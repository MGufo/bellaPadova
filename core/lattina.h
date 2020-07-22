#ifndef LATTINA_H
#define LATTINA_H
#include "bevanda.h"

class Lattina : public Bevanda {
 public:
  Lattina();
  Lattina(unsigned int, string, bool, double, unsigned int, double, QDate, float);
  Lattina* clone() const;

  /**
   * @brief: Ritorna il costo dell'articolo comprensivo di eventuali extra.
   * @return: double (costo)
   */
  double getPrezzo() const;

  virtual void salva(QJsonObject &) const;
};
#endif
