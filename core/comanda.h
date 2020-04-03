#include "articolo.h"
#include "cliente.h"
#include "container.h"

class Comanda {
 private:
  Lista<Articolo*> articoli;
  Lista<unsigned int> quantita;
  Contatto cliente;
};