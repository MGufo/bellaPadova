#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>
#include <unordered_map>

#include "articolo.h"
#include "contatto.h"
#include "farina.h"

using std::unordered_map;

class Comanda {
 private:
  std::unordered_map<Articolo*, unsigned int> articoli;
  Contatto* cliente;
  QTime oraConsegna;

 public:
  Comanda(unordered_map<Articolo*, unsigned int>, Contatto*, QTime);
  Comanda(const Comanda&);
  ~Comanda();

  // .1 aggiungere un nuovo articolo non presente in comanda (se già presente,
  // incrementa la qta) (param: articoloDaInserire, qta)
  // caso particolare di .2
  void inserisciArticolo(Articolo*, unsigned int);

  // .2 sostituire un articolo presente in comanda con un altro
  // articolo non presente (param: articoloDaSostituire,
  // qtaArticoloDaSostituire, articoloDaInserire, qtaArticoloDaInserire)
  void sostituisciArticolo(Articolo*, unsigned int, Articolo*, unsigned int);

  // .3 sostituire un articolo presente in comanda con un altro
  // articolo non presente (param: articoloDaSostituire,
  // articoloDaInserire, qtaArticoloDaInserire)
  // caso particolare di .2

  // .4 rimuovere un articolo presente in comanda (param: articoloDaRimuovere,
  // qta) caso particolare di .2
  void rimuoviArticolo(Articolo*);

  // .5 modificare la farina della pizza
  // (param: articoloDaModificare, Farina* da modificare)
  void modificaFarina(Articolo*, Farina*);
  // .6 inserire un nuovo ingrediente nella pizza
  // (param: articoloDaModificare, Ingrediente* da inserire)
  // (se già presente non succede nulla e notifica l'utente)

  // .7 rimuovere un nuovo ingrediente nella pizza
  // (param: articoloDaModificare, Ingrediente* da rimuovere)
  // (se non presente non succede nulla e notifica l'utente)

  // .8 modifica contatto

  // .9 modifica ora consegna
  // (delirio)

  // .10 modifica qta articolo presente in comanda
};

#endif
