#ifndef FARINA_H
#define FARINA_H
#include "ingrediente.h"

/**
 * @brief: Classe che rappresenta l'ingrediente 'farina', usato come ingrediente
 * base di ogni pizza.
 * @note: Modellare la farina come classe permette maggiore estensibilità
 * (aggiunta/rimozione di farine) rispetto ad un enumerazione.
 */
class Farina : public Ingrediente {
 private:
  string tipoFarina;

 public:
  Farina();
  Farina(unsigned int, string = "farina 1kg", bool = true, unsigned int = 1,
         double = 3, QDate = QDate::currentDate(), bool = true,
         string = "tipo 00");

  /**
   * @brief: Ritorna il tipo di una farina (00, integrale, ecc)
   * @return: string& (tipo di farina)
   */
  const string& getTipoFarina() const;

  /**
   * @brief: Modifica il tipo farina ad una farina esistente
   * @param: string& (nuovo tipo farina)
   */
  void setTipoFarina(const string&);

  /**
   * @brief: Metodo polimorfo di clonazione dell'oggetto
   * @returns: Farina* (puntatore a un nuovo oggetto creato di copia a partire
   * dall'oggetto di invocazione)
   */
  virtual void modifica(Risorsa*);

  /**
   * @brief: Metodo polimorfo di clonazione dell'oggetto
   * @returns: Farina* (puntatore a un nuovo oggetto creato di copia a partire
   * dall'oggetto di invocazione)
   */
  Farina* clone() const;

  /**
   * @brief: Effettua la deserializzazione dell'oggetto, assegnando ai campi
   * privati i valori corrispondenti contenuti nell'oggetto JSON.
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>*);

  /**
   * @brief: Effettua la serializzazione dell'oggetto, salvando il contenuto dei
   * campi privati nell'oggetto JSON ricevuto come parametro.
   */
  virtual void salva(QJsonObject&) const;
};

#endif
