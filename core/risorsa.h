#ifndef RISORSA_H
#define RISORSA_H

#include <QJsonArray>
#include <QJsonObject>
#include <iostream>
#include <string>
#include <unordered_map>

#include "utils.h"

using std::string;

class Risorsa {
 private:
  unsigned int ID;
  string nome;
  bool disponibilita;

 public:
  Risorsa();
  Risorsa(unsigned int, string, bool);
  virtual ~Risorsa() = default;

  /**
   * @brief: Ritorna l'ID (univoco) della risorsa di invocazione
   * @returns: unsigned int (ID dell'oggetto)
   */
  unsigned int getIdRisorsa() const;

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

  /**
   * @brief: Modifica l'ID dell'oggetto
   * @param: unsigned int (nuovo ID)
   */
  void setID(unsigned int);
  /**
   * @brief: Legge i dati di una risorsa da file JSON e li assegna ai campi
   * dati dell'oggetto di invocazione
   * @param: const QJsonObject& (file da cui leggere)
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>* = nullptr) = 0;

  /**
   * @brief: Serializza l'oggetto di invocazione in un file JSON
   * @param: bool (nuova disponibilità)
   */
  virtual void salva(QJsonObject&) const = 0;

  // metodo di clonazione virtuale puro
  virtual Risorsa* clone() const = 0;

  // metodo che consente la modifica delle risorse in modo polimorfo
  virtual void modifica(Risorsa*) = 0;
};

#endif
