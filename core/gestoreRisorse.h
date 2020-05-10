#ifndef GESTORERISORSE_H
#define GESTORERISORSE_H

#include "bottiglia.h"
#include "farina.h"
#include "lattina.h"
#include "pizza.h"
#include "qontainer.h"

// Idea da implementare: la classe gestore deve gestire le liste di Articoli
// (menu) e consumabili (inventario), permettendo inserimento, modifica,
// rimozione e ricerca all'interno delle liste

class GestoreRisorse {
 private:
  Lista<Articolo *> menu;
  Lista<Consumabile *> inventario;

 protected:
  /**
   * @brief: Controlla la disponibilità di un articolo nel menu
   * @param: Articolo* (articolo di cui si vuole conoscere la disponibilità)
   * @return: TRUE se l'articolo è presente nel menu, FALSE altrimenti
   */
  bool controlloDisponibilita(const Articolo *) const;

  /**
   * @brief: Controlla la disponibilità di un consumabile nell'inventario
   * @param: Consumabile* (consumabile di cui si vuole conoscere la
   * disponibilità)
   * @return: TRUE se il consumabile è presente nell'inventario, FALSE
   * altrimenti
   */
  bool controlloDisponibilita(const Consumabile *) const;

  // HACK: La '&' dev'essere adiacente al nome del parametro!
  template <class T>
  typename Lista<T>::Iterator getPosizione(const Lista<T> &lista,
                                           const T &valore) const {
    typename Lista<T>::Iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
      if (*it == valore) return it;
    return it;
  }

 public:
  GestoreRisorse();

  /**
   * @brief: Inserisce un consumabile nella lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da inserire)
   * @note: L'aggiunta di una bevanda all'inventario provoca la sua aggiunta al
   * menu.
   */
  void inserisciArticoloInMenu(Articolo *);

  /**
   * @brief: Rimuove un articolo dalla lista di articoli (menu).
   * @param: Articolo* (oggetto da rimuovere)
   * @note: La rimozione di una pizza non provoca l'eliminazione di ogni suo
   * ingrediente.
   * @note: La rimozione di una bevanda provoca la sua rimozione anche
   * dall'inventario.
   */
  void rimuoviArticoloDaMenu(Articolo *);

  /**
   * @brief: Inserisce un consumabile nella lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da inserire)
   * @note: L'aggiunta di una bevanda all'inventario provoca la sua aggiunta al
   * menu.
   */
  void inserisciConsumabileInInventario(Consumabile *);

  /**
   * @brief: Rimuove un consumabile dalla lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da rimuovere)
   * @note: La rimozione di un ingrediente provoca l'aggiornamento a "non
   * disponibile" delle pizze che contengono l'ingrediente.
   * @note: La rimozione di una bevanda provoca la rimozione
   * della stessa anche nella lista di articoli (menu).
   * @note: La rimozione della farina di default non è consentita.
   */
  void rimuoviConsumabileDaInventario(Consumabile *);
};

#endif
