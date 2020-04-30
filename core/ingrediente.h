#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "consumabile.h"

class Ingrediente : public Consumabile {
 private:
  bool locale;

 public:
  Ingrediente(string, bool, unsigned int, double, QDate = QDate::currentDate(),
              bool locale = false);

  /**
   * @return: true se l'ingrediente è locale, false altrimenti
   */
  bool isLocal() const;

  /**
   * @brief: Ritorna la spesa sostenuta dalla pizzeria per acquistare
   * l'ingrediente.
   * @return: double (spesa)
   * @note: Se l'ingrediente è locale viene aggiunto un extra da donare
   * all'associazione "Amici dello Gnocco"
   */
  double getSpesa() const;

  Ingrediente* clone() const;
};

#endif
