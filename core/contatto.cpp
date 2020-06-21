#include "contatto.h"

Contatto::Contatto(string _nome, string _indirizzo, string _telefono)
    : nome(_nome), indirizzo(_indirizzo), telefono(_telefono) {}

Contatto::Contatto(const Contatto& c)
    : nome(c.nome), indirizzo(c.indirizzo), telefono(c.telefono) {
  if (indirizzo.empty())
    throw new std::invalid_argument("Errore: indirizzo inserito non valido.");
}

// TODO: Add exception type
void Contatto::setNome(const string& n) { nome = n; }
void Contatto::setIndirizzo(const string& ind) {
  if (ind.empty())
    throw new std::invalid_argument("Errore: indirizzo inserito non valido.");
  indirizzo = ind;
}
void Contatto::setTelefono(const string& tel) { telefono = tel; }

const string Contatto::getNome() const { return nome; }
const string Contatto::getIndirizzo() const { return indirizzo; }
const string Contatto::getTelefono() const { return telefono; }

const Lista<string>& Contatto::getContatto() const {
  Lista<string>* contatti = new Lista<string>();
  contatti->push_back(getNome());
  contatti->push_back(getIndirizzo());
  contatti->push_back(getTelefono());
  return *contatti;
}
