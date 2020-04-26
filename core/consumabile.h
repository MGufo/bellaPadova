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

  // Getter
  unsigned int getQuantita() const;
  double getCosto() const;
  const QDate& getDataAcquisto() const;

  // Setter
  void setQuantita(const unsigned int);
  void setCosto(const double);
  void setDataAcquisto(const QDate&);

  // Metodi Propri
  // Beneficenza sul cibo locale
  virtual double getSpesa() const = 0;
};

#endif
