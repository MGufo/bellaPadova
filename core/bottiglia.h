#ifndef BOTTIGLIA_H
#define BOTTIGLIA_H
#include "bevanda.h"

class Bottiglia : public Bevanda {
 public:
  Bottiglia();
  Bottiglia(unsigned int, string, bool, double, unsigned int, double, QDate,
            float);
  Bottiglia* clone() const;

  /**
   * @brief: Ritorna il costo dell'articolo comprensivo di eventuali extra.
   * @return: double (costo)
   */
  double getPrezzo() const;

  /**
   * @brief: Effettua la serializzazione dell'oggetto, salvando il contenuto dei
   * campi privati nell'oggetto JSON ricevuto come parametro.
   */
  virtual void salva(QJsonObject&) const;
};

#endif
