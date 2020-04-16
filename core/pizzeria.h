#include <QDate>

#include "contatto.h"
#include "gestoreComande.h"
#include "gestoreRisorse.h"

class Pizzeria {
 private:
  Contatto* contatto;
  GestoreRisorse* gestoreRisorse;
  GestoreComande* gestoreComande;

 public:
  Pizzeria(string, string, string);
  double contabilizzazione(QDate, QDate) const;
  const Lista<const string&> getContatto() const;
};