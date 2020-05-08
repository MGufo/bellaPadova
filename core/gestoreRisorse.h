#ifndef GESTORERISORSE_H
#define GESTORERISORSE_H
#include "bottiglia.h"
#include "farina.h"
#include "lattina.h"
#include "pizza.h"
#include "qontainer.h"

class GestoreRisorse {
 private:
  Lista<Articolo*> menu;
  Lista<Consumabile*> inventario;

  // Idea da implementare: la classe gestore deve gestire le liste di Articoli
  // (menu) e consumabili (inventario), permettendo inserimento, modifica,
  // rimozione e ricerca all'interno delle liste

  template <class T>
  typename Lista<T*>::Iterator getPosizione(Lista<T*> lista, T* valore);
  template <class T>
  typename Lista<T*>::Iterator getPosizione(const Lista<T*> lista, T* valore);

 protected:
  bool controlloDisponibilita(const Articolo*) const;
  bool controlloDisponibilita(const Consumabile*) const;

 public:
  GestoreRisorse();

  void inserisciArticoloInMenu();
  void rimuoviArticoloDaMenu(Articolo*);

  void inserisciConsumabileInInventario(Consumabile*);

  // Nell'eliminare un consumabile si setta la disponibilità delle pizze che
  // usano quel consumabile a false.
  // Eccezione: la farina di default NON PUÒ essere eliminata!
  void rimuoviConsumabileDaInventario(Consumabile*);
};

#endif