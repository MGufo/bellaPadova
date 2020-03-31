#include "articolo.h"
#include "consumabile.h"

class Bevanda : public Articolo, public Consumabile {
 private:
  formatoBevanda formato;
  capacitaBevanda capacita;

 public:
  Bevanda(string nome = "acqua", bool disponibilita = true, double prezzo = 4.5,
          unsigned int qta = 1, double costo = 10,
          QDate dataAcquisto = QDate::currentDate(),
          formatoBevanda fb = formatoBevanda::bottiglia,
          capacitaBevanda cb = capacitaBevanda::CL50);
  Bevanda* clone() const;
};
