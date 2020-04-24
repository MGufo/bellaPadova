#include "lattina.h"

Lattina::Lattina(string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataScadenza,
                 QDate dataAcquisto, double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Bevanda(nome, disponibilita, prezzo, qta, costo, dataScadenza,
              dataAcquisto, capacitaBevanda) {}

Lattina* Lattina::clone() const { return new Lattina(*this); }

double Lattina::getPrezzo() const { return getPrezzoBase(); }