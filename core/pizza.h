#ifndef PIZZA_H
#define PIZZA_H

#include "articolo.h"
#include "farina.h"
#include "ingrediente.h"
#include "qontainer.h"

class Pizza : public Articolo {
 private:
  Lista<Ingrediente*> ingredienti;
  static double extra;
  bool checkIngrediente(const Ingrediente*) const;
  void addIngrediente(Ingrediente*);
  void removeIngrediente(Ingrediente*);

 public:
  Pizza();

  Pizza(unsigned int, string nome, bool disponibilita, double prezzo);

  // getter
  const Lista<Ingrediente*>& getIngredienti() const;
  Farina* getFarina() const;
  double getExtra() const;

  /**
   * @brief: Cambia la farina alla pizza di invocazione
   * @param: const Farina* (nuova farina)
   */
  void setFarina(Farina*);

  /**
   * @brief: Aggiunge uno o più ingredienti alla pizza di invocazione.
   * @param: const Lista<Ingrediente*>& (lista di ingredienti da aggiungere)
   * @throw: std::domain_error se l'ingrediente è già presente o è una Farina
   * @note: La lista non deve contenere oggetti con tipo 'Farina'
   */
  void aggiungiIngredienti(const Lista<Ingrediente*>&);

  /**
   * @brief: Rimuove uno o più ingredienti dalla pizza di invocazione.
   * @param: const Lista<Ingrediente*>& (lista di ingredienti da rimuovere)
   * @throw: std::domain_error se l'ingrediente non è presente o è una Farina
   * @note: La lista non deve contenere oggetti con tipo 'Farina'
   */
  void rimuoviIngredienti(const Lista<Ingrediente*>&);

  void setExtra(double);

  Pizza* clone() const;

  virtual double getPrezzo() const;

  /**
   * @brief: Ritorna la composizione (la lista di consumabili) di una pizza.
   * @note: Usata nella classe GestoreRisorse per impostare correttamente la
   * disponibilità della pizza.
   */
  virtual const Lista<const Consumabile*>* getComposizione() const;

  /**
   * @brief: Metodo polimorfo di modifica dell'oggetto
   * @param: Risorsa* (copia temporanea dell'oggetto da modificare contenente i
   * nuovi valori dei campi dati)
   */
  virtual void modifica(Risorsa*);

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
