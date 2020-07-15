#include "comanda.h"

#include "pizzeria.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(unsigned int _id, Contatto _cliente, QTime _oraConsegna, QDate _dataConsegna,
                 unordered_map<Articolo*, unsigned int> _ordinazione)
    : ID(_id), cliente(_cliente), oraConsegna(_oraConsegna), dataConsegna(_dataConsegna), ordinazione(_ordinazione) {}

unsigned int Comanda::getIdComanda() const{
    return ID;
}

const unordered_map<Articolo*, unsigned int>& Comanda::getOrdinazione() const {
  return ordinazione;
}

int Comanda::getTempoPreparazione(unsigned short capForno) const {
  unsigned short nPizze = 0;
  int tempoPreparazione = 5;
  for (auto it = ordinazione.begin(); it != ordinazione.end(); ++it)
    if (dynamic_cast<Pizza*>((*it).first)) nPizze += (*it).second;
  if (nPizze <= capForno)
    return tempoPreparazione;
  else {
    tempoPreparazione = 5 * (nPizze / capForno);
    if ((nPizze % 5) != 0) tempoPreparazione += 5;
    return tempoPreparazione;
  }
}

QTime& Comanda::getOrarioInizioPreparazione(unsigned short capForno) const {
  QTime* orario =
      new QTime(getOraConsegna().addSecs(getTempoPreparazione(capForno) * 60));
  return *orario;
}
const Contatto& Comanda::getCliente() const { return cliente; }

const QTime& Comanda::getOraConsegna() const { return oraConsegna; }

const QDate &Comanda::getDataConsegna() const{ return dataConsegna; }

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

void Comanda::salva(QJsonObject* comandaJSON) const {
  comandaJSON->insert("ID", QJsonValue(static_cast<int>(ID)));
  QJsonObject* contattoJSON = new QJsonObject();
  cliente.salva(contattoJSON);
  comandaJSON->insert("cliente", QJsonValue(*contattoJSON));
  comandaJSON->insert("oraConsegna", QJsonValue(oraConsegna.toString()));
  comandaJSON->insert("dataConsegna", QJsonValue(dataConsegna.toString()));
  // serializzazione mappa ordine
  QJsonObject* ordinazioneJSON = new QJsonObject();
  for(auto it = ordinazione.cbegin(); it != ordinazione.cend(); ++it)
    ordinazioneJSON->insert(QString::fromStdString(((*it).first)->getNome()),
                            QJsonValue(static_cast<int>((*it).second)));
  comandaJSON->insert("ordinazione", QJsonValue(*ordinazioneJSON));
  delete ordinazioneJSON;
  delete contattoJSON;
  delete comandaJSON;
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
