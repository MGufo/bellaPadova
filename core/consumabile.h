#ifndef CONSUMABILE_H
#define CONSUMABILE_H

#include <QDate>

#include "risorsa.h"

class Consumabile : virtual public Risorsa {
 private:
  unsigned int quantita;
  double costo;
  QDate dataAcquisto;

 public:
  Consumabile(string, bool, unsigned int, double, QDate);

  /**
   * @brief: Ritorna la quantità acquistata di un consumabile.
   * @return: unsigned int (quantità acquistata)
   */
  unsigned int getQuantita() const;

  /**
   * @brief: Ritorna il costo d'acquisto per un'unità di un consumabile.
   * @return: double (costo d'acquisto)
   */
  double getCosto() const;

  /**
   * @brief: Ritorna la data in cui è stato acquistato un consumabile.
   * @return: QDate& (data d'acquisto)
   */
  const QDate& getDataAcquisto() const;

  /**
   * @brief: Modifica la quantità acquistata di un consumabile.
   * @param: unsigned int (quantità acquistata)
   */
  void setQuantita(const unsigned int);

  /**
   * @brief: Modifica il costo d'acquisto di un consumabile.
   * @param: double (costo d'acquisto)
   */
  void setCosto(const double);

  /**
   * @brief: Modifica la data in cui è stato acquistato un consumabile.
   * @param: QDate& (data d'acquisto)
   */
  void setDataAcquisto(const QDate&);

  virtual double getSpesa() const = 0;
};

#endif
