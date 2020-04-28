#ifndef GESTORECOMANDE_H
#define GESTORECOMANDE_H
#include "comanda.h"
#include "qontainer.h"
/*
Il gestore delle comande viene implementato tramite il container (già definito).
Le comande vengono inserite in coda al container e rimosse dalla testa o da un
indice.
*/

class GestoreComande {
 private:
  Lista<Comanda*> bacheca;
  // current è l'iteratore che punta alla prima comanda del sottoinsieme di
  // comande da preparare. Tutte le comande precedenti a 'current' sono state
  // già preparate.
  Lista<Comanda*>::Iterator current;

  /*
    Funzione che inserisce una nuova comanda nella coda ('bacheca') di comande.
    La funzione deve mantere l'ordine temporale delle comande da eseguire,
    quindi prima di inserire una nuova comanda determina dopo quale comanda
    già presente si debba inserire la nuova.
    Per determinare la posizione d'inserimento si usa il seguente algoritmo:
    - ogni pizza ha un tempo di preparazione di 5min
    - il tempo di preparazione di una comanda è: (n° pizze comanda) x costante
    di preparazione Se il tempo di preparazione dell'ordine da inserire calza
    tra l'orario di consegna dell'ordine precedente e (tempo consegna ordine
    succ - tempo preparazione ordine succ) allora la comanda da inserire verrà
    inserita tra le due comande, altrimenti passa alla successiva coppia di
    comande già presenti e ripete il controllo.
  */
  void inserisciComanda(const Comanda*);

  // modifica comanda

  // rimozione comanda dalla lista
  void rimuoviComanda(Comanda*);

  // getter comanda corrente
  const Comanda* getComandaCorrente() const;
  // getter tutte comande
  Lista<Comanda*> getBacheca();
};

#endif
