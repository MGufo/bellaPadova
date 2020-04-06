#include "risorsa.h"
#include <QDate>

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
  // calcola la spesa totale per l'acquisto di un consumabile
  double getSpesa() const;
  virtual Consumabile* clone() const;
};
