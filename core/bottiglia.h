#include "bevanda.h"

class Bottiglia : public Bevanda {
 public:
  Bottiglia(string, bool, double, unsigned int, double, QDate, QDate, double);
  Bottiglia* clone() const;
  double getPrezzo() const;
};