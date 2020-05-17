#include "pizzeria.h"

unsigned short Pizzeria::capacitaForno = 5;

Pizzeria::Pizzeria()
    : contatto(Contatto()),
      gestoreRisorse(GestoreRisorse()),
      gestoreComande(GestoreComande()) {}

void Pizzeria::inserisciArticolo(Articolo* daInserire) {
  gestoreRisorse.inserisciArticolo(daInserire);
}

void Pizzeria::modificaArticolo(Articolo* daModificare,
                                const Articolo* modificato) {
  gestoreRisorse.modificaArticolo(daModificare, modificato);
  delete modificato;
}

void Pizzeria::rimuoviArticolo(Articolo* daRimuovere) {
  gestoreRisorse.rimuoviArticolo(daRimuovere);
  delete daRimuovere;
}

void Pizzeria::inserisciConsumabile(Consumabile* daInserire) {
  gestoreRisorse.inserisciConsumabile(daInserire);
}

void Pizzeria::modificaConsumabile(Consumabile* daModificare,
                                   const Consumabile* modificato) {
  gestoreRisorse.modificaConsumabile(daModificare, modificato);
  delete modificato;
}

void Pizzeria::rimuoviConsumabile(Consumabile* daRimuovere) {
  gestoreRisorse.rimuoviConsumabile(daRimuovere);
  delete daRimuovere;
}

void Pizzeria::inserisciComanda(Comanda* daInserire) {
  gestoreComande.inserisciComanda(daInserire);
}

void Pizzeria::modificaComanda(Comanda* daModificare,
                               const Comanda* modificata) {
  gestoreComande.modificaComanda(daModificare, modificata);
  delete modificata;
}

void Pizzeria::eseguiComanda() { gestoreComande.eseguiComanda(); }

void Pizzeria::rimuoviComanda(Comanda* daRimuovere) {
  gestoreComande.rimuoviComanda(daRimuovere);
  delete daRimuovere;
}

const Lista<string>& Pizzeria::getContatto() const {
  return contatto.getContatto();
}

void Pizzeria::setContatto(const Contatto* modificato) {
  contatto = *modificato;
}

unsigned short Pizzeria::getCapacitaForno() { return capacitaForno; }

void Pizzeria::setCapacitaForno(unsigned short _forno) {
  capacitaForno = _forno;
}
