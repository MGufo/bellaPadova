#include "consumabile.h"

Consumabile::Consumabile() {}

Consumabile::Consumabile(unsigned int id, string n, bool d, unsigned int q, double c, QDate da)
    : Risorsa(id, n, d), quantita(q), costo(c), dataAcquisto(da) {}

unsigned int Consumabile::getQuantita() const { return quantita; }
double Consumabile::getCosto() const { return costo; }
const QDate& Consumabile::getDataAcquisto() const { return dataAcquisto; }

void Consumabile::setQuantita(const unsigned int q) { quantita = q; }
void Consumabile::setCosto(const double c) {
  if(c <= 0) throw new std::domain_error("Errore: Il costo non può essere"
                                         " inferiore a 0.");
  else
    costo = c;
}
void Consumabile::setDataAcquisto(const QDate& da) { dataAcquisto = da; }
