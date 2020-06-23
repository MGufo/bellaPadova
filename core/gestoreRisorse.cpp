#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

bool GestoreRisorse::controlloInInventario(Articolo * daControllare) const{
    bool presente = true;
    const Lista<Consumabile*>* consumabili = daControllare->getComposizione();
    for(auto it = consumabili->const_begin(); (it != consumabili->const_end()) && presente; ++it){
        presente = controlloConsumabile(&inventario, *it);
    }
    return presente;
}

bool GestoreRisorse::controlloDisponibilita(
    const Lista<Consumabile*>* daCercare) const {
  Lista<Consumabile*>::const_Iterator it;
  bool disponibile = true;
  for (it = daCercare->const_begin();
       it != daCercare->const_end() && disponibile; ++it)
    if (!(*it)->getDisponibilita()) disponibile = false;
  return disponibile;
}

bool GestoreRisorse::controlloConsumabile(const Lista<Consumabile*>* _lista,
                                          Consumabile* daCercare) const {
  if ((_lista->find(daCercare).isValid())) return true;
  return false;
}

void GestoreRisorse::inserisciArticolo(Articolo* daInserire) {
  if (daInserire) {
    const Lista<Consumabile*>* lista = daInserire->getComposizione();
    for (auto it = lista->const_begin(); it != lista->const_end(); ++it)
      if (!controlloConsumabile(&inventario, *it))
        throw new std::logic_error("Errore: Uno o più ingredienti selezionati"
                                   "non sono disponibili.");
    daInserire->setDisponibilita(controlloDisponibilita(lista));
    menu.push_back(daInserire);
    delete lista;
  }
}

void GestoreRisorse::rimuoviArticolo(Articolo* daRimuovere) {
  if (daRimuovere) {
    Lista<Articolo*>::Iterator it = menu.find(daRimuovere);
    if (it.isValid()) {
      menu.erase(it);
    }
  }
}

void GestoreRisorse::inserisciConsumabile(Consumabile* daInserire) {
  if (daInserire) {
    inventario.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviConsumabile(Consumabile* daRimuovere) {
  if (daRimuovere) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
      const Lista<Consumabile*>* lista = (*it)->getComposizione();
      if (controlloConsumabile(lista, daRimuovere)) it = menu.erase(it);
      if (it != menu.begin()) --it;
      delete lista;
    }
    inventario.erase(inventario.find(daRimuovere));
  }
}

void GestoreRisorse::modificaArticolo(Articolo* daModificare,
                                      const Articolo* modificato) {
  *daModificare = *modificato;
  const Lista<Consumabile*>* lista = daModificare->getComposizione();
  for (auto it = lista->const_begin(); it != lista->const_end(); ++it)
    if (!controlloConsumabile(&inventario, *it))
      throw new std::logic_error("Errore: Uno o più ingredienti selezionati"
                                 "non sono disponibili.");
  daModificare->setDisponibilita(controlloDisponibilita(lista));
  delete lista;
}

void GestoreRisorse::modificaConsumabile(Consumabile* daModificare,
                                         const Consumabile* modificato) {
  *daModificare = *modificato;
  for (auto it = menu.begin(); it != menu.end(); ++it) {
    const Lista<Consumabile*>* lista = (*it)->getComposizione();
    (*it)->setDisponibilita(controlloDisponibilita(lista));
    delete lista;
  }
}

const Lista<Articolo*>& GestoreRisorse::getMenu() const { return menu; }

const Lista<Consumabile*>& GestoreRisorse::getInventario() const {
  return inventario;
}

void GestoreRisorse::salvaRisorse(QJsonObject *)
{

}
