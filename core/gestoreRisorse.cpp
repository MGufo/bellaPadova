#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

template <class T>
T getPosizione(Lista<T*> lista, T* valore) {
  Lista<T*>::Iterator it;
  bool trovato = false;
  for (it = lista.begin(); it != lista.end() && !trovato; ++it)
    if (*it == valore) trovato = true;
  return it;
}
template <class T>
T getPosizione(const Lista<T*> lista, T* valore) {
  Lista<T*>::Iterator it;
  bool trovato = false;
  for (it = lista.begin(); it != lista.end() && !trovato; ++it)
    if (*it == valore) trovato = true;
  return it;
}

bool GestoreRisorse::controlloDisponibilita(const Articolo* _articolo) const {
  Lista<Articolo*>::const_Iterator it;
  bool trovato = false;
  for (it = menu.const_begin(); it != menu.const_end() && !trovato; ++it)
    if (*it == _articolo) trovato = true;
  return trovato;
}

bool GestoreRisorse::controlloDisponibilita(
    const Consumabile* _consumabile) const {
  Lista<Consumabile*>::const_Iterator it;
  bool trovato = false;
  for (it = inventario.const_begin(); it != inventario.const_end() && !trovato;
       ++it)
    if (*it == _consumabile) trovato = true;
  return trovato;
}

void GestoreRisorse::rimuoviArticoloDaMenu(Articolo* daRimuovere) {
  Lista<Articolo*>::Iterator it = getPosizione(menu, daRimuovere);
  // bool trovato = false;
  if (it != menu.end())
    // for (it = menu.begin(); it != menu.end() && !trovato; ++it)
    //   if (*it == daRimuovere) trovato = true;
    menu.erase(it);
}

// TODO: Verifica tipo istanziazione container in push_back
void GestoreRisorse::inserisciConsumabileInInventario(Consumabile* daInserire) {
  inventario.push_back(daInserire);
}

void GestoreRisorse::rimuoviConsumabileDaInventario(Consumabile* daRimuovere) {
  if (!dynamic_cast<Pizza*>(daRimuovere)) {
    auto it = getPosizione(inventario, daRimuovere);
    if (it != inventario.end()) inventario.erase(it);
  }
  // pizza
  else {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
      if (dynamic_cast<Pizza*>(*it)) {
        Pizza* temPizza = static_cast<Pizza*>(*it);
        if (getPosizione(temPizza->getIngredienti(),
                         static_cast<Ingrediente*>(daRimuovere)) !=
            temPizza->getIngredienti().end())
          temPizza->setDisponibilita(false);
      }
    }
  }

  //   if (!dynamic_cast<Farina*>(daRimuovere)) {
  //     Lista<Articolo*>::Iterator it;
  //     // pizza
  //     for (it = menu.begin(); it != menu.end(); ++it) {
  //       if (dynamic_cast<Pizza*>(*it)) {
  //         bool trovato = false;
  //         Pizza* temPizza = static_cast<Pizza*>(*it);
  //         for (auto it2 = temPizza->getIngredienti().const_begin();
  //              it2 != temPizza->getIngredienti().const_end(); ++it)
  //           if (*it2 == daRimuovere) trovato = true;
  //         if (trovato) temPizza->setDisponibilita(false);
  //       }
  //       // bevanda
  //       else if (dynamic_cast<Bevanda*>(*it)) {
  //         int x;
  //       }
  //       // farina
  //       else {
  //         Lista<Consumabile*>::Iterator it;
  //         bool trovato = false;
  //         for (it = inventario.begin(); it != inventario.end() && !trovato;
  //         ++it)
  //           if (*it == daRimuovere) trovato = true;
  //         inventario.erase(it);
  //       }
  //     }
  //   }
  // }
