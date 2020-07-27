#include "bevanda.h"

Bevanda::Bevanda() {}

Bevanda::Bevanda(unsigned int id, string nome, bool disponibilita, double prezzo,
                 unsigned int qta, double costo, QDate dataAcquisto,
                 float capacitaBevanda)
    : Risorsa(id, nome, disponibilita),
      Articolo(id, nome, disponibilita, prezzo),
      Consumabile(id, nome, disponibilita, qta, costo, dataAcquisto),
      capacita(capacitaBevanda) {}

double Bevanda::getSpesa() const { return getQuantita() * getCosto(); }

double Bevanda::getCapacita() const { return capacita; }

double Bevanda::getPlasticTax() const { return plasticTax; }

void Bevanda::setPlasticTax(double pt) { plasticTax = pt; }

void Bevanda::setCapacita(float _capacita) { capacita = _capacita; }

double Bevanda::plasticTax = 0.5;

const Lista<Consumabile*>* Bevanda::getComposizione() const {
  Lista<Consumabile*>* lista = new Lista<Consumabile*>();
  lista->push_back(const_cast<Bevanda*>(this));
  return lista;
}

void Bevanda::modifica(Consumabile* modificato){
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setPrezzoBase(dynamic_cast<Articolo*>(modificato)->getPrezzoBase());
  setQuantita(modificato->getQuantita());
  setCosto(modificato->getCosto());
  setDataAcquisto(modificato->getDataAcquisto());
  setCapacita(dynamic_cast<Bevanda*>(modificato)->getCapacita());
}

void Bevanda::carica(const QJsonObject& bevandaJSON,
                     const std::unordered_map<uint, Risorsa*>* keymap){
  setID((*(bevandaJSON.find("ID"))).toInt());
  setNome((*(bevandaJSON.find("Nome"))).toString().toStdString());
  setDisponibilita((*(bevandaJSON.find("Disponibilita"))).toBool());
  setPrezzoBase((*(bevandaJSON.find("Prezzo"))).toDouble());
  setQuantita((*(bevandaJSON.find("Quantita"))).toInt());
  setCosto((*(bevandaJSON.find("Costo"))).toDouble());
  setDataAcquisto(
        QDate::fromString((*(bevandaJSON.find("Data Acquisto"))).toString()));
  setCapacita((*(bevandaJSON.find("Capacita"))).toDouble());
}

void Bevanda::salva(QJsonObject & bevandaJSON) const{
  // ID
  bevandaJSON.insert("ID", static_cast<int>(getIdRisorsa()));
  // Nome
  bevandaJSON.insert("Nome", QString::fromStdString(getNome()));
  // Disponibilita
  bevandaJSON.insert("Disponibilità", getDisponibilita());
  // Prezzo
  bevandaJSON.insert("Prezzo", getPrezzo());
  // Quantità
  bevandaJSON.insert("Quantita", static_cast<int>(getQuantita()));
  // Costo
  bevandaJSON.insert("Costo", getCosto());
  // Data Acquisto
  bevandaJSON.insert("Data Acquisto", getDataAcquisto().toString());
  // Capacità
  bevandaJSON.insert("Capacita", capacita);
}
