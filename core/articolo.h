#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzoBase;

 public:
  Articolo(string, bool, double);

  double getPrezzoBase() const;
  void setPrezzoBase(const double&);
  virtual double getPrezzo() const = 0;
};
