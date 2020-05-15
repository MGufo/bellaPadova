#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::removeIngrediente(Ingrediente* i) {
  for (Lista<Ingrediente*>::Iterator it = ingredienti.begin();
       it != ingredienti.end(); ++it) {
    if (*it == i) {
      ingredienti.erase(it);
      it = --(ingredienti.end());
    }
  }
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

/* Non si controlla che la lista di ingredienti sia vuota perchè nella
costruzione di una nuova pizza al costruttore è garantito il passaggio di una
lista di ingredienti non vuota */
Farina* Pizza::getFarina() const {
  if (!ingredienti.isEmpty())
    return static_cast<Farina*>(*(ingredienti.begin()));
  return nullptr;
}

// aggiorna la tipologia di farina presente nella lista ingredienti della pizza
void Pizza::setFarina(const Farina* f) {
  if (f) {
    if (!ingredienti.isEmpty())
      static_cast<Farina*>(*(ingredienti.begin()))
          ->setTipoFarina(f->getTipoFarina());
    else
      // FIXME: Correggere implementazione set/get Farina, causa SEGFAULT quando
      // si usa aggiungiIngredienti() a pizza appena creata (con lista vuota)
      ingredienti.push_back((f));
  }
}

void Pizza::aggiungiIngredienti(const Lista<Ingrediente*>& ingr) {
  unsigned short nFarina = 0;
  Lista<Ingrediente*>::const_Iterator farina;
  for (auto it = ingr.const_begin(); it != ingr.const_end() && nFarina <= 1;
       ++it) {
    if (dynamic_cast<Farina*>(*it)) {
      farina = it;
      ++nFarina;
    }
  }
  if (nFarina > 1) throw;

  if (!(farina.isValid()) && getFarina() == (*farina)) throw;
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it)) setFarina(dynamic_cast<Farina*>(*it));
    if (checkIngrediente(*it)) throw;
    addIngrediente(*it);
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
