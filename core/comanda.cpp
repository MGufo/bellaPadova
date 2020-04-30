#include "comanda.h"

unsigned short Comanda::capacitaForno = 5;
/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(unordered_map<Articolo*, unsigned int> _ordinazione,
                 Contatto _cliente, QTime _oraConsegna)
    : ordinazione(_ordinazione), cliente(_cliente), oraConsegna(_oraConsegna) {}

Comanda::Comanda(const Comanda& c)
    : ordinazione(c.ordinazione),
      cliente(c.cliente),
      oraConsegna(c.oraConsegna) {}

const unordered_map<Articolo*, unsigned int>& Comanda::getOrdinazione() const {
  return ordinazione;
}
int Comanda::getTempoPreparazione() const {
  unsigned short nPizze = 0;
  int tempoPreparazione = 5;
  for (auto it = ordinazione.begin(); it != ordinazione.end(); ++it)
    if (dynamic_cast<Pizza*>((*it).first)) ++nPizze;
  if (nPizze <= capacitaForno)
    return tempoPreparazione;
  else {
    tempoPreparazione = 5 * (nPizze / 5);
    if ((nPizze % 5) != 0) tempoPreparazione += 5;
    return tempoPreparazione;
  }
}
// TODO
QTime& Comanda::getOrarioInizioPreparazione() const {
  QTime orario(getOraConsegna().addSecs(-getTempoPreparazione()));
  return orario;
}
const Contatto& Comanda::getCliente() const { return cliente; }

const QTime& Comanda::getOraConsegna() const { return oraConsegna; }

void Comanda::setOraConsegna(QTime _oraConsegna) { oraConsegna = _oraConsegna; }

void Comanda::sostituisciArticolo(Articolo* daSostituire, int qtaDS,
                                  Articolo* daInserire, unsigned int qtaDI) {
  if (daSostituire) {
    if (qtaDS < 0) {
      if (ordinazione[daSostituire] <= qtaDS * (-1))
        ordinazione.erase(daSostituire);
      else
        // TODO: Check logic
        ordinazione[daSostituire] += qtaDS;
    } else
      ordinazione[daSostituire] += qtaDS;
  }
  if (daInserire) ordinazione[daInserire] = qtaDI;
}
// sottocaso 1: aggiungere un nuovo articolo non presente in comanda
void Comanda::inserisciArticolo(Articolo* _daInserire, unsigned int _qtaDI) {
  sostituisciArticolo(nullptr, 0, _daInserire, _qtaDI);
}

// sottocaso 4: rimuovere un articolo presente in comanda
void Comanda::rimuoviArticolo(Articolo* _daSostituire) {
  ordinazione.erase(_daSostituire);
}

void Comanda::modificaContatto(string _nome, string _indirizzo, string _tel) {
  if (_nome != "") cliente.setNome(_nome);
  if (_indirizzo != "") cliente.setIndirizzo(_indirizzo);
  if (_tel != "") cliente.setTelefono(_tel);
}

void Comanda::modificaQuantita(Articolo* _daModificare, int _qta) {
  sostituisciArticolo(_daModificare, _qta, nullptr, 0);
}

void Comanda::setQuantita(Articolo* _daModificare, int _qta) {
  ordinazione[_daModificare] = _qta;
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
