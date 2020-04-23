#include "bevanda.h"

class Lattina : public Bevanda {
 public:
  Lattina(string, bool, double, unsigned int, double, QDate, QDate, double);
  Lattina* clone() const;
  double getPrezzo() const;
};