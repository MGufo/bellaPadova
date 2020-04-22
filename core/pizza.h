#ifndef PIZZA_H
#define PIZZA_H
#include "articolo.h"
#include "qontainer.h"
#include "ingrediente.h"
#include "farina.h"

class Pizza : public Articolo {
 private:
  Lista<Ingrediente*>* ingredienti;
  static double extra;

 public:
  // Costruttore non usiamo valori di default perchè vengono tutti sempre
  // passati per costruire l'oggetto
  Pizza(string nome, bool disponibilita, double prezzo,
        Lista<Ingrediente*>* ingr);

  // Costruttore di copia,
  Pizza(const Pizza&);

  // Distruttore
  //~Pizza();

  // getter
  const Lista<Ingrediente*>& getIngredienti() const;
  Farina* getFarina() const;

  // setter
  void setFarina(Farina*);
  void addIngrediente(Ingrediente*);
  void removeIngrediente(Ingrediente*);

  // implementazione metodo di clonazione (classe diventa concreta)
  // metodo da utilizzare per aggiungere una pizza del menu tra gli articoli di
  // una comanda
  Pizza* clone() const;
  double getPrezzo() const;
};
#endif
