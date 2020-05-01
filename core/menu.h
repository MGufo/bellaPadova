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

  /**
   * @brief: Inserisce un articolo nel menù. Se già presente non fa nulla.
   * Se almeno un ingrediente dell'articolo non è disponibile l'articolo sarà
   * inserito con disponibilità = false.
   * @param: Articolo* (Articolo da inserire)
   */
  void inserisciArticolo(Articolo*);

  void modificaArticolo(Articolo*);
  void eliminaArticolo(Articolo*);
};

#endif