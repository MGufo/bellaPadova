#ifndef BEVANDA_H
#define BEVANDA_H

#include "articolo.h"
#include "consumabile.h"

class Bevanda : public Articolo, public Consumabile {
 private:
  static double plasticTax;
  double capacita;

 public:
  Bevanda(string, bool, double, unsigned int, double, QDate, QDate, double);

  // getter
  double getSpesa() const;
  double getCapacitaBevanda() const;
  double getPlasticTax() const;

  // setter

  void setPlasticTax(double);
  void setCapacita(double);
};
#endif