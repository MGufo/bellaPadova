#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

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

void GestoreRisorse::inserisciArticoloInMenu(Articolo* daInserire) {
  if (daInserire) {
    if (dynamic_cast<Bevanda*>(daInserire))
      inventario.push_back(dynamic_cast<Consumabile*>(daInserire));
    menu.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviArticoloDaMenu(Articolo* daRimuovere) {
  if (daRimuovere) {
    Lista<Articolo*>::Iterator it = getPosizione(menu, daRimuovere);
    if (it != menu.end()) {
      if (dynamic_cast<Bevanda*>(*it))
        inventario.erase(
            getPosizione(inventario, dynamic_cast<Consumabile*>(daRimuovere)));
      menu.erase(it);
    }
  }
}

// TODO: Verifica tipo istanziazione container in push_back
void GestoreRisorse::inserisciConsumabileInInventario(Consumabile* daInserire) {
  if (daInserire) {
    if (dynamic_cast<Bevanda*>(daInserire))
      menu.push_back(dynamic_cast<Articolo*>(daInserire));
    inventario.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviConsumabileDaInventario(Consumabile* daRimuovere) {
  if (daRimuovere) {
    // bevanda
    if (dynamic_cast<Bevanda*>(daRimuovere)) {
      Lista<Articolo*>::Iterator it =
          getPosizione(menu, dynamic_cast<Articolo*>(daRimuovere));
      if (it != menu.end()) menu.erase(it);
    } else {
      // ingrediente
      for (auto it = menu.begin(); it != menu.end(); ++it) {
        Pizza* currentPizza = dynamic_cast<Pizza*>(*it);
        if (currentPizza) {
          if (currentPizza->checkIngrediente(
                  static_cast<Ingrediente*>(daRimuovere)))
            currentPizza->setDisponibilita(false);
        }
      }
    }
    // farina di default
    Farina* tmp = dynamic_cast<Farina*>(daRimuovere);
    if (!tmp || (tmp && tmp->getTipoFarina() != "tipo 00")) {
      inventario.erase(getPosizione(inventario, daRimuovere));
    }
  }
}

void GestoreRisorse::modificaArticoloinMenu(Articolo* daModificare,
                                            const std::string& _nome) {
  daModificare->setNome(_nome);
}

void GestoreRisorse::modificaArticoloinMenu(Articolo* daModificare,
                                            bool _disponibilita) {
  daModificare->setDisponibilita(_disponibilita);
}

void GestoreRisorse::modificaArticoloinMenu(Articolo* daModificare,
                                            double _prezzoBase) {
  daModificare->setPrezzoBase(_prezzoBase);
}

void GestoreRisorse::modificaArticoloinMenu(Pizza* daModificare,
                                            const Farina* _farina) {
  daModificare->setFarina(_farina);
}

void GestoreRisorse::modificaArticoloinMenu(
    Pizza* daModificare, const Lista<Ingrediente*>* daInserire,
    const Lista<Ingrediente*>* daRimuovere) {
  Lista<Ingrediente*>::const_Iterator it = daInserire->const_begin();

  if (!daInserire->isEmpty()) {
    // controllo presenza nuova farina
    if (dynamic_cast<Farina*>(*it)) {
      daModificare->setFarina(static_cast<Farina*>(*it));
      ++it;
    }
    while (it != daInserire->const_end()) {
      if (!daModificare->checkIngrediente(*it))
        daModificare->addIngrediente(*it);
      ++it;
    }
  }
  it = daRimuovere->const_begin();
  if (!daRimuovere->isEmpty()) {
    while (it != daRimuovere->const_end()) {
      if (daModificare->checkIngrediente(*it))
        daModificare->removeIngrediente(*it);
      ++it;
    }
  }
}

void GestoreRisorse::modificaArticoloInMenu(Pizza *, double){

}
