#include "container.h"
#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzoBase;

 public:
  Articolo(string, bool, double);

  // metodo di clonazione virtuale puro (uso covarianza)
  virtual Articolo* clone() const;
  double getPrezzoBase() const;
  void setPrezzoBase(const double&);
  virtual double getPrezzo() const = 0;
  
};
