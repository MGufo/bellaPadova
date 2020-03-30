#ifndef PIZZA.H
#define PIZZA .H

#include "articolo.h"
#include "container.h"

class Pizza : public Articolo {
 private:
  formatoPizza tipoFormato;
  farina tipoFarina;
  Vettore<string>* ingredienti;

 public:
  // Costruttore di default, costruisce una pizza a impasto normale senza
  // ingredienti
  Pizza(string nome = "focaccia", bool disponibilita = true, double prezzo = 0,
        formatoPizza fo = formatoPizza::normale, farina fa = farina::normale,
        Vettore<string>* ingr = nullptr);
  // Costruttore di copia
  Pizza(const Pizza&);
  // Distruttore
  ~Pizza();
  // getter
  formatoPizza getTipoFormato() const;
  const Vettore<string>& getIngredienti() const;
  farina getTipoFarina() const;

  // setter
  void setTipoFormato(const unsigned int);
  void setTipoFarina(const unsigned int);
  void addIngrediente(const string&);

  // implementazione metodo di clonazione (classe diventa concreta)
  Pizza* clone() const;
};
#endif