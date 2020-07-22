#include "lattina.h"

Lattina::Lattina() {}

Lattina::Lattina(unsigned int id, string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 float capacitaBevanda)
    : Risorsa(id, nome, disponibilita),
      Bevanda(id, nome, disponibilita, prezzo, qta, costo, dataAcquisto,
              capacitaBevanda) {}

Lattina* Lattina::clone() const { return new Lattina(*this); }

double Lattina::getPrezzo() const { return getPrezzoBase(); }

void Lattina::salva(QJsonObject& bevandaJSON) const{
  bevandaJSON.insert("tipo", "lattina");
  Bevanda::salva(bevandaJSON);
}
