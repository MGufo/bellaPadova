#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "consumabile.h"
#include "qontainer.h"

class Inventario {
 private:
  Lista<Consumabile*>* oggetti;
};

#endif