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
  Consumabile();
  Consumabile(unsigned int, string, bool, unsigned int, double, QDate);

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

  // TODO: Add exception se quantità <= 0
  /**
   * @brief: Modifica la quantità acquistata di un consumabile.
   * @param: unsigned int (quantità acquistata)
   */
  void setQuantita(const unsigned int);

  // TODO: Add exception se costo <= 0
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

  /**
   * @brief: Legge i dati di una risorsa da file JSON e li assegna ai campi
   * dati dell'oggetto di invocazione
   * @param: const QJsonObject& (file da cui leggere)
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>*) = 0;

  /**
   * @brief: Serializza l'oggetto di invocazione in un file JSON
   * @param: bool (nuova disponibilità)
   */
  virtual void salva(QJsonObject&) const = 0;
};

#endif
