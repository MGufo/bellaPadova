#include "ingrediente.h"

Ingrediente::Ingrediente(string _nome, bool _disponibilita,
                         unsigned int _quantita, double _costo,
                         QDate _dataScadenza, QDate _dataAcquisto, bool _locale)
    : Risorsa(_nome, _disponibilita),
      Consumabile(_quantita, _costo, _dataAcquisto, _dataScadenza),
      locale(_locale) {}
