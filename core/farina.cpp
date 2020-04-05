#include "farina.h"

Farina::Farina(string _nome, bool _disponibilita, unsigned int _quantita, double _costo, 
QDate _data, bool _locale, string _tipoFarina) : Ingrediente(_nome, _disponibilita, _quantita, 
_costo, _data, _locale), tipoFarina(_tipoFarina) {}

const string& Farina::getTipoFarina() const {
    return tipoFarina;
}

void Farina::setTipoFarina(const string& f) {
    tipoFarina = f; 
}