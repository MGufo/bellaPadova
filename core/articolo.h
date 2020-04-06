#include "container.h"
#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzoBase;

 public:
  Articolo(string, bool, double);

  // metodo di clonazione virtuale puro (uso covarianza)
  virtual Articolo* clone() const;
  virtual double getPrezzo() const = 0;
  void setPrezzo(const double&);
};
