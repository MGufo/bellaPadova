#include "gestoreComande.h"

GestoreComande::GestoreComande()
    : bacheca(Lista<Comanda*>()), current(bacheca.begin()) {}

/*
Algoritmo posizione di inserimento:
    - ogni pizza ha un tempo di preparazione di 5min
    - il tempo di preparazione di una comanda è: (n° pizze comanda) x costante
    di preparazione
    - Se il tempo di preparazione dell'ordine da inserire calza
    tra l'orario di consegna dell'ordine precedente e (tempo consegna ordine
    succ - tempo preparazione ordine succ) allora la comanda da inserire verrà
    inserita tra le due comande, altrimenti passa alla successiva coppia di
    comande già presenti e ripete il controllo.
*/
bool GestoreComande::testInsert(const Comanda* precedente,
                                const Comanda* successiva,
                                const Comanda* daInserire,
                                unsigned short capForno,
                                const QTime& currentTime) {
  QTime* orarioInizioPreparazioneDaIns =
      daInserire->getOrarioInizioPreparazione(capForno);
  QTime* orarioInizioPreparazioneSucc;
  if (successiva)
    orarioInizioPreparazioneSucc =
        successiva->getOrarioInizioPreparazione(capForno);
  // non ci sono comande da fare oppure si è arrivati all'ultima comanda
  if (!successiva) return true;
  // se la comanda da inserire "fitta" tra la precedente e la successiva
  if (successiva != *current) {
    if (precedente->getOraConsegna() <= *orarioInizioPreparazioneDaIns &&
        daInserire->getOraConsegna() <= *orarioInizioPreparazioneSucc)
      return true;
    else
      return false;
  }
  // precedente = ? && successiva = current
  else {
    // se precedente esiste è stata già consegnata e il suo orario di consegna
    // era al più == currentTime
    if (currentTime <= *orarioInizioPreparazioneDaIns &&
        daInserire->getOraConsegna() <= *orarioInizioPreparazioneSucc)
      return true;
    return false;
  }
  delete orarioInizioPreparazioneDaIns;
  delete orarioInizioPreparazioneSucc;
}

unsigned int GestoreComande::getMaxId() const {
  unsigned int maxID = 0;
  for (auto it = bacheca.const_begin(); it != bacheca.const_end(); ++it)
    if ((*it)->getIdComanda() > maxID) maxID = (*it)->getIdComanda();
  return maxID;
}

void GestoreComande::fixCurrent() { current = bacheca.find(*current); }

void GestoreComande::inserisciComanda(Comanda* daInserire,
                                      unsigned short capForno) {
  if (daInserire) {
    QTime currentTime = QTime::currentTime();
    QTime* orarioInizioPreparazioneDaIns =
        daInserire->getOrarioInizioPreparazione(capForno);
    int tempoPreparazione = daInserire->getTempoPreparazione(capForno) * 60;

    if (currentTime >= *orarioInizioPreparazioneDaIns) {
      if (!(current.isValid()))
        daInserire->setOraConsegna(
            QTime(currentTime).addSecs(tempoPreparazione));
      else {
        QTime* orarioInizioPreparazioneCurrent =
            (*current)->getOrarioInizioPreparazione(capForno);
        if (QTime(currentTime).addSecs(tempoPreparazione) <
            *orarioInizioPreparazioneCurrent)
          daInserire->setOraConsegna(
              QTime(currentTime).addSecs(tempoPreparazione));
        else
          daInserire->setOraConsegna(
              (*current)->getOraConsegna().addSecs(tempoPreparazione));
        delete orarioInizioPreparazioneCurrent;
      }
    }
    if (bacheca.isEmpty()) {
      bacheca.push_back(daInserire);
      current = bacheca.begin();
    } else {
      if (current.isValid()) {
        auto it = current;
        auto it2 = it;
        bool beforeCurrent =
            testInsert(nullptr, *current, daInserire, capForno, currentTime);
        if (!beforeCurrent) {
          bool flag = false;
          while (!flag) {
            ++it2;
            if (it2 != bacheca.end())
              flag = testInsert(*it, *(it2), daInserire, capForno, currentTime);
            else
              flag =
                  testInsert(*it, nullptr, daInserire, capForno, currentTime);
            ++it;
          }
        }
        if (beforeCurrent) {
          bacheca.insert(current, daInserire);
          fixCurrent();
          --current;
        } else {
          --it;
          if (*orarioInizioPreparazioneDaIns < (*(it))->getOraConsegna())
            daInserire->setOraConsegna(
                (*it)->getOraConsegna().addSecs(tempoPreparazione));
          if (it2 != bacheca.end())
            bacheca.insert(it2, daInserire);
          else
            bacheca.push_back(daInserire);
        }
      } else {
        if (currentTime > *orarioInizioPreparazioneDaIns)
          daInserire->setOraConsegna(
              QTime(currentTime).addSecs(tempoPreparazione));
        bacheca.push_back(daInserire);
        current = --(bacheca.end());
      }
    }
    delete orarioInizioPreparazioneDaIns;
  }
}

void GestoreComande::modificaComanda(Comanda* daModificare,
                                     const Comanda* modificata,
                                     unsigned short capForno) {
  bool daReinserire =
      (daModificare->getOraConsegna() != modificata->getOraConsegna()) ||
      (daModificare->getTempoPreparazione(capForno) !=
       modificata->getTempoPreparazione(capForno));
  *daModificare = *modificata;
  if (daReinserire) {
    rimuoviComanda(daModificare);
    inserisciComanda(daModificare, capForno);
  }
}

void GestoreComande::eseguiComanda() { ++current; }

void GestoreComande::rimuoviComanda(Comanda* daRimuovere) {
  if (daRimuovere) {
    Lista<Comanda*>::Iterator it;
    for (it = bacheca.begin(); it != bacheca.end() && (*it) != daRimuovere;
         ++it) {
    }
    if (it != bacheca.end()) {
      if (*it >= *current) {
        if (it == current) ++current;
        bacheca.erase(it);
        fixCurrent();
      }
    }
  }
}

const Comanda* GestoreComande::getComandaCorrente() const {
  if (current.isValid())
    return *current;
  else
    return nullptr;
}

const Lista<Comanda*>& GestoreComande::getBacheca() const { return bacheca; }

Comanda* GestoreComande::trovaComanda(unsigned int _ID) const {
  Comanda* c = nullptr;
  if (!bacheca.isEmpty()) {
    for (auto it = bacheca.const_begin(); it != bacheca.const_end(); ++it)
      if ((*it)->getIdComanda() == _ID) c = *it;
  }
  return c;
}

void GestoreComande::salvaComande(QJsonObject* fileComandeJSON) const {
  QJsonObject* comandeJSON = new QJsonObject();
  for (auto it = bacheca.begin(); it != current; ++it) {
    QJsonObject* comandaJSON = new QJsonObject();
    (*it)->salva(comandaJSON);
    comandeJSON->insert(
        QString::fromStdString(std::to_string((*it)->getIdComanda())),
        *comandaJSON);
    delete comandaJSON;
  }
  fileComandeJSON->insert("Comande", *comandeJSON);
  delete comandeJSON;
}

void GestoreComande::salvaIdComande(QJsonObject* fileComandeJSON) const {
  fileComandeJSON->insert("ID", static_cast<double>(getMaxId()));
}
