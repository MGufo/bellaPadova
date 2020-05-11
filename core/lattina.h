#ifndef LATTINA_H
#define LATTINA_H
#include "bevanda.h"

class Lattina : public Bevanda {
 public:
  Lattina(string, bool, double, unsigned int, double, QDate, double);
  Lattina* clone() const;

  /**
   * @brief: Ritorna il costo dell'articolo comprensivo di eventuali extra.
   * @return: double (costo)
   */
  double getPrezzo() const;
};
#endif
