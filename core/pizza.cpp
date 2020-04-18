#include "pizza.h"
#include "farina.h"

double Pizza::extra = 0.50;
// Costruttore di default, costruisce una pizza a impasto normale senza
// ingredienti
Pizza::Pizza(string nome, bool disponibilita, double prezzo,
             Lista<Ingrediente*>* ingr)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      ingredienti(new Lista<Ingrediente*>(*ingr)) {}

// Costruttore di copia
// Copia profonda, metodo copy presente nel container
Pizza::Pizza(const Pizza& p) : Risorsa(p), Articolo(p), ingredienti(new Lista<Ingrediente*>(p.getIngredienti())){}

// Distruttore
// Distruttore profondo, metodo destroy presente nel container
// Pizza::~Pizza()

const Lista<Ingrediente*>& Pizza::getIngredienti() const {
  if (!ingredienti) return *(new Lista<Ingrediente*>());
    return *ingredienti;
}

/* Non si controlla che la lista sia vuota perchè la costruzione di una nuova pizza
garantisce che tale lista non sia vuota */

string Pizza::getTipoFarina() const { return static_cast<Farina*>(**ingredienti)->getTipoFarina();}

void Pizza::setTipoFarina(const string& tf) { static_cast<Farina*>(**ingredienti)->setTipoFarina(tf); }
/* controlla se l'ingrediente da inserire è presente nella lista di consumabili
di inventario, se c'è lo costruisce di copia e lo aggiunge alla lista
ingredienti
di pizza , altrimenti ritorna un'eccezione congrua al tipo di errore */
void addIngrediente(const string& i) {}

Pizza* Pizza::clone() const { return new Pizza(*this); }

double Pizza::getPrezzo() const {
  int somma = 0;
  for (auto it = ingredienti->begin(); it != ingredienti->end(); ++it) {
    if ((*it)->isLocal()) somma += extra;
  }
  return getPrezzoBase() + somma;
}
