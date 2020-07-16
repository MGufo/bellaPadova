#ifndef PACCHETTI_H
#define PACCHETTI_H

#include <string>
#include <QDate>
#include "../core/qontainer.h"

using std::string;
struct pacchetto {
  uint ID;
  string nome;
  bool disponibilita;

  pacchetto(uint _ID, string _n, bool _d) :
    ID(_ID), nome(_n), disponibilita(_d) {}

  virtual ~pacchetto() = default;
};

struct pacchettoArticolo : pacchetto {
  double prezzo;

  pacchettoArticolo(uint _ID, string _n, bool _d, double _p) :
    pacchetto(_ID, _n, _d), prezzo(_p) {}
};

struct pacchettoConsumabile : pacchetto {
  uint quantita;
  double costo;
  QDate dataAcquisto;

  pacchettoConsumabile(uint _ID, string _n, bool _d, uint _q, double _c, QDate _da) :
    pacchetto(_ID, _n, _d), quantita(_q), costo(_c), dataAcquisto(_da) {}
};

struct pacchettoIngrediente : pacchettoConsumabile {
  bool locale;
  pacchettoIngrediente(uint _ID, string _n, bool _d, uint _q,
                        double _c, QDate _da, bool _l) :
    pacchettoConsumabile(_ID, _n, _d, _q, _c, _da), locale(_l) {}
};

struct pacchettoFarina : pacchettoIngrediente{
  string tipologia;
  pacchettoFarina(uint _ID, string _n, bool _d, uint _q,
                        double _c, QDate _da, bool _l, string _t) :
    pacchettoIngrediente(_ID, _n, _d, _q, _c, _da, _l), tipologia(_t) {}
};

struct pacchettoBevandaA : pacchettoArticolo{
  // 0: bottiglia
  // 1: lattina
  bool tipo;
  float capacita;

  pacchettoBevandaA(uint _ID, string _n, bool _d, double _p, bool _t, float _f)
    : pacchettoArticolo(_ID, _n, _d, _p), tipo(_t), capacita(_f) {}
};

struct pacchettoBevandaC : pacchettoConsumabile{
  bool tipo;
  float capacita;
  pacchettoBevandaC(uint _ID, string _n, bool _d, uint _q, double _c,
                    QDate _da, bool _t, float _cap) :
    pacchettoConsumabile(_ID, _n, _d, _q, _c, _da), tipo(_t), capacita(_cap) {}
};

struct pacchettoPizza : pacchettoArticolo{
  Lista<uint> ingredienti;
  pacchettoPizza(uint _ID, string _n, bool _d, double _p) :
    pacchettoArticolo(_ID, _n, _d, _p), ingredienti(Lista<uint>()) {}
};

#endif // PACCHETTI_H
