#include "pizzeria.h"

unsigned short Pizzeria::capacitaForno = 5;

Pizzeria::Pizzeria()
    : contatto(Contatto()),
      gestoreRisorse(GestoreRisorse()),
      gestoreComande(GestoreComande()) {}

const Lista<const string> Pizzeria::getContatto() const {
  return contatto.getContatto();
}

unsigned short Pizzeria::getCapacitaForno() {
  return capacitaForno;
}


void Pizzeria::setCapacitaForno(unsigned short _forno) {
  capacitaForno = _forno;
}
