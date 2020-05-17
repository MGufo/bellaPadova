#include "comanda.h"

#include "pizzeria.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(Contatto _cliente, QTime _oraConsegna,
                 unordered_map<Articolo*, unsigned int> _ordinazione)
    : cliente(_cliente), oraConsegna(_oraConsegna), ordinazione(_ordinazione) {}

// Comanda::Comanda(const Comanda& c)
//  :
//    cliente(c.cliente),
//    oraConsegna(c.oraConsegna),
//    ordinazione(c.ordinazione) {}

const unordered_map<Articolo*, unsigned int>& Comanda::getOrdinazione() const {
  return ordinazione;
}

int Comanda::getTempoPreparazione() const {
  unsigned short nPizze = 0;
  int tempoPreparazione = 5;
  for (auto it = ordinazione.begin(); it != ordinazione.end(); ++it)
    if (dynamic_cast<Pizza*>((*it).first)) nPizze += (*it).second;
  if (nPizze <= Pizzeria::getCapacitaForno())
    return tempoPreparazione;
  else {
    tempoPreparazione = 5 * (nPizze / Pizzeria::getCapacitaForno());
    if ((nPizze % 5) != 0) tempoPreparazione += 5;
    return tempoPreparazione;
  }
}

QTime& Comanda::getOrarioInizioPreparazione() const {
  QTime* orario =
      new QTime(getOraConsegna().addSecs(-getTempoPreparazione() * 60));
  return *orario;
}
const Contatto& Comanda::getCliente() const { return cliente; }

const QTime& Comanda::getOraConsegna() const { return oraConsegna; }

void Comanda::setOraConsegna(QTime _oraConsegna) { oraConsegna = _oraConsegna; }

// sottocaso 1: aggiungere un nuovo articolo non presente in comanda
void Comanda::inserisciArticolo(Articolo* _daInserire, unsigned int _qtaDI) {
  if (_daInserire) ordinazione[_daInserire] = _qtaDI;
}

void Comanda::modificaQuantitaArticolo(Articolo* daModificare,
                                       unsigned int qta) {
  inserisciArticolo(daModificare, qta);
}

// sottocaso 4: rimuovere un articolo presente in comanda
void Comanda::rimuoviArticolo(Articolo* _daSostituire) {
  ordinazione.erase(_daSostituire);
}

void Comanda::modificaContatto(const Contatto* modificato) {
  cliente = *modificato;
}

bool Comanda::operator<(const Comanda& c) const {
  return getOraConsegna() < c.getOraConsegna();
}

bool Comanda::operator<=(const Comanda& c) const {
  return getOraConsegna() <= c.getOraConsegna();
}

bool Comanda::operator>(const Comanda& c) const {
  return getOraConsegna() > c.getOraConsegna();
}

bool Comanda::operator>=(const Comanda& c) const {
  return getOraConsegna() >= c.getOraConsegna();
}

bool Comanda::operator==(const Comanda& c) const {
  return getOraConsegna() == c.getOraConsegna();
}

bool Comanda::operator!=(const Comanda& c) const {
  return getOraConsegna() != c.getOraConsegna();
}
