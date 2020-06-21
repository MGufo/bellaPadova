#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::removeIngrediente(Ingrediente* i) {
  Lista<Ingrediente*>::Iterator it = ingredienti.find(i);
  if (it.isValid()) ingredienti.erase(it);
}

// costruisce una pizza la cui lista di ingredienti contiene solo la farina
Pizza::Pizza(unsigned int id, string nome, bool disponibilita, double prezzo)
    : Risorsa(id, nome, disponibilita),
      Articolo(id, nome, disponibilita, prezzo),
      ingredienti(Lista<Ingrediente*>()) {}

// Copia profonda implementata tramite metodo copy del container
Pizza::Pizza(const Pizza& p)
    : Risorsa(p), Articolo(p), ingredienti(p.getIngredienti()) {}

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

// TODO: Messaggio da mostrare come eccezione nel caso in cui l'ingrediente sia
// già presente o sia di tipo Farina*:
// - "Ingrediente già presente nella lista di ingredienti"
// - "La lista di ingredienti non deve contenere Farine"
void Pizza::aggiungiIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it)
    if (dynamic_cast<Farina*>(*it) || (checkIngrediente(*it)))
      throw new std::domain_error("Non è possibile aggiungere l'ingrediente selezionato");

  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it)
    addIngrediente(*it);
}

// "Ingrediente già rimosso dalla lista di ingredienti"
// "Rimozione della farina dalla lista di ingredienti non consentita"
void Pizza::rimuoviIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it))
      throw new std::domain_error("Errore: Non è possibile rimuovere la farina da una pizza.");
    if (!checkIngrediente(*it))
      throw new std::domain_error("Errore: L'ingrediente da rimuovere non è presente nella pizza selezionata.");
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

const Lista<Consumabile*>* Pizza::getComposizione() const {
  Lista<Consumabile*>* lista = new Lista<Consumabile*>();
  for (auto it = ingredienti.const_begin(); it != ingredienti.const_end();
       ++it) {
    lista->push_back(*it);
  }
  return lista;
}
