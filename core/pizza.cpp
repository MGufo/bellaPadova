#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;
// Costruttore di default, costruisce una pizza la cui lista di ingredienti
// contiene un solo ingrediente (la farina)
Pizza::Pizza(string nome, bool disponibilita, double prezzo,
             Lista<Ingrediente*>* ingr)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      ingredienti(new Lista<Ingrediente*>(*ingr)) {}

// Costruttore di copia;
// Copia profonda implementata tramite metodo copy presente nel container
Pizza::Pizza(const Pizza& p)
    : Risorsa(p),
      Articolo(p),
      ingredienti(new Lista<Ingrediente*>(p.getIngredienti())) {}

// Distruttore;
// Distruzione profonda implementata tramite metodo destroy presente nel
// container Pizza::~Pizza()

const Lista<Ingrediente*>& Pizza::getIngredienti() const {
  if (!ingredienti) return *(new Lista<Ingrediente*>());
  return *ingredienti;
}

/* Non si controlla che la lista di ingredienti sia vuota perchè nella
costruzione di una nuova pizza al costruttore è garantito il passaggio di una
lista di ingredienti non vuota */
string Pizza::getTipoFarina() const {
  return static_cast<Farina*>(**ingredienti)->getTipoFarina();
}

// aggiorna la tipologia di farina presente nella lista ingredienti della pizza
void Pizza::setTipoFarina(const string& tf) {
  static_cast<Farina*>(**ingredienti)->setTipoFarina(tf);
}

/*
Se l'ingrediente da inserire è presente nella lista di consumabili
di inventario ed è disponibile, ne si costruisce una copia e lo si aggiunge
alla lista ingredienti della pizza , altrimenti si ritorna un'eccezione congrua
al tipo di errore */
void addIngrediente(const Ingrediente& i) {}

Pizza* Pizza::clone() const { return new Pizza(*this); }

// Ritorna il prezzo di vendita della pizza di invocazione.
double Pizza::getPrezzo() const {
  int somma = 0;
  for (auto it = ingredienti->begin(); it != ingredienti->end(); ++it) {
    if ((*it)->isLocal()) somma += extra;
  }
  return getPrezzoBase() + somma;
}
