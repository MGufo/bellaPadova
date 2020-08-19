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

const Lista<const Consumabile*>* Bevanda::getComposizione() const {
  Lista<const Consumabile*>* lista = new Lista<const Consumabile*>();
  lista->push_back(this);
  return lista;
}

void Bevanda::modifica(Risorsa* modificato){
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setPrezzoBase(dynamic_cast<Articolo*>(modificato)->getPrezzoBase());
  setQuantita(dynamic_cast<Consumabile*>(modificato)->getQuantita());
  setCosto(dynamic_cast<Consumabile*>(modificato)->getCosto());
  setDataAcquisto(dynamic_cast<Consumabile*>(modificato)->getDataAcquisto());
  setCapacita(dynamic_cast<Bevanda*>(modificato)->getCapacita());
}

void Bevanda::carica(const QJsonObject& bevandaJSON,
                     const std::unordered_map<uint, Risorsa*>* keymap){
  setID((*(bevandaJSON.constFind("ID"))).toInt());
  setNome((*(bevandaJSON.constFind("Nome"))).toString().toStdString());
  setDisponibilita((*(bevandaJSON.constFind("Disponibilita"))).toBool());
  setPrezzoBase((*(bevandaJSON.constFind("Prezzo"))).toDouble());
  setQuantita((*(bevandaJSON.constFind("Quantita"))).toInt());
  setCosto((*(bevandaJSON.constFind("Costo"))).toDouble());
  setDataAcquisto(
        QDate::fromString((*(bevandaJSON.constFind("Data Acquisto"))).toString()));
  setCapacita((*(bevandaJSON.constFind("Capacita"))).toDouble());
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
