#ifndef RISORSA_H
#define RISORSA_H
#include <iostream>
#include <string>

using std::string;

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  Risorsa(string, bool);
  virtual ~Risorsa() = default;
  /**
   * @brief: Ritorna il nome dell'oggetto
   * @return: string (nome dell'oggetto)
   */
  string getNome() const;

  /**
   * @brief: Ritorna la disponibilità dell'oggetto
   * @return: bool (disponibilità dell'oggetto)
   */
  bool getDisponibilita() const;

  /**
   * @brief: Modifica il nome dell'oggetto
   * @param: const string& (nuovo nome)
   */
  void setNome(const string&);

  /**
   * @brief: Modifica la disponibilità dell'oggetto
   * @param: bool (nuova disponibilità)
   */
  void setDisponibilita(bool);

  // metodo di clonazione virtuale puro
  virtual Risorsa* clone() const = 0;
};

#endif
