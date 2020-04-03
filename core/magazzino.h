#include "container.h"
#include "risorsa.h"
class Magazzino {
 private:
  Lista<Risorsa*>* boh;

 public:
  virtual void inserimento() = 0;
  virtual void rimozione() = 0;
  virtual void modifica() = 0;
};