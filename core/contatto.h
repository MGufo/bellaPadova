#ifndef CONTATTO_H
#define CONTATTO_H
#include <string>

#include "qontainer.h"
using std::string;

class Contatto {
 private:
  string nome;
  string indirizzo;
  string telefono;

 public:
  Contatto(string, string, string);

  const string getNome() const;
  const string getIndirizzo() const;
  const string getTelefono() const;
  const Lista<const string>& getContatto() const;

  void setNome(const string&);
  void setIndirizzo(const string&);
  void setTelefono(const string&);
};

#endif
