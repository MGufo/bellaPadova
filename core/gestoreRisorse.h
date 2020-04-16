#include "articolo.h"
#include "consumabile.h"

class GestoreRisorse {
 private:
  Lista<Articolo*>* menu;
  Lista<Consumabile*>* inventario;

 public:
  GestoreRisorse();

  // Idea da implementare: la classe gestore deve gestire le liste di Articoli
  // (menu) e consumabili (inventario), permettendo inserimento, modifica,
  // rimozione e ricerca all'interno delle liste
};