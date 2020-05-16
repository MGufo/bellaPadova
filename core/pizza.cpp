#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::removeIngrediente(Ingrediente* i) {
  Lista<Ingrediente*>::Iterator it = ingredienti.find(i);
  if (it.isValid()) ingredienti.erase(it);
}

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

bool Pizza::checkIngrediente(const Ingrediente* daCercare) const {
  Lista<Ingrediente*>::const_Iterator it;
  bool trovato = false;
  for (it = ingredienti.const_begin();
       it != ingredienti.const_end() && !trovato; ++it)
    if (*it == daCercare) trovato = true;
  return trovato;
}

const Lista<Ingrediente*>& Pizza::getIngredienti() const { return ingredienti; }

Farina* Pizza::getFarina() const {
  if (!ingredienti.isEmpty()) {
    for (auto it = ingredienti.const_begin(); it != ingredienti.const_end();
         ++it)
      if (dynamic_cast<Farina*>(*it)) return static_cast<Farina*>(*it);
  }
  return nullptr;
}

// aggiorna la tipologia di farina presente nella lista ingredienti della
// pizza
void Pizza::setFarina(Farina* f) {
  if (f) {
    if (!ingredienti.isEmpty()) {
      Lista<Ingrediente*>::Iterator it = ingredienti.find(getFarina());
      if (it.isValid())
        *it = f;
      else
        ingredienti.push_back((f));
    } else
      ingredienti.push_back((f));
  }
}

void Pizza::aggiungiIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (!dynamic_cast<Farina*>(*it)) {
      if (checkIngrediente(*it)) throw;
      addIngrediente(*it);
    }
  }
}

// se l'ingr non c'è
// se l'ingr è una farina
void Pizza::rimuoviIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it)) throw;
    if (!checkIngrediente(*it)) throw;
    removeIngrediente(*it);
  }
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

const Lista<const Consumabile*>* Pizza::getComposizione() const {
  Lista<const Consumabile*>* lista = new Lista<const Consumabile*>();
  for (auto it = ingredienti.const_begin(); it != ingredienti.const_end();
       ++it) {
    lista->push_back(*it);
  }
  return lista;
}
