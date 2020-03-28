#include "risorsa.h"
class Articolo : virtual public Risorsa {
 private:
  double prezzo;

 public:
  Articolo(string nome, bool disponibilita = true, double p =)
      : Risorsa(nome, disponibilita), prezzo(p){};
};