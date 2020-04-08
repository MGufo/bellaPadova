#include "consumabile.h"
#include "articolo.h"

class Gestore {
 private:
  Lista<Articolo*>* menu; 
  Lista<Consumabile*>* inventario; 
 public:
  Gestore();
};