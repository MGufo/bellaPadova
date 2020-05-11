#ifndef BEVANDA_H
#define BEVANDA_H

#include "articolo.h"
#include "consumabile.h"

class Bevanda : public Articolo, public Consumabile {
 private:
  static double plasticTax;
  float capacita;

 public:
  Bevanda(string, bool, double, unsigned int, double, QDate, double);

  /**
   * @brief: Ritorna la spesa sostenuta dalla pizzeria per l'acquisto di una
   * bevanda.
   * @return: double (spesa)
   */
  double getSpesa() const;

  /**
   * @brief: Ritorna la capacità di una bevanda
   * @return: double (capacità bevanda in L)
   */
  double getCapacitaBevanda() const;

  /**
   * @brief: Ritorna la "plastic tax"
   * @return: double (costo extra per contenitori in plastica)
   */
  double getPlasticTax() const;

  /**
   * @brief: Modifica la "plastic tax"
   * @param: double (costo extra per contenitori in plastica)
   */
  void setPlasticTax(double);

  /**
   * @brief: Modifica la capacità della bevanda
   * @param: double (nuova capacità espressa in L)
   */
  void setCapacita(float);
};
#endif