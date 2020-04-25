#include "comanda.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(unordered_map<Articolo*, unsigned int> _articoli,
                 Contatto* _cliente, QTime _oraConsegna)
    : articoli(_articoli), cliente(_cliente), oraConsegna(_oraConsegna){};

Comanda::Comanda(const Comanda& c)
    : articoli(c.articoli),
      cliente(new Contatto(*c.cliente)),
      oraConsegna(c.oraConsegna){};

Comanda::~Comanda() {
  if (cliente) delete cliente;
}

void Comanda::sostituisciArticolo(Articolo* daSostituire, unsigned int qtaDS,
                                  Articolo* daInserire, unsigned int qtaDI) {
  if (daSostituire) {
    if (articoli[daSostituire] <= qtaDS)
      articoli.erase(daSostituire);
    else
      articoli[daSostituire] -= qtaDS;
  }
  if (daInserire) articoli[daInserire] = qtaDI;
}
// sottocaso 1: aggiungere un nuovo articolo non presente in comanda
void Comanda::inserisciArticolo(Articolo* _daInserire, unsigned int _qtaDI) {
  sostituisciArticolo(nullptr, 0, _daInserire, _qtaDI);
}

// sottocaso 4: rimuovere un articolo presente in comanda
void Comanda::rimuoviArticolo(Articolo* _daSostituire) {
  if (&articoli[_daSostituire]) {
    unsigned int _qtaDS = articoli[_daSostituire];
    sostituisciArticolo(_daSostituire, _qtaDS, nullptr, 0);
  }
}
