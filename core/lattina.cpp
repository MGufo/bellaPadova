#include "lattina.h"

Lattina::Lattina(string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 QDate dataScadenza, double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Bevanda(nome, disponibilita, prezzo, qta, costo, dataAcquisto,
              dataScadenza, capacitaBevanda) {}

Lattina* Lattina::clone() const { return new Lattina(*this); }

double Lattina::getPrezzo() const { return getPrezzoBase(); }