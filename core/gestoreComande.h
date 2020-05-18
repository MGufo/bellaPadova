#ifndef GESTORECOMANDE_H
#define GESTORECOMANDE_H
#include "comanda.h"
#include "qontainer.h"

class GestoreComande {
 private:
  Lista<Comanda*> bacheca;
  /**
   * @param: iteratore alla prima comanda da preparare.
   * @brief: tutte le comande che precedono 'current' sono state già preparate.
   */
  Lista<Comanda*>::Iterator current;

  /**
   * @brief: Controlla se sia temporalmente possibile inserire una comanda tra
   * due comande.
   * @param: Comanda* (Comanda all'inizio dello slot temporale)
   * @param: Comanda* (Comanda alla fine dello slot temporale)
   * @param: Comanda* (Comanda che si vuole inserire nello slot temporale)
   */
  bool testInsert(const Comanda*, const Comanda*, const Comanda*);

 public:
  GestoreComande();

  /**
   * @brief: Inserisce una nuova comanda nella lista di comande mantenendo
   l'ordine temporale delle comande da eseguire.

   @param: Comanda* (puntatore alla comanda da inserire)

   Algoritmo di inserimento:
    - ogni pizza ha un tempo di preparazione di 5min
    - il tempo di preparazione di una comanda è: (n° pizze comanda) x 5min
    - Se il tempo di preparazione dell'ordine da inserire calza
    tra l'orario di consegna dell'ordine precedente e (tempo consegna ordine
    succ - tempo preparazione ordine succ) allora la comanda da inserire verrà
    inserita tra le due comande, altrimenti passa alla successiva coppia di
    comande già presenti e ripete il controllo.
  */
  void inserisciComanda(Comanda*);

  /**
   * @brief: Inserimento, rimozione o modifica della quantità di un articolo
   * nella comanda.
   * @param: Comanda* (comanda in cui inserire/modificare/rimuovere un articolo)
   * @param: Articolo* (articolo da inserire/modificare/rimuovere)
   * @param: int (nuova quantità dell'articolo da inserire/modificare; se 0 si
   * rimuove)
   */
  void modificaComanda(Comanda*, const Comanda*);

  /**
   * @brief: incrementa current ( "esegue" la prima comanda non completata)
   */
  void eseguiComanda();

  /**
   * @brief: Rimuove dalla lista di comande la comanda passata come parametro.
   * Se la comanda passata precede *current la rimozione non è permessa.
   * @param: puntatore alla comanda da rimuovere
   */
  void rimuoviComanda(Comanda*);

  /**
   * @brief: Ritorna un puntatore alla comanda puntata da 'current' se la lista
   * ha almeno 1 comanda, nullptr altrimenti.
   */
  const Comanda* getComandaCorrente() const;

  /**
   * @brief: Ritorna una lista contenente tutte le comande
   */
  const Lista<Comanda*>& getBacheca() const;
};

#endif
