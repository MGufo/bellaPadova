#include "gestoreComande.h"

GestoreComande::GestoreComande(Lista<Comanda*> _bacheca,
                               Lista<Comanda*>::Iterator _current)
    : bacheca(_bacheca), current(_bacheca.begin()) {}

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
bool GestoreComande::testInsert(const Comanda* precedente,  //--curr
                                const Comanda* successiva,  // curr
                                const Comanda* daInserire) {
  if (!precedente && successiva) {
    if (QTime::currentTime() <= daInserire->getOrarioInizioPreparazione() &&
        daInserire->getOraConsegna <= successiva->getOrarioInizioPreparazione())
      return true;
    return false;
  }
  // non ci sono comande da fare oppure si è arrivati all'ultima comanda
  if (!precedente || !successiva) return true;
  // se la comanda da inserire "fitta" tra la precedente e la successiva
  if (precedente->getOraConsegna() <=
          daInserire->getOrarioInizioPreparazione() &&
      daInserire->getOraConsegna <= successiva->getOrarioInizioPreparazione())
    return true;
  else
    return false;
}

void GestoreComande::inserisciComanda(Comanda* daInserire) {
  if (daInserire) {
    if (bacheca.isEmpty()) {
      bacheca.push_back(daInserire);
      current = bacheca.begin();
    } else if (true) {
    } else {
      // esiste almeno 1 comanda
      if (*current) {
        auto it = current;
        --it;
        while (!testInsert(*it, *(++it), daInserire)) {
        }
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