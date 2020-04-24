#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>

#include "articolo.h"
#include "qontainer.h"
#include "contatto.h"
class Comanda {
 private:
  Lista<Articolo*> articoli;
  Lista<unsigned int> quantita;
  Contatto cliente;
  QTime oraConsegna;
};

#endif
