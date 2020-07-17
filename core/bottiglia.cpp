#include "bottiglia.h"

Bottiglia::Bottiglia(unsigned int id, string nome, bool disponibilita, double prezzo,
                     unsigned int qta, double costo, QDate dataAcquisto,
                     float capacitaBevanda)
    : Risorsa(id, nome, disponibilita),
      Bevanda(id, nome, disponibilita, prezzo, qta, costo, dataAcquisto,
              capacitaBevanda) {}

Bottiglia* Bottiglia::clone() const { return new Bottiglia(*this); }

double Bottiglia::getPrezzo() const {
  return getPrezzoBase() + getPlasticTax() * (1 / getCapacita());
}
