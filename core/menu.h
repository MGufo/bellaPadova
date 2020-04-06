#include "articolo.h"

class Menu {
 private:
  Lista<Articolo*>* listino;
 public:
  Menu();
  inserisciArticolo(Articolo*);
  modificaArticolo();
  eliminaArticolo();
};
