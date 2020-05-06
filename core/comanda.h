#ifndef COMANDA_H
#define COMANDA_H

#include <QTime>
#include <unordered_map>

#include "bevanda.h"
#include "contatto.h"
#include "farina.h"
#include "pizza.h"

class Pizzeria;

using std::unordered_map;

class Comanda {
 private:
  Contatto cliente;
  QTime oraConsegna;
  unordered_map<Articolo*, unsigned int> ordinazione;

 public:
  Comanda(Contatto, QTime,
          unordered_map<Articolo*, unsigned int> =
              unordered_map<Articolo*, unsigned int>());
  //  Comanda(const Comanda&);

  /**
   * @brief: Ritorna l'orario di consegna di una comanda
   * @return: unordered_map& (coppie (Articolo, quantità) )
   * @note: Elementi accessibili tramite operatore at()
   */
  const unordered_map<Articolo*, unsigned int>& getOrdinazione() const;

  /**
   * @brief: Ritorna il tempo di preparazione di una comanda
   * @return: int (minuti per la preparazione)
   */
  int getTempoPreparazione() const;

  /**
   * @brief: Ritorna l'orario stimato in cui la pizzeria deve inizare la
   * preparazione della comanda.
   * @return: QTime& (orario inizio preparazione)
   */
  QTime& getOrarioInizioPreparazione() const;

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

  /**
   * @brief: Modifica l'orario di consegna di una comanda
   * @param: QTime (Nuovo orario di consegna)
   */
  void setOraConsegna(QTime);

  /**
   * @brief: Aggiunge un articolo alla comanda o aumenta la sua quantità
   * @param: Articolo* (Articolo da aggiungere/modificare)
   * @param: int (Quantità articolo da aggiungere/modificare)
   */
  void inserisciArticolo(Articolo*, unsigned int);

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
  void modificaContatto(string = "", string = "", string = "");

  bool operator<(const Comanda&) const;

  bool operator<=(const Comanda&) const;

  bool operator>(const Comanda&) const;

  bool operator>=(const Comanda&) const;

  bool operator==(const Comanda&) const;

  bool operator!=(const Comanda&) const;
};

#endif
