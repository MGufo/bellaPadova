#include "pizza.h"

double Pizza::extra = 0.50;
// Costruttore di default, costruisce una pizza a impasto normale senza
// ingredienti
Pizza::Pizza(string nome, bool disponibilita, double prezzo,
             Lista<Ingrediente*>* ingr)
    : Articolo(nome, disponibilita, prezzo),
      ingredienti(new Lista<Ingrediente*>(ingr)) {}

// Costruttore di copia
// TODO: Implementare copia profonda
// Pizza::Pizza(const Pizza& p){}

// Distruttore
// TODO: Implementare distruttore profondo
// Pizza::~Pizza();

const Lista<Ingrediente*>& Pizza::getIngredienti() const {
  if (!ingredienti) return new Lista<Ingrediente*>();
  return *ingredienti;
}

string Pizza::getTipoFarina() const {}

void Pizza::setTipoFarina(const string& tf) {}
/* controlla se l'ingrediente da inserire è presente nella lista di consumabili
di inventario, se c'è lo costruisce di copia e lo aggiunge alla lista
ingredienti
di pizza , altrimenti ritorna un'eccezione congrua al tipo di errore */
void addIngrediente(const string& i) {}

Pizza* Pizza::clone() const { return new Pizza(*this); }

double Pizza::getPrezzo() const {
  int somma = 0;
  for (auto it = ingredienti->begin(); it != ingredienti->end(); ++it) {
    if (*it.isLocal()) somma += extra;
  }
  return prezzo + somma;
}
