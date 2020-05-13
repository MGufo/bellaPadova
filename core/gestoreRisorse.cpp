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

/* bool GestoreRisorse::controlloDisponibilita(const Articolo* _articolo)
const { Lista<Articolo*>::const_Iterator it; bool trovato = false; for (it =
menu.const_begin(); it != menu.const_end() && !trovato; ++it) if (*it ==
_articolo) trovato = true; return trovato;
}

bool GestoreRisorse::controlloDisponibilita(
    const Consumabile* _consumabile) const {
  Lista<Consumabile*>::const_Iterator it;
  bool trovato = false;
  for (it = inventario.const_begin(); it != inventario.const_end() &&
!trovato;
       ++it)
    if (*it == _consumabile) trovato = true;
  return trovato;
} */

void GestoreRisorse::inserisciArticoloInMenu(Articolo* daInserire) {
  if (daInserire) {
    const Lista<const Consumabile*>* lista = daInserire->getComposizione();
    daInserire->setDisponibilita(controlloDisponibilita(lista));
    menu.push_back(daInserire);
    delete lista;
  }
}

void GestoreRisorse::rimuoviArticoloDaMenu(Articolo* daRimuovere) {
  if (daRimuovere) {
    Lista<Articolo*>::Iterator it = getPosizione(menu, daRimuovere);
    if (it != menu.end()) {
      menu.erase(it);
    }
  }
}

// TODO: Verifica tipo istanziazione container in push_back
void GestoreRisorse::inserisciConsumabileInInventario(Consumabile* daInserire) {
  if (daInserire) {
    inventario.push_back(daInserire);
  }
}

// TODO: Controllare possibilità di far tornare disponibile una pizza che ha un
// ingredienti non più disponibili
void GestoreRisorse::rimuoviConsumabileDaInventario(Consumabile* daRimuovere) {
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

void GestoreRisorse::modificaArticoloinMenu(Pizza* _pizza,
                                            const Farina* _farina) {
  _pizza->setFarina(_farina);
}

void GestoreRisorse::modificaArticoloinMenu(
    Pizza* _pizza, const Lista<Ingrediente*>* daInserire,
    const Lista<Ingrediente*>* daRimuovere) {
  Lista<Ingrediente*>::const_Iterator it = daInserire->const_begin();

  if (!daInserire->isEmpty()) {
    // controllo presenza nuova farina
    if (dynamic_cast<Farina*>(*it)) {
      _pizza->setFarina(static_cast<Farina*>(*it));
      ++it;
    }
    while (it != daInserire->const_end()) {
      if (!_pizza->checkIngrediente(*it)) _pizza->addIngrediente(*it);
      ++it;
    }
  }
  it = daRimuovere->const_begin();
  if (!daRimuovere->isEmpty()) {
    while (it != daRimuovere->const_end()) {
      if (_pizza->checkIngrediente(*it)) _pizza->removeIngrediente(*it);
      ++it;
    }
  }
}

void GestoreRisorse::modificaArticoloInMenu(Pizza* _pizza, double _extra) {
  _pizza->setExtra(_extra);
}

void GestoreRisorse::modificaArticoloInMenu(Bevanda* _bevanda, double _tax) {
  _bevanda->setPlasticTax(_tax);
}

void GestoreRisorse::modificaArticoloInMenu(Bevanda* _bevanda,
                                            float _capacita) {
  _bevanda->setCapacita(_capacita);
}

void GestoreRisorse::modificaConsumabileInInventario(Consumabile* daModificare,
                                                     unsigned int _qta) {
  daModificare->setQuantita(_qta);
}

void GestoreRisorse::modificaConsumabileInInventario(Consumabile* daModificare,
                                                     double _costo) {
  daModificare->setCosto(_costo);
}

void GestoreRisorse::modificaConsumabileInInventario(Consumabile* daModificare,
                                                     const QDate& _data) {
  daModificare->setDataAcquisto(_data);
}

void GestoreRisorse::modificaConsumabileInInventario(Ingrediente* daModificare,
                                                     bool _locale) {
  daModificare->setLocal(_locale);
}

void GestoreRisorse::modificaConsumabileInInventario(Farina* daModificare,
                                                     const std::string& _tipo) {
  daModificare->setTipoFarina(_tipo);
}

void GestoreRisorse::modificaConsumabileInInventario(Bevanda* _bevanda,
                                                     double _tax) {
  _bevanda->setPlasticTax(_tax);
}

void GestoreRisorse::modificaConsumabileInInventario(Bevanda* _bevanda,
                                                     float _capacita) {
  _bevanda->setCapacita(_capacita);
