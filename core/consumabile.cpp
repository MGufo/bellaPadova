#include "consumabile.h"

Consumabile::Consumabile(string nome, bool disponibilita, unsigned int q,
                         double c, QDate da, QDate ds)
    : Risorsa(nome, disponibilita),
      quantita(q),
      costo(c),
      dataAcquisto(da),
      dataScadenza(ds) {}

unsigned int Consumabile::getQuantita() const { return quantita; }

double Consumabile::getCosto() const { return costo; }

const QDate& Consumabile::getDataAcquisto() const { return dataAcquisto; }

const QDate& Consumabile::getDataScadenza() const { return dataScadenza; }

void Consumabile::setQuantita(const unsigned int q) { quantita = q; }
void Consumabile::setCosto(const double c) { costo = c; }
void Consumabile::setDataAcquisto(const QDate& da) { dataAcquisto = da; }
void Consumabile::setDataScadenza(const QDate& ds) { dataScadenza = ds; }

//double Consumabile::getSpesa() const { return quantita * costo; }
