#include "bottiglia.h"

Bottiglia::Bottiglia(string nome, bool disponibilita, double prezzo,
                     unsigned int qta, double costo, QDate dataScadenza,
                     QDate dataAcquisto, double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Bevanda(nome, disponibilita, prezzo, qta, costo, dataScadenza,
              dataAcquisto, capacitaBevanda) {}

Bottiglia* Bottiglia::clone() const { return new Bottiglia(*this); }

double Bottiglia::getPrezzo() const {
  return getPrezzoBase() + getPlasticTax() * (1 / getCapacitaBevanda());
}