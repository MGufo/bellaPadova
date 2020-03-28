#include "articolo.h"
//#include "consumabile.h"

class Bevanda : public Articolo, public Consumabile {
 private:
  formatoBevanda formato;
  capacitaBevanda capacita;

 public:
  Bevanda(string, bool, double, unsigned int, double, QDate,
          formatoBevanda, capacitaBevanda);
};