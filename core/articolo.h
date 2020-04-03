#include "container.h"
#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzo;

 public:
  Articolo(string, bool, double);
  double getPrezzo() const;
  void setPrezzo(const double&);

  // metodo di clonazione virtuale puro (uso covarianza)
  virtual Articolo* clone() const;
  virtual const Lista<string>* getComposizione() const = 0;
};
