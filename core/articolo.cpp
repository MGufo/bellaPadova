#include "articolo.h"
#include "risorsa.h"

Articolo::Articolo(string nome, bool disponibilita, double p) {
  Risorsa(nome, disponibilita);
  prezzo = p;
}

;