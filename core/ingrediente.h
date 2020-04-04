#include "consumabile.h"

class Ingrediente : public Consumabile{
 private:
   bool locale;
 public:
   Ingrediente(string, bool, unsigned int, double, QDate=QDate::currentDate(), bool locale=false);
   bool isLocal();
   Ingrediente* clone() const;
};
