#ifndef INGREDIENTE
#define INGREDIENTE

#include "consumabile.h"

class Ingrediente : public Consumabile {
 private:
  bool locale;

 public:
  Ingrediente(string, bool, unsigned int, double, QDate,
              QDate = QDate::currentDate(), bool locale = false);
  Ingrediente(const Ingrediente&);
  bool isLocal() const;
  Ingrediente* clone() const;
  // se gli ingredienti sono locali si aggiunge automaticamente una costante che
  // rappresenta un'offerta verso l'associazione "Amici dello Gnocco"
  double getSpesa() const;
};

#endif
