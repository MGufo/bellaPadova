#include "farina.h"

Farina::Farina(double _costo, QDate _dataScadenza, string _nome,
               bool _disponibilita, unsigned int _quantita, QDate _dataAcquisto,
               bool _locale, string _tipoFarina)
    : Risorsa(_nome, _disponibilita),
      Ingrediente(_nome, _disponibilita, _quantita, _costo, _dataScadenza,
                  _dataAcquisto, _locale),
      tipoFarina(_tipoFarina) {}

const string& Farina::getTipoFarina() const { return tipoFarina; }

void Farina::setTipoFarina(const string& f) { tipoFarina = f; }