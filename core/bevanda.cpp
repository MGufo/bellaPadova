#include "bevanda.h"

Bevanda::Bevanda(string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 double capacitaBevanda)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      Consumabile(nome, disponibilita, qta, costo, dataAcquisto),
      capacita(capacitaBevanda) {}

double Bevanda::getSpesa() const { return getQuantita() * getCosto(); }

double Bevanda::getCapacitaBevanda() const { return capacita; }

double Bevanda::getPlasticTax() const { return plasticTax; }

void Bevanda::setPlasticTax(double pt) { plasticTax = pt; }

void Bevanda::setCapacita(float _capacita) { capacita = _capacita; }

double Bevanda::plasticTax = 0.5;

const Lista<const Consumabile*>* Bevanda::getComposizione() const {
  Lista<const Consumabile*>* lista = new Lista<const Consumabile*>();
  lista->push_back(this);
  return lista;
}
