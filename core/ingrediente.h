#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "consumabile.h"

class Ingrediente : public Consumabile {
 private:
  bool locale;

 public:
  Ingrediente();
  Ingrediente(unsigned int, string, bool, unsigned int, double,
              QDate = QDate::currentDate(), bool locale = false);

  /**
   * @brief: Controllo provenienza ingrediente
   * @return: TRUE se l'ingrediente è locale, FALSE altrimenti
   */
  bool isLocal() const;

  /**
   * @brief: Imposta la provenienza di un ingrediente
   * @param: bool (TRUE se l'ingrediente è locale, FALSE altrimenti)
   */
  void setLocal(bool);

  /**
   * @brief: Ritorna la spesa sostenuta dalla pizzeria per acquistare
   * l'ingrediente.
   * @return: double (spesa)
   * @note: Se l'ingrediente è locale viene aggiunto un extra da donare
   * all'associazione "Amici dello Gnocco"
   */
  double getSpesa() const;

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
  Ingrediente* clone() const;

  /**
   * @brief: Effettua la deserializzazione dell'oggetto, assegnando ai campi
   * privati i valori corrispondenti contenuti nell'oggetto JSON.
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>* = nullptr);

  /**
   * @brief: Effettua la serializzazione dell'oggetto, salvando il contenuto dei
   * campi privati nell'oggetto JSON ricevuto come parametro.
   */
  virtual void salva(QJsonObject&) const;
};

#endif
