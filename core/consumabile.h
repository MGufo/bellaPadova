#include "risorsa.h"
#include <QDate>

class Consumabile : virtual public Risorsa {
 private:
  unsigned int quantita;
  double costo;
  QDate dataAcquisto;
  QDate dataScadenza; 
 public:
  Consumabile(string, bool, unsigned int, double, QDate, QDate);

  // Getter
  unsigned int getQuantita() const;
  double getCosto() const;
  const QDate& getDataAcquisto() const;
  const QDate& getDataScadenza() const;
  
  // Setter
  void setQuantita(const unsigned int);
  void setCosto(const double);
  void setDataAcquisto(const QDate&);
  void setDataScadenza(const QDate&); 

  // Metodi Propri
  // calcola la spesa totale per l'acquisto di un consumabile
  double getSpesa() const;
  virtual Consumabile* clone() const;
  virtual bool Scaduto() const = 0; 

};
