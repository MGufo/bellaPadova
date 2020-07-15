#include "farina.h"

Farina::Farina(unsigned int id, string _nome, bool _disponibilita, unsigned int _quantita,
               double _costo, QDate _dataAcquisto, bool _locale,
               string _tipoFarina)
    : Risorsa(id, _nome, _disponibilita),
      Ingrediente(id, _nome, _disponibilita, _quantita, _costo, _dataAcquisto,
                  _locale),
      tipoFarina(_tipoFarina) {}

const string& Farina::getTipoFarina() const { return tipoFarina; }

void Farina::setTipoFarina(const string& f) { tipoFarina = f; }

Farina* Farina::clone() const { return new Farina(*this); }

void Farina::carica(const QJsonObject &){

}

void Farina::salva(QJsonObject &) const{

}
