#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>
#include <unordered_map>

#include "bevanda.h"
#include "contatto.h"
#include "farina.h"
#include "pizza.h"

using std::unordered_map;

class Comanda {
 private:
  unordered_map<Articolo*, unsigned int> ordinazione;
  Contatto cliente;
  QTime oraConsegna;

 public:
  Comanda(unordered_map<Articolo*, unsigned int>, Contatto, QTime);
  Comanda(const Comanda&);  

  const unordered_map<Articolo*, unsigned int>& getOrdinazione() const;

  const Contatto& getCliente() const;

  const QTime& getOraConsegna() const;

  // .9 modifica ora consegna
  void setOraConsegna(QTime);

  // .1 aggiungere un nuovo articolo non presente in comanda (se già
  // presente, incrementa la qta) (param: articoloDaInserire, qta) caso
  // particolare di .2
  void inserisciArticolo(Articolo*, unsigned int);

  // .2 sostituire un articolo presente in comanda con un altro
  // articolo non presente (param: articoloDaSostituire,
  // qtaArticoloDaSostituire, articoloDaInserire, qtaArticoloDaInserire)
  void sostituisciArticolo(Articolo*, int, Articolo*, unsigned int);

  // .3 sostituire un articolo presente in comanda con un altro
  // articolo non presente (param: articoloDaSostituire,
  // articoloDaInserire, qtaArticoloDaInserire)
  // caso particolare di .2

  // .4 rimuovere un articolo presente in comanda (param: articoloDaRimuovere,
  // qta) caso particolare di .2
  void rimuoviArticolo(Articolo*);

  // .5 modificare la farina della pizza
  // (param: articoloDaModificare, Farina* da modificare)
  void modificaFarina(Pizza*, Farina*);

  // .6 inserire un nuovo ingrediente nella pizza
  // (param: articoloDaModificare, Ingrediente* da inserire)
  // (se già presente non succede nulla e notifica l'utente)
  void aggiungiIngrediente(Pizza*, Ingrediente*);

  // .7 rimuovere un nuovo ingrediente nella pizza
  // (param: articoloDaModificare, Ingrediente* da rimuovere)
  // (se non presente non succede nulla e notifica l'utente)
  void rimuoviIngrediente(Pizza*, Ingrediente*);

  // .8 modifica contatto
  void modificaContatto(string = "", string = "", string = "");

  // .10 modifica qta articolo presente in comanda
  void modificaQuantita(Articolo*, int);
};

#endif
