#include "articolo.h"

Articolo::Articolo(string nome, bool disponibilita, double p)
    : Risorsa(nome, disponibilita), prezzoBase(p) {}

double Articolo::getPrezzoBase() const { return prezzoBase; }

void Articolo::setPrezzoBase(const double& p) { prezzoBase = p; }
