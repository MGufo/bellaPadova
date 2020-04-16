#include "pizzeria.h"

Pizzeria::Pizzeria(string nome, string indirizzo, string telefono)
    : contatto(new Contatto(nome, indirizzo, telefono)),
      gestoreRisorse(new GestoreRisorse()) {}

const Lista<const string&> Pizzeria::getContatto() const {
  return contatto->getContatto();
}
