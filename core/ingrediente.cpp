#include "ingrediente.h"

Ingrediente::Ingrediente(unsigned int id, string _nome, bool _disponibilita,
                         unsigned int _quantita, double _costo,
                         QDate _dataAcquisto, bool _locale)
    : Risorsa(id, _nome, _disponibilita),
      Consumabile(id, _nome, _disponibilita, _quantita, _costo, _dataAcquisto),
      locale(_locale) {}

Ingrediente* Ingrediente::clone() const { return new Ingrediente(*this); }

bool Ingrediente::isLocal() const { return locale; }

void Ingrediente::setLocal(bool _locale) { locale = _locale; }

double Ingrediente::getSpesa() const {
  return getQuantita() * getCosto() + 1 * isLocal();
}
