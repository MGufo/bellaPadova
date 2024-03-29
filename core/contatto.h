#ifndef CONTATTO_H
#define CONTATTO_H
#include <QJsonObject>
#include <string>

#include "qontainer.h"
using std::string;

class Contatto {
 private:
  string nome;
  string indirizzo;
  /**
   * @note: Tipo string perché il tipo int troncherebbe lo '0' iniziale
   */
  string telefono;

 public:
  Contatto(string = "", string = "", string = "");
  Contatto(const Contatto&);
  /**
   * @brief: Ritorna il nome del cliente
   * @return: string (nome)
   */
  const string getNome() const;

  /**
   * @brief: Ritorna l'indirizzo del cliente
   * @return: string (indirizzo)
   */
  const string getIndirizzo() const;

  /**
   * @brief: Ritorna il num. di telefono del cliente
   * @return: string (num. di telefono)
   */
  const string getTelefono() const;

  /**
   * @brief: Ritorna tutte le informazioni del cliente come lista di stringhe
   * @return: List<const string>& (nome, indirizzo, telefono)
   */
  const Lista<string>& getContatto() const;

  /**
   * @brief: Modifica il nome del cliente
   * @param: string& (nuovo nome)
   */
  void setNome(const string&);

  /**
   * @brief: Modifica l'indirizzo del cliente
   * @param: string& (nuovo indirizzo)
   */
  void setIndirizzo(const string&);

  /**
   * @brief: Modifica il num. di telefono del cliente
   * @param: string& (nuovo num. telefono)
   */
  void setTelefono(const string&);

  /**
   * @brief: Effettua la serializzazione dell'oggetto, salvando il contenuto dei
   * campi privati nell'oggetto JSON ricevuto come parametro.
   */
  void salva(QJsonObject*) const;

  /**
   * @brief: Effettua la deserializzazione dell'oggetto, assegnando ai campi
   * privati i valori corrispondenti contenuti nell'oggetto JSON.
   */
  void carica(QJsonObject);
};

#endif
