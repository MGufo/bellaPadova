#include "bevanda.h"

Bevanda::Bevanda(string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 QDate dataScadenza, formatoBevanda fb, capacitaBevanda cb)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      Consumabile(nome, disponibilita, qta, costo, dataAcquisto, dataScadenza),
      formato(fb),
      capacita(cb) {}

double Bevanda::getSpesa() const {
  return getQuantita() * getCosto();
}
double Bevanda::getPrezzo() const { return getCosto() * getQuantita(); }
