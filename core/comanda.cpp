#include "comanda.h"
#include "pizzeria.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda() {}

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
  comandaJSON->insert("ID", static_cast<int>(ID));
  QJsonObject* contattoJSON = new QJsonObject();
  cliente.salva(contattoJSON);
  comandaJSON->insert("cliente", *contattoJSON);
  comandaJSON->insert("oraConsegna", oraConsegna.toString());
  comandaJSON->insert("dataConsegna", dataConsegna.toString());
  QJsonObject* ordinazioneJSON = new QJsonObject();
  for(auto it = ordinazione.cbegin(); it != ordinazione.cend(); ++it)
    ordinazioneJSON->insert(
          QString::fromStdString(std::to_string((*it).first->getIdRisorsa())),
          static_cast<int>((*it).second));
  comandaJSON->insert("ordinazione", *ordinazioneJSON);
  delete ordinazioneJSON;
  delete contattoJSON;
  delete comandaJSON;
}

void Comanda::carica(const QJsonObject* comandaJSON){
  ID = (*(comandaJSON->find("ID"))).toInt();
  cliente.carica((*(comandaJSON->find("cliente"))).toObject());
  oraConsegna =
      QTime::fromString((*(comandaJSON->find("oraConsegna"))).toString());
  QJsonObject* ordinazioneJSON =
      new QJsonObject((*(comandaJSON->find("ordinazione"))).toObject());
  for(auto it = ordinazioneJSON->constBegin();
      it != ordinazioneJSON->constEnd(); ++it){
  }
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
