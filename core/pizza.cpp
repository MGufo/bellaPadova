#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;
// Costruttore di default, costruisce una pizza la cui lista di ingredienti
// contiene un solo ingrediente (la farina)
Pizza::Pizza(string nome, bool disponibilita, double prezzo)
    : Risorsa(nome, disponibilita),
      Articolo(nome, disponibilita, prezzo),
      ingredienti(Lista<Ingrediente*>()) {}

// Costruttore di copia;
// Copia profonda implementata tramite metodo copy presente nel container
Pizza::Pizza(const Pizza& p)
    : Risorsa(p), Articolo(p), ingredienti(p.getIngredienti()) {}

// Distruttore;
// Distruzione profonda implementata tramite metodo destroy presente nel
// container
// Pizza::~Pizza() { delete ingredienti; }

const Lista<Ingrediente*>& Pizza::getIngredienti() const { return ingredienti; }

/* Non si controlla che la lista di ingredienti sia vuota perchè nella
costruzione di una nuova pizza al costruttore è garantito il passaggio di una
lista di ingredienti non vuota */
Farina* Pizza::getFarina() const {
  return static_cast<Farina*>(*(ingredienti.begin()));
}

// aggiorna la tipologia di farina presente nella lista ingredienti della pizza
void Pizza::setFarina(const Farina* f) {
  static_cast<Farina*>(*(ingredienti.begin()))
      ->setTipoFarina(f->getTipoFarina());
}

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::addIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.begin(); it != ingr.end(); ++it) addIngrediente(*it);
}

void Pizza::removeIngrediente(Ingrediente* i) {
  for (Lista<Ingrediente*>::Iterator it = ingredienti.begin();
       it != ingredienti.end(); ++it) {
    if (*it == i) {
      ingredienti.erase(it);
      it = --(ingredienti.end());
    }
  }
}

bool Pizza::checkIngrediente(const Ingrediente* daCercare) const {
  Lista<Ingrediente*>::const_Iterator it;
  bool trovato = false;
  for (it = ingredienti.const_begin();
       it != ingredienti.const_end() && !trovato; ++it)
    if (*it == daCercare) trovato = true;
  return trovato;
}

Pizza* Pizza::clone() const { return new Pizza(*this); }

// Ritorna il prezzo di vendita della pizza di invocazione.
double Pizza::getPrezzo() const {
  int somma = 0;
  for (Lista<Ingrediente*>::const_Iterator it = ingredienti.const_begin();
       it != ingredienti.const_end(); ++it) {
    if ((*it)->isLocal()) somma += extra;
  }
  return getPrezzoBase() + somma;
}
