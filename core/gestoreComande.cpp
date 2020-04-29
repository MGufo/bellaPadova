#include "gestoreComande.h"

void GestoreComande::inserisciComanda(const Comanda* daInserire) {}

void GestoreComande::rimuoviComanda(Comanda* daRimuovere) {
  Lista<Comanda*>::Iterator it;
  for (it = bacheca.begin(); it != bacheca.end() && (*it) != daRimuovere;
       ++it) {
  }
  if (it != bacheca.end()) bacheca.erase(it);
}

const Comanda* GestoreComande::getComandaCorrente() const { return *current; }

Lista<Comanda*> GestoreComande::getBacheca() { return bacheca; }
