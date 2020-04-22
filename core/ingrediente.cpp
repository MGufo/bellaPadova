#include "ingrediente.h"

Ingrediente::Ingrediente(string _nome, bool _disponibilita,
                         unsigned int _quantita, double _costo,
                         QDate _dataScadenza, QDate _dataAcquisto, bool _locale)
    : Risorsa(_nome, _disponibilita),
      Consumabile(_nome, _disponibilita, _quantita, _costo, _dataAcquisto, _dataScadenza),
      locale(_locale) {}

Ingrediente* Ingrediente::clone() const{
    return new Ingrediente(*this);
}

bool Ingrediente::isLocal() const {
  return locale;
}

double Ingrediente::getSpesa() const {
  return getQuantita() * getCosto() + 1*isLocal();
}
