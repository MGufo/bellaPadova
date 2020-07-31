#ifndef PACCHETTI_H
#define PACCHETTI_H

#include <string>
#include <QDate>
#include <sstream>
#include "../core/qontainer.h"

//TODO: dividere in file header e cpp

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

using std::string;
struct pacchetto {
  uint ID;
  string nome;
  bool disponibilita;

  pacchetto(uint _ID, string _n, bool _d) :
    ID(_ID), nome(_n), disponibilita(_d) {}

  virtual ~pacchetto() = default;
};

struct pacchettoArticolo : virtual public pacchetto {
  double prezzo;

  pacchettoArticolo(uint _ID, string _n, bool _d, double _p) :
    pacchetto(_ID, _n, _d), prezzo(_p) {}
};

struct pacchettoConsumabile : virtual public pacchetto {
  uint quantita;
  double costo;
  QDate dataAcquisto;

  pacchettoConsumabile(uint _ID, string _n, bool _d, uint _q, double _c, QDate _da) :
    pacchetto(_ID, _n, _d), quantita(_q), costo(_c), dataAcquisto(_da) {}
};

struct pacchettoIngrediente : pacchettoConsumabile {
  bool locale;
  pacchettoIngrediente(uint _ID, string _n, bool _d, uint _q, double _c, QDate _da, bool _l) : pacchetto(_ID, _n, _d), pacchettoConsumabile(_ID, _n, _d, _q, _c, _da), locale(_l) {}
};

struct pacchettoFarina : pacchettoIngrediente{
  string tipologia;
  pacchettoFarina(uint _ID, string _n, bool _d, uint _q, double _c, QDate _da, bool _l, string _t) : pacchetto(_ID, _n, _d), pacchettoIngrediente(_ID, _n, _d, _q, _c, _da, _l), tipologia(_t) {}
};

struct pacchettoBevanda : pacchettoArticolo, pacchettoConsumabile{

  float capacita;
  // 0: bottiglia
  // 1: lattina
  bool tipo;

  pacchettoBevanda(uint _ID, string _n, bool _d, double _p, uint _q, double _c, QDate _da, float _ca, bool _t)
    : pacchetto(_ID, _n, _d), pacchettoArticolo(_ID, _n, _d, _p),  pacchettoConsumabile(_ID,_n,_d,_q,_c,_da), capacita(_ca), tipo(_t) {}
};

struct pacchettoPizza : pacchettoArticolo{
  Lista<uint> ingredienti;
  pacchettoPizza(uint _ID, string _n, bool _d, double _p) : pacchetto(_ID,_n,_d), pacchettoArticolo(_ID, _n, _d, _p), ingredienti(Lista<uint>()) {}
};

#endif // PACCHETTI_H
