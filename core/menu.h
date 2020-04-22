#ifndef MENU_H
#define MENU_H

#include "articolo.h"
#include "gestoreRisorse.h"
#include "qontainer.h"

class Menu {
 private:
  Lista<Articolo*>* listino;
  GestoreRisorse* gestore;

 public:
  Menu();
  void inserisciArticolo(Articolo*);
  void modificaArticolo(Articolo*);
  void eliminaArticolo(Articolo*);
};

#endif