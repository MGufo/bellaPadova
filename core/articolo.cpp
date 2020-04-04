#include "articolo.h"

Articolo::Articolo(string nome, bool disponibilita, double p)
    : Risorsa(nome, disponibilita), prezzoBase(p) {}

void Articolo::setPrezzo(const double& p) { prezzoBase = p; }
