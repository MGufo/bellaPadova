#include "consumabile.h"

Consumabile::Consumabile(string n, bool d, unsigned int q, double c, QDate ds, QDate da)
    : Risorsa(n,d), quantita(q), costo(c), dataAcquisto(da), dataScadenza(ds) {}

Consumabile::Consumabile(const Consumabile & c)
    : Risorsa(c), quantita(c.quantita), costo(c.costo), dataAcquisto(c.dataAcquisto), dataScadenza(c.dataScadenza) {}

unsigned int Consumabile::getQuantita() const { return quantita; }

double Consumabile::getCosto() const { return costo; }

const QDate& Consumabile::getDataAcquisto() const { return dataAcquisto; }

const QDate& Consumabile::getDataScadenza() const { return dataScadenza; }

void Consumabile::setQuantita(const unsigned int q) { quantita = q; }
void Consumabile::setCosto(const double c) { costo = c; }
void Consumabile::setDataAcquisto(const QDate& da) { dataAcquisto = da; }
void Consumabile::setDataScadenza(const QDate& ds) { dataScadenza = ds; }
