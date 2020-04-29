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
  static unsigned short capacitaForno;

 public:
  Comanda(unordered_map<Articolo*, unsigned int>, Contatto, QTime);
  Comanda(const Comanda&);

  const unordered_map<Articolo*, unsigned int>& getOrdinazione() const;

  int getTempoPreparazione() const;

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

  // .8 modifica contatto
  void modificaContatto(string = "", string = "", string = "");

  // .10 modifica qta articolo presente in comanda
  void modificaQuantita(Articolo*, int);

  // .11 set qta articolo presente in comanda
  void setQuantita(Articolo*, int);

  bool operator<(const Comanda&) const;

  bool operator<=(const Comanda&) const;

  bool operator>(const Comanda&) const;

  bool operator>=(const Comanda&) const;

  bool operator<(const Comanda&) const;

  bool operator==(const Comanda&) const;

  bool operator!=(const Comanda&) const;
};

#endif
