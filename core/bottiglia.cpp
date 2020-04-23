#include "bottiglia.h"

Bottiglia::Bottiglia(string nome, bool disponibilita, double prezzo,
                     unsigned int qta, double costo, QDate dataAcquisto,
                     QDate dataScadenza, double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Bevanda(nome, disponibilita, prezzo, qta, costo, dataAcquisto,
              dataScadenza, capacitaBevanda) {}

Bottiglia* Bottiglia::clone() const { return new Bottiglia(*this); }

double Bottiglia::getPrezzo() const {
  return getPrezzoBase() + getPlasticTax() * (1 / getCapacitaBevanda());
}