#ifndef LATTINA_H
#define LATTINA_H
#include "bevanda.h"

class Lattina : public Bevanda {
 public:
  Lattina();
  Lattina(unsigned int, string, bool, double, unsigned int, double, QDate,
          float);

  /**
   * @brief: Metodo polimorfo di clonazione dell'oggetto
   * @returns: Farina* (puntatore a un nuovo oggetto creato di copia a partire
   * dall'oggetto di invocazione)
   */
  Lattina* clone() const;

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
