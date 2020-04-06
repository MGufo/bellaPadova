#include "contatto.h"
#include "gestore.h"
#include "risorsa.h"
#include <QDate>

class Pizzeria {
 private:
  Contatto* contatto;
  Gestore* gestore;
 public:
  Pizzeria(string, string, string);
  double contabilizzazione(QDate, QDate) const;
  const Lista<const string&> getContatto() const;
};