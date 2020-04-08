#include "ingrediente.h"

Ingrediente::Ingrediente(string _nome, bool _disponibilita, unsigned int _quantita, double _costo, 
                        QDate _dataScadenza, QDate _dataAcquisto, bool _locale) 
                        : Consumabile(_nome, _disponibilita, _quantita, _costo, 
                         _dataAcquisto, _dataScadenza), locale(_locale)  {}

bool Ingrediente::Scaduto() const{
    QDate 
    return ;
}
