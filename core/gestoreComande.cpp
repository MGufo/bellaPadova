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
                                unsigned short capForno) {
  // non ci sono comande da fare oppure si è arrivati all'ultima comanda
  if (!successiva) return true;
  // se la comanda da inserire "fitta" tra la precedente e la successiva
  if (successiva != *current) {
    if (precedente->getOraConsegna() <=
            daInserire->getOrarioInizioPreparazione(capForno) &&
        daInserire->getOraConsegna() <=
            successiva->getOrarioInizioPreparazione(capForno))
      return true;
    else
      return false;
  }
  // precedente = ? && successiva = current
  else {
    // se precedente esiste è stata già consegnata e il suo orario di consegna
    // era al più == currentTime
    if (QTime::currentTime() <= daInserire->getOrarioInizioPreparazione(capForno) &&
        daInserire->getOraConsegna() <=
            successiva->getOrarioInizioPreparazione(capForno))
      return true;
    return false;
  }
}


// HACK: La comanda può contenere sia pizze di copia dal menù che pizze
// "temporanee", cioè create appositamente per la comanda
void GestoreComande::inserisciComanda(Comanda* daInserire, unsigned short capForno) {
  int tempoPreparazione = daInserire->getTempoPreparazione(capForno)*60;
  if (daInserire) {
    if (QTime::currentTime() > daInserire->getOrarioInizioPreparazione(capForno)) {
      if (!(current.isValid()))
        daInserire->setOraConsegna(QTime::currentTime().addSecs(tempoPreparazione));
      else {
        // current esiste
        // sottocaso prima di current
        if (QTime::currentTime().addSecs(tempoPreparazione) <
            (*current)->getOrarioInizioPreparazione(capForno))
          daInserire->setOraConsegna(QTime::currentTime().addSecs(tempoPreparazione));
        else
          // sottocaso dopo current
          daInserire->setOraConsegna((*current)->getOraConsegna().addSecs(
            tempoPreparazione));
      }
    }
    if (bacheca.isEmpty()) {
      bacheca.push_back(daInserire);
      current = bacheca.begin();
    } else {
      // esiste almeno 1 comanda da fare
      if (current.isValid()) {
        auto it = current;
        auto it2 = it;
        bool beforeCurrent = testInsert(nullptr, *current, daInserire, capForno);
        // se non entriamo si può inserire la comanda prima di current
        if (!beforeCurrent) {
          bool flag = false;
          while (!flag) {
            ++it2;
            if (it2 != bacheca.end())
              flag = testInsert(*it, *(it2), daInserire, capForno);
            else
              flag = testInsert(*it, nullptr, daInserire, capForno);
            ++it;
          }
        }
        if (beforeCurrent) {
          // caso 1: si può inserire la comanda prima di current
          // caso 1.1: prima di current esiste una comanda
          // caso 1.2: prima di current non c'è niente (current è la prima
          // comanda da svolgere della serata) si gestiscono allo stesso modo
          bacheca.insert(current, daInserire);
          --current;
        } else {
          // caso 2: la comanda va inserita dopo current
          // caso 2.1: inseriamo la comanda tra due comande valide
          // caso 2.2: inseriamo la comanda in coda (prima di end())
          // si gestiscono allo stesso modo
          --it;
          if (daInserire->getOrarioInizioPreparazione(capForno) <
              (*(it))->getOraConsegna())
            daInserire->setOraConsegna((*it)->getOraConsegna().addSecs(
tempoPreparazione));
          // qui it punta alla comanda già presente (andyM), ma insert inserisce
          // daInserire prima di andyM! in teoria non possiamo fare insert(++it,
          // daInserire) perché causerebbe SEGFAULT possibile soluzione: usare
          // push back (serve condizione per distinguere inserimento in coda da
          // inserimento in mezzo
          if (it2 != bacheca.end())
            bacheca.insert(it2, daInserire);
          else
            bacheca.push_back(daInserire);
        }
      }
      // la bacheca contiene solo comande terminate, current == end()
      else {
        if (QTime::currentTime() > daInserire->getOrarioInizioPreparazione(capForno))
          daInserire->setOraConsegna(QTime::currentTime().addSecs(tempoPreparazione));
        bacheca.push_back(daInserire);
        current = --(bacheca.end());
      }
    }
  }
}

void GestoreComande::modificaComanda(Comanda* daModificare,
                                     const Comanda* modificata, unsigned short capForno) {
  bool daReinserire =
      daModificare->getOraConsegna() != modificata->getOraConsegna();
  *daModificare = *modificata;
  if (daReinserire) inserisciComanda(daModificare, capForno);
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
      }
    }
  }
}

const Comanda* GestoreComande::getComandaCorrente() const { return *current; }

const Lista<Comanda*>& GestoreComande::getBacheca() const { return bacheca; }

void GestoreComande::salvaComande(QJsonObject *comandeJSON) const{
  for(auto it = bacheca.const_begin(); it != bacheca.const_end(); ++it){
    QJsonObject* comandaJSON = new QJsonObject();
    (*it)->salva(comandaJSON);
    comandeJSON->insert(
          QString::fromStdString(std::to_string((*it)->getIdComanda())),
          *comandaJSON);
    delete comandaJSON;
  }
}
/*
Problema: per creare correttamente ogni comanda servono i puntatori agli Articoli
che compongono la comanda.
Questi puntatori sono ottenibili solo tramite l'inventario (quindi gestoreRisorse)
MA per ottenerli servono informazioni presenti in comandeJSON (che viene passato
a gestioneComande).
*/
void GestoreComande::caricaComande(const QJsonObject& comandeJSON){
  for(auto it = comandeJSON.constBegin(); it != comandeJSON.constEnd(); ++it){
    QJsonObject* comandaJSON = new QJsonObject(it->toObject());
    Comanda* c = new Comanda();
    c->carica(comandaJSON);
  }
}
