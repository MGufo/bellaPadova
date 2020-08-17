#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>
#include <QDate>
#include <unordered_map>

#include "bevanda.h"
#include "contatto.h"
#include "farina.h"
#include "pizza.h"

class Pizzeria;

using std::unordered_map;

class Comanda {
 private:
  unsigned int ID;
  Contatto cliente;
  QTime oraConsegna;
  QDate dataConsegna;
  unordered_map<Articolo*, unsigned int> ordinazione;
  double totale;

 public:
  Comanda();
  Comanda(unsigned int, Contatto, QTime, QDate,
          unordered_map<Articolo*, unsigned int> =
              unordered_map<Articolo*, unsigned int>(), double = 0);

  unsigned int getIdComanda() const;

  /**
   * @brief: Ritorna l'orario di consegna di una comanda
   * @return: unordered_map& (coppie (Articolo, quantità) )
   * @note: Elementi accessibili tramite operatore at()
   */
  const unordered_map<Articolo*, unsigned int>& getOrdinazione() const;

  /**
   * @brief: Ritorna il tempo di preparazione di una comanda
   * @param: unsigned short (capacità del forno)
   * @return: int (minuti per la preparazione)
   */
  int getTempoPreparazione(unsigned short) const;

  /**
   * @brief: Ritorna l'orario stimato in cui la pizzeria deve inizare la
   * preparazione della comanda.
   * @return: QTime& (orario inizio preparazione)
   */
  QTime& getOrarioInizioPreparazione(unsigned short capForno) const;

  /**
   * @brief: Ritorna il cliente associato a una comanda
   * @return: Contatto& (Cliente)
   */
  const Contatto& getCliente() const;

  /**
   * @brief: Ritorna l'orario di consegna di una comanda
   * @return: QTime& (orario di consegna)
   */
  const QTime& getOraConsegna() const;

  const QDate& getDataConsegna() const;

  double getTotale() const;

  void setIdComanda(unsigned int);

  void setCliente(const Contatto&);

  /**
   * @brief: Modifica l'orario di consegna di una comanda
   * @param: QTime (Nuovo orario di consegna)
   */
  void setOraConsegna(QTime);

  void setDataConsegna(const QDate&);

  void setTotale(double);

  /**
   * @brief: Aggiunge un articolo alla comanda o aumenta la sua quantità
   * @param: Articolo* (Articolo da aggiungere)
   * @param: unsigned int (Quantità articolo da aggiungere)
   */
  void inserisciArticolo(Articolo*, unsigned int = 1);

  void modificaArticolo(Articolo*);
  /**
   * @brief: Modifica la quantità di un articolo
   * @param: Articolo* (Articolo da modificare)
   * @param: unsigned int (nuova quantità)
   */
  void modificaQuantitaArticolo(Articolo*, unsigned int);

  /**
   * @brief: Rimuove un articolo presente nella comanda
   * @param: Articolo* (Articolo da rimuovere)
   */
  void rimuoviArticolo(Articolo*);

  /**
   * @brief: Modifica dati di un cliente associato a una comanda
   * @param: string (nuovo nome)
   * @param: string (nuovo indirizzo)
   * @param: string (nuovo telefono)
   */
  void modificaContatto(const Contatto*);

  /**
   * @brief: Serializza la comanda d'invocazione in JSON
   *
   */
  void salva(QJsonObject*) const;

  bool operator<(const Comanda&) const;

  bool operator<=(const Comanda&) const;

  bool operator>(const Comanda&) const;

  bool operator>=(const Comanda&) const;

  bool operator==(const Comanda&) const;

  bool operator!=(const Comanda&) const;
};

#endif
