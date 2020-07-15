#include "articolo.h"

Articolo::Articolo(unsigned int id, string nome, bool disponibilita, double p)
    : Risorsa(id, nome, disponibilita), prezzoBase(p) {}

double Articolo::getPrezzoBase() const { return prezzoBase; }

void Articolo::setPrezzoBase(const double& p) { prezzoBase = p; }
