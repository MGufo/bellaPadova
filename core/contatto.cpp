#include "contatto.h"

void Contatto::setNome(const string& n) { nome = n; };
void Contatto::setIndirizzo(const string& ind) { indirizzo = ind; };
void Contatto::setTelefono(const string& tel) { telefono = tel; };

string Contatto::getNome() const { return nome; };
string Contatto::getIndirizzo() const { return indirizzo; };
string Contatto::getTelefono() const { return telefono; };