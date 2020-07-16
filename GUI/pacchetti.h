#ifndef PACCHETTI_H
#define PACCHETTI_H

#include <string>
#include <QDate>

using std::string;

struct pacchetto_ingrediente{
  uint id;
  string nome;
  bool disponibilita;
  uint quantita;
  double costo;
  QDate dataAcquisto;
  bool locale;
  pacchetto_ingrediente* next;

  pacchetto_ingrediente(uint _ID, string _n, bool _d, uint _q,
                        double _c, QDate _da, bool _l,
                        pacchetto_ingrediente* _p = nullptr) :
    id(_ID), nome(_n), disponibilita(_d), quantita(_q), costo(_c),
    dataAcquisto(_da), locale(_l), next(_p) {}
};

struct pacchetto_bevanda{
  uint id;
  string nome;
  bool disponibilita;
  uint quantita;
  double costo;
  QDate dataAcquisto;
  bool locale;
  pacchetto_bevanda* next;

  pacchetto_bevanda(uint _ID, string _n, bool _d, uint _q,
                    double _c, QDate _da, bool _l,
                    pacchetto_bevanda* _p = nullptr) :
    id(_ID), nome(_n), disponibilita(_d), quantita(_q), costo(_c),
    dataAcquisto(_da), locale(_l), next(_p) {}
};

#endif // PACCHETTI_H
