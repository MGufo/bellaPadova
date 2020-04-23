#include "bevanda.h"

Bevanda::Bevanda(string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 QDate dataScadenza, double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      Consumabile(nome, disponibilita, qta, costo, dataAcquisto, dataScadenza),
      capacita(capacitaBevanda) {}

double Bevanda::getSpesa() const { return getQuantita() * getCosto(); }

double Bevanda::getCapacitaBevanda() const { return capacita; }

double Bevanda::getPlasticTax() const { return plasticTax; }

void Bevanda::setPlasticTax(double pt) { plasticTax = pt; }

double Bevanda::plasticTax = 0.5;
