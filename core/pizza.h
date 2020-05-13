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

 public:
  // Costruttore non usiamo valori di default perchè vengono tutti sempre
  // passati per costruire l'oggetto
  Pizza(string nome, bool disponibilita, double prezzo);

  // Costruttore di copia,
  Pizza(const Pizza&);

  // Distruttore
  // ~Pizza();

  // getter
  const Lista<Ingrediente*>& getIngredienti() const;
  Farina* getFarina() const;
  double getExtra() const;

  // setter
  void setFarina(const Farina*);
  void addIngrediente(Ingrediente*);
  void addIngredienti(const Lista<Ingrediente*>&);
  void removeIngrediente(Ingrediente*);
  
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
  virtual const Lista<const Consumabile*>* getComposizione() const;
};
#endif
