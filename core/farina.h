#ifndef FARINA_H
#define FARINA_H
#include "ingrediente.h"

/**
 * @brief: Classe che rappresenta l'ingrediente 'farina', usato come ingrediente
 * base di ogni pizza.
 * @note: Modellare la farina come classe permette maggiore estensibilità
 * (aggiunta/rimozione di farine) rispetto ad un enumerazione.
 */
class Farina : public Ingrediente {
 private:
  string tipoFarina;

 public:
  Farina();
  Farina(unsigned int, string = "farina 1kg", bool = true, unsigned int = 1, double = 3,
         QDate = QDate::currentDate(), bool = true, string = "tipo 00");

  // TODO: Add exception se stringa vuota
  /**
   * @brief: Ritorna il tipo di una farina (00, integrale, ecc)
   * @return: string& (tipo di farina)
   */
  const string& getTipoFarina() const;

  /**
   * @brief: Modifica il tipo farina ad una farina esistente
   * @param: string& (nuovo tipo farina)
   */
  void setTipoFarina(const string&);

  Farina* clone() const;

  virtual void carica(const QJsonObject&);

  virtual void salva(QJsonObject &) const;
};

#endif
