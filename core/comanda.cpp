#include "comanda.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(unordered_map<Articolo*, unsigned int>* _articoli,
                 Contatto* _cliente, QTime _oraConsegna)
    : articoli(_articoli), cliente(_cliente), oraConsegna(_oraConsegna){};

Comanda::Comanda(const Comanda& c)
    : articoli(new unordered_map<Articolo*, unsigned int>(*c.articoli)),
      cliente(new Contatto(*c.cliente)),
      oraConsegna(c.oraConsegna){};

Comanda::~Comanda() {
  if (articoli) delete articoli;
  if (cliente) delete cliente;
}
