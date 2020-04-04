#include "container.h"
#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzoBase;

 public:
  Articolo(string, bool, double);
  virtual double getPrezzo() const = 0;
  void setPrezzo(const double&);

  // metodo di clonazione virtuale puro (uso covarianza)
  virtual Articolo* clone() const;
  virtual const Lista<string>* getComposizione() const = 0;
};
