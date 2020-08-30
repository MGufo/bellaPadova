#include "articolo.h"

Articolo::Articolo() {}

Articolo::Articolo(unsigned int id, string nome, bool disponibilita, double p)
    : Risorsa(id, nome, disponibilita), prezzoBase(p) {}

double Articolo::getPrezzoBase() const { return prezzoBase; }

void Articolo::setPrezzoBase(const double& p) {
  if(p <= 0) throw new std::domain_error("Errore: Il prezzo non può essere"
                                         " inferiore a 0.");
  else
    prezzoBase = p;
}
