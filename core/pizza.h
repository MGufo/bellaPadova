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

  // Costruttore di copia,
  Pizza(const Pizza&);

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
   * @note: PRE: La lista non deve contenere oggetti con tipo 'Farina'
   */
  void aggiungiIngredienti(const Lista<Ingrediente*>&);

  void rimuoviIngredienti(const Lista<Ingrediente*>&);

  void setExtra(double);

  // implementazione metodo di clonazione (classe diventa concreta)
  // metodo da utilizzare per aggiungere una pizza del menu tra gli articoli di
  // una comanda
  Pizza* clone() const;

  virtual double getPrezzo() const;

  /**
   * @brief: Ritorna la composizione (la lista di consumabili) di una pizza.
   * @note: Usata nella classe GestoreRisorse per impostare correttamente la
   * disponibilità della pizza.
   */
  virtual const Lista<Consumabile*>* getComposizione() const;

  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>*);

  virtual void salva(QJsonObject &) const;
};
#endif
