#ifndef RISORSA_H
#define RISORSA_H
#include <string>
#include <iostream>

using std::string;

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  Risorsa(string, bool);
  virtual ~Risorsa() = default;
  string getNome() const;
  bool getDisponibilita() const;
  void setNome(const string&);
  void setDisponibilita(bool);

  // metodo di clonazione virtuale puro
  virtual Risorsa* clone() const = 0;
};

#endif
