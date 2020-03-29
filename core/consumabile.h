#include "risorsa.h"

class Consumabile : virtual public Risorsa {
 private:
  unsigned int quantita;
  double costo;
  QDate dataAcquisto;

 public:
  Consumabile(string, bool, unsigned int, double, QDate);
  unsigned int getQuantita() const;
  double getCosto() const;
  const QDate& getDataAcquisto() const;
  void setQuantita(const unsigned int);
  void setCosto(const double);
  void setDataAcquisto(const QDate&);
};
