#ifndef RISORSA_H
#define RISORSA_H

#include <Qdate>
#include <string>

using std::string;

// enum class permette di creare enum con scoping automatico
// possiamo quindi usare l'elemento "normale" in entrambi gli enum
enum class formatoPizza { normale, family, mezzo_metro, battuta };
enum class farina { normale, integrale, kamut, farro };
enum formatoBevanda { bottiglia, lattina };
enum capacitaBevanda { CL33, CL50, CL66, L1 };

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  Risorsa(string, bool);
  virtual ~Risorsa() = default;
  string& getNome() const;
  bool getDisponibilita() const;
  void setNome(const string&);
  void setDisponibilita(bool);

  // metodo di clonazione virtuale puro
  virtual Risorsa* clone() const = 0;
};

#endif
