#include "ingrediente.h"

Ingrediente::Ingrediente() {}

Ingrediente::Ingrediente(unsigned int id, string _nome, bool _disponibilita,
                         unsigned int _quantita, double _costo,
                         QDate _dataAcquisto, bool _locale)
    : Risorsa(id, _nome, _disponibilita),
      Consumabile(id, _nome, _disponibilita, _quantita, _costo, _dataAcquisto),
      locale(_locale) {}

Ingrediente* Ingrediente::clone() const { return new Ingrediente(*this); }


bool Ingrediente::isLocal() const { return locale; }

void Ingrediente::setLocal(bool _locale) { locale = _locale; }

double Ingrediente::getSpesa() const {
    return getQuantita() * getCosto() + 1 * isLocal();
}

void Ingrediente::modifica(Consumabile* modificato){
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setQuantita(modificato->getQuantita());
  setCosto(modificato->getCosto());
  setDataAcquisto(modificato->getDataAcquisto());
  setLocal(dynamic_cast<Ingrediente*>(modificato)->isLocal());
}

void Ingrediente::carica(const QJsonObject & ingredienteJSON,
                         const std::unordered_map<uint, Risorsa*>* keymap){


}

void Ingrediente::salva(QJsonObject& ingredienteJSON) const{
  // ID
  ingredienteJSON.insert("ID", static_cast<int>(getIdRisorsa()));
  // Nome
  ingredienteJSON.insert("Nome", QString::fromStdString(getNome()));
  // Disponibilita
  ingredienteJSON.insert("Disponibilità", getDisponibilita());
  // Quantita
  ingredienteJSON.insert("Quantità", static_cast<int>(getQuantita()));
  // Costo
  ingredienteJSON.insert("Costo", getCosto());
  // Data Acquisto
  ingredienteJSON.insert("dataAcquisto", getDataAcquisto().toString());
  // Locale
  ingredienteJSON.insert("Locale", locale);
}
