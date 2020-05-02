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
                                const Comanda* daInserire) {
  // non ci sono comande da fare oppure si è arrivati all'ultima comanda
  if (!successiva) return true;
  // se la comanda da inserire "fitta" tra la precedente e la successiva
  if (successiva != *current) {
    if (precedente->getOraConsegna() <=
            daInserire->getOrarioInizioPreparazione() &&
        daInserire->getOraConsegna() <=
            successiva->getOrarioInizioPreparazione())
      return true;
    else
      return false;
  }
  // precedente = ? && successiva = current
  else {
    // se precedente esiste è stata già consegnata e il suo orario di consegna
    // era al più == currentTime
    if (QTime::currentTime() <= daInserire->getOrarioInizioPreparazione() &&
        daInserire->getOraConsegna() <=
            successiva->getOrarioInizioPreparazione())
      return true;
    return false;
  }
}

bool GestoreComande::testCurrent(const Lista<Comanda*>::Iterator it) const {
  return current == it;
}

void GestoreComande::inserisciComanda(Comanda* daInserire) {
  if (daInserire) {
    if (bacheca.isEmpty()) {
      bacheca.push_back(daInserire);
      current = bacheca.begin();
    } else {
      // esiste almeno 1 comanda
      if (*current) {
        auto it = current;
        auto it2 = current;
        // se non entriamo si può inserire la comanda prima di current
        if (!testInsert(*(--it2), *current, daInserire)) {
          it = current;
          while (!testInsert(*it, *(++it), daInserire)) {
          }
        }

        // caso 1: si può inserire la comanda prima di current
        // caso 1.1: prima di current esiste una comanda
        // caso 1.2: prima di current non c'è niente (current è la prima comanda
        // da svolgere della serata) si gestiscono allo stesso modo
        bacheca.insert(current, daInserire);
        --current;

        // TODO: Controllare se serve questo if
        if (*it2 && daInserire->getOraConsegna() < (*it2)->getOraConsegna())
          daInserire->setOraConsegna((*it2)->getOraConsegna().addSecs(
              daInserire->getTempoPreparazione() * 60));

        // caso 2: la comanda va inserita dopo current
        // caso 2.1: inseriamo la comanda tra due comande valide
        // caso 2.2: inseriamo la comanda in coda (prima di end())
        // si gestiscono allo stesso modo
        if (daInserire->getOraConsegna() < (*(--it))->getOraConsegna())
          daInserire->setOraConsegna((*it)->getOraConsegna().addSecs(
              daInserire->getTempoPreparazione() * 60));

        //--it2;
        if (testCurrent(it2) &&
            daInserire->getOraConsegna() < (*it2)->getOraConsegna())
          daInserire->setOraConsegna((*it2)->getOraConsegna().addSecs(
              daInserire->getTempoPreparazione() * 60));
        bacheca.insert(it, daInserire);
        if (it == current) --current;
      } else {
        bacheca.push_back(daInserire);
        current = --(bacheca.end());
      }
    }
  }
}

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

Lista<Comanda*> GestoreComande::getBacheca() { return bacheca; }

void GestoreComande::eseguiComanda() { ++current; }
