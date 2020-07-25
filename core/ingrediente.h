#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "consumabile.h"

class Ingrediente : public Consumabile {
 private:
  bool locale;

 public:
  Ingrediente();
  Ingrediente(unsigned int, string, bool, unsigned int, double,
              QDate = QDate::currentDate(), bool locale = false);

  /**
   * @brief: Controllo provenienza ingrediente
   * @return: TRUE se l'ingrediente è locale, FALSE altrimenti
   */
  bool isLocal() const;

  /**
   * @brief: Imposta la provenienza di un ingrediente
   * @param: bool (TRUE se l'ingrediente è locale, FALSE altrimenti)
   */
  void setLocal(bool);

  /**
   * @brief: Ritorna la spesa sostenuta dalla pizzeria per acquistare
   * l'ingrediente.
   * @return: double (spesa)
   * @note: Se l'ingrediente è locale viene aggiunto un extra da donare
   * all'associazione "Amici dello Gnocco"
   */
  double getSpesa() const;

  Ingrediente* clone() const;

  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>* = nullptr);

  virtual void salva(QJsonObject &) const;
};

#endif
