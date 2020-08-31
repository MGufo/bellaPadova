#include "farina.h"

Farina::Farina() {}

Farina::Farina(unsigned int id, string _nome, bool _disponibilita,
               unsigned int _quantita, double _costo, QDate _dataAcquisto,
               bool _locale, string _tipoFarina)
    : Risorsa(id, _nome, _disponibilita),
      Ingrediente(id, _nome, _disponibilita, _quantita, _costo, _dataAcquisto,
                  _locale),
      tipoFarina(_tipoFarina) {}

const string& Farina::getTipoFarina() const { return tipoFarina; }

void Farina::setTipoFarina(const string& f) {
  if (f == "")
    throw new std::domain_error(
        "Errore: Il tipo della farina non può essere"
        " una stringa vuota.");
  else
    tipoFarina = f;
}

void Farina::modifica(Risorsa* modificato) {
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setQuantita(dynamic_cast<Consumabile*>(modificato)->getQuantita());
  setCosto(dynamic_cast<Consumabile*>(modificato)->getCosto());
  setDataAcquisto(dynamic_cast<Consumabile*>(modificato)->getDataAcquisto());
  setLocal(dynamic_cast<Ingrediente*>(modificato)->isLocal());
  setTipoFarina(dynamic_cast<Farina*>(modificato)->getTipoFarina());
}

Farina* Farina::clone() const { return new Farina(*this); }

void Farina::carica(const QJsonObject& farinaJSON,
                    const std::unordered_map<uint, Risorsa*>*) {
  Ingrediente::carica(farinaJSON);
  setTipoFarina((*(farinaJSON.constFind("tFarina"))).toString().toStdString());
}

void Farina::salva(QJsonObject& farinaJSON) const {
  Ingrediente::salva(farinaJSON);
  farinaJSON.insert("tFarina", QString::fromStdString(tipoFarina));
  // Tipo
  farinaJSON.insert("tipo", "farina");
}
