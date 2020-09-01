#ifndef GESTORERISORSE_H
#define GESTORERISORSE_H

#include <unordered_map>

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

  /**
   * scorre una lista di consumabili
   * ritorna TRUE se sono tutti disp
   * ritorna FALSE se almeno uno non lo è
   */
  bool controlloDisponibilita(const Lista<const Consumabile *> *) const;

  /**
   * @brief: Scorre la lista alla ricerca di un consumabile
   * @param: const Lista<const Consumabile *> (lista da scorrere)
   * @param: const Consumabile* (consumabile da cercare nella lista)
   * @returns: TRUE se il consumabile è presente nella lista, FALSE altrimenti.
   */
  bool controlloConsumabile(const Lista<const Consumabile *> *,
                            const Consumabile *) const;

  unsigned int getMaxId() const;

 public:
  GestoreRisorse();

  // controlla che siano presenti tutti i consumabili della lista di
  // composizione di un articolo nell'inventario
  /**
   * @brief: Controlla che ogni ingrediente nella lista di ingredienti
   * dell'articolo d'invocazione sia disponibile
   * @returns: True se tutti gli ingredienti sono disponibili, falsi altrimenti.
   */
  bool controlloInInventario(Articolo *) const;

  /**
   * @brief: Metodo di ricerca per ID
   * @returns: Risorsa* (puntatore all'oggetto che ha come ID l'ID ricevuto come
   * parametro, nullptr altrimenti)
   */
  Risorsa *trovaRisorsa(unsigned int ID) const;

  /**
   * @brief: Inserisce un consumabile nella lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da inserire)
   * @note: Non è possibile aggiungere un articolo se non sono presenti tutti i
   * consumabili richiesti per la sua creazione.
   */
  void inserisciArticolo(Articolo *);

  void modificaArticolo(Articolo *, Articolo *);

  /**
   * @brief: Rimuove un articolo dalla lista di articoli (menu).
   * @param: Articolo* (oggetto da rimuovere)
   * @note: La rimozione di una pizza non provoca l'eliminazione di ogni suo
   * ingrediente.
   * @note: La rimozione di una bevanda provoca la sua rimozione anche
   * dall'inventario.
   */
  void rimuoviArticolo(Articolo *);

  /**
   * @brief: Inserisce un consumabile nella lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da inserire)
   * @note: I consumabili da inserire vengono creati prima dell'inserimento.
   */
  void inserisciConsumabile(Consumabile *);

  void modificaConsumabile(Consumabile *, Consumabile *);

  /**
   * @brief: Rimuove un consumabile dalla lista di consumabili (inventario).
   * @param: Consumabile* (oggetto da rimuovere)
   * @note: La rimozione di un ingrediente rende non disponibili nel menu le
   * pizze che contenevano l'ingrediente rimosso.
   * @note: La rimozione di una bevanda provoca la rimozione
   * della stessa anche nella lista di articoli (menu).
   * @note: La rimozione della farina di default non è consentita.
   */
  void rimuoviConsumabile(Consumabile *);

  const Lista<Articolo *> &getMenu() const;

  const Lista<Consumabile *> &getInventario() const;

  void salvaRisorse(QJsonObject *) const;

  void salvaIdRisorse(QJsonObject *) const;

  void caricaMenu(const QJsonObject &);
  void caricaInventario(const QJsonObject &);
};
#endif
