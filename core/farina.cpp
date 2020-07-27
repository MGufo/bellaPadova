#include "farina.h"

Farina::Farina() {}

Farina::Farina(unsigned int id, string _nome, bool _disponibilita, unsigned int _quantita,
               double _costo, QDate _dataAcquisto, bool _locale,
               string _tipoFarina)
    : Risorsa(id, _nome, _disponibilita),
      Ingrediente(id, _nome, _disponibilita, _quantita, _costo, _dataAcquisto,
                  _locale),
      tipoFarina(_tipoFarina) {}

const string& Farina::getTipoFarina() const { return tipoFarina; }

void Farina::setTipoFarina(const string& f) { tipoFarina = f; }

void Farina::modifica(Consumabile* modificato){
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setQuantita(modificato->getQuantita());
  setCosto(modificato->getCosto());
  setDataAcquisto(modificato->getDataAcquisto());
  setLocal(dynamic_cast<Ingrediente*>(modificato)->isLocal());
  setTipoFarina(dynamic_cast<Farina*>(modificato)->getTipoFarina());
}

Farina* Farina::clone() const { return new Farina(*this); }

void Farina::carica(const QJsonObject & farinaJSON,
                    const std::unordered_map<uint, Risorsa*>* keymap){

}

void Farina::salva(QJsonObject & farinaJSON) const{
  // ID
  farinaJSON.insert("ID", static_cast<int>(getIdRisorsa()));
  // Nome
  farinaJSON.insert("Nome", QString::fromStdString(getNome()));
  // Disponibilita
  farinaJSON.insert("Disponibilità", getDisponibilita());
  // Quantita
  farinaJSON.insert("Quantità", static_cast<int>(getQuantita()));
  // Costo
  farinaJSON.insert("Costo", getCosto());
  // Data Acquisto
  farinaJSON.insert("dataAcquisto", getDataAcquisto().toString());
  // Locale
  farinaJSON.insert("Locale", isLocal());
  // Tipo
  farinaJSON.insert("Locale", QString::fromStdString(tipoFarina));
}
