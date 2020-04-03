#include "articolo.h"

Articolo::Articolo(string nome, bool disponibilita, double p)
    : Risorsa(nome, disponibilita), prezzo(p) {}

double Articolo::getPrezzo() const { return prezzo; }

void Articolo::setPrezzo(const double& p) { prezzo = p; }
