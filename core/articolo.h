#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzo;

 public:
  Articolo(string, bool, double);
  double& getPrezzo() const;
  void setPrezzo(const double&);
};
