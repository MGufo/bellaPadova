#include "articolo.h"
#include "gestore.h"

class Menu {
 private:
  Lista<Articolo*>* listino;
  Gestore* gestore;

 public:
  Menu();
  inserisciArticolo(Articolo*);
  modificaArticolo();
  eliminaArticolo();
};
