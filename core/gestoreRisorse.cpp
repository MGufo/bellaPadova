#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

bool GestoreRisorse::controlloDisponibilita(
    const Lista<const Consumabile*>* daCercare) const {
  Lista<const Consumabile*>::const_Iterator it;
  bool disponibile = true;
  for (it = daCercare->const_begin();
       it != daCercare->const_end() && disponibile; ++it)
    if (!(*it)->getDisponibilita()) disponibile = false;
  return disponibile;
}

bool GestoreRisorse::controlloConsumabile(
    const Lista<const Consumabile*>* _lista,
    const Consumabile* daCercare) const {
  Lista<const Consumabile*>::const_Iterator it;
  bool trovato = false;
  for (it = _lista->const_begin(); it != _lista->const_end() && !trovato; ++it)
    if (*it == daCercare) trovato = true;
  return trovato;
}

void GestoreRisorse::inserisciArticolo(Articolo* daInserire) {
  if (daInserire) {
    const Lista<const Consumabile*>* lista = daInserire->getComposizione();
    daInserire->setDisponibilita(controlloDisponibilita(lista));
    menu.push_back(daInserire);
    delete lista;
  }
}

void GestoreRisorse::rimuoviArticolo(Articolo* daRimuovere) {
  if (daRimuovere) {
    Lista<Articolo*>::Iterator it = getPosizione(menu, daRimuovere);
    if (it != menu.end()) {
      menu.erase(it);
    }
  }
}

// TODO: Verifica tipo istanziazione container in push_back
void GestoreRisorse::inserisciConsumabile(Consumabile* daInserire) {
  if (daInserire) {
    inventario.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviConsumabile(Consumabile* daRimuovere) {
  if (daRimuovere) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
      const Lista<const Consumabile*>* lista = (*it)->getComposizione();
      if (controlloConsumabile(lista, daRimuovere)) it = menu.erase(it);
      if (it != menu.begin()) --it;
      delete lista;
    }
    inventario.erase(getPosizione(inventario, daRimuovere));
  }
}

void GestoreRisorse::modificaArticolo(Articolo* daModificare,
                                      const Articolo* modificato) {
  *daModificare = *modificato;
  const Lista<const Consumabile*>* lista = daModificare->getComposizione();
  daModificare->setDisponibilita(controlloDisponibilita(lista));
  delete lista;
}

void GestoreRisorse::modificaConsumabile(Consumabile* daModificare,
                                         const Consumabile* modificato) {
  *daModificare = *modificato;
  for (auto it = menu.begin(); it != menu.end(); ++it) {
    const Lista<const Consumabile*>* lista = (*it)->getComposizione();
    (*it)->setDisponibilita(controlloDisponibilita(lista));
    delete lista;
  }
}