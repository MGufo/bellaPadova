#include "contatto.h"

Contatto::Contatto(string _nome, string _indirizzo, string _telefono)
    : nome(_nome), indirizzo(_indirizzo), telefono(_telefono) {}

void Contatto::setNome(const string& n) { nome = n; }
void Contatto::setIndirizzo(const string& ind) { indirizzo = ind; }
void Contatto::setTelefono(const string& tel) { telefono = tel; }

const string Contatto::getNome() const { return nome; }
const string Contatto::getIndirizzo() const { return indirizzo; }
const string Contatto::getTelefono() const { return telefono; }

const Lista<const string>& Contatto::getContatto() const {
  Lista<const string>* contatti = new Lista<const string>();
  contatti->push_back(getNome());
  contatti->push_back(getIndirizzo());
  contatti->push_back(getTelefono());
  return *contatti;
}
