#ifndef BEVANDA_H
#define BEVANDA_H

#include "articolo.h"
#include "consumabile.h"

enum formatoBevanda { bottiglia, lattina };
enum capacitaBevanda { CL33, CL50, CL66, L1 };

class Bevanda : public Articolo, public Consumabile {
 private:
  formatoBevanda formato;
  capacitaBevanda capacita;

 public:
  Bevanda(string, bool, double, unsigned int, double, QDate, QDate,
          formatoBevanda, capacitaBevanda);
  Bevanda* clone() const;
  double getSpesa() const;
  double getPrezzo() const;
};
#endif