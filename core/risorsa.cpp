#include "risorsa.h"
#include <string>

Risorsa::Risorsa(string n, bool b) {
  if (n.empty()) {
    // TODO: Implementare gestione eccezioni
    // throw();
  } else {
    nome = n;
    disponibilita = b;
  }
}