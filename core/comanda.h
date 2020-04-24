#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>
#include <unordered_map>

#include "articolo.h"
#include "contatto.h"

using std::unordered_map;

class Comanda {
 private:
  std::unordered_map<Articolo*, unsigned int>* articoli;
  Contatto* cliente;
  QTime oraConsegna;

 public:
  Comanda(unordered_map<Articolo*, unsigned int>*, Contatto*, QTime);
  Comanda(const Comanda&);
  ~Comanda();
  // aggiunta-rimozione articolo
  // modifica qta articolo

  //getter setter
};

#endif
