#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::removeIngrediente(Ingrediente* i) {
  Lista<Ingrediente*>::Iterator it = ingredienti.find(i);
  if (it.isValid()) ingredienti.erase(it);
}

Pizza::Pizza() {}

Pizza::Pizza(unsigned int id, string nome, bool disponibilita, double prezzo)
    : Risorsa(id, nome, disponibilita),
      Articolo(id, nome, disponibilita, prezzo),
      ingredienti(Lista<Ingrediente*>()) {}

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

void Pizza::aggiungiIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it))
      throw new std::domain_error(
          "Errore: La lista di ingredienti non può"
          "contenere farine.");
    if (checkIngrediente(*it))
      throw new std::domain_error(
          "Errore: L'ingrediente " + (*it)->getNome() +
          " è già presente nella lista di ingredienti.");
  }
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it)
    addIngrediente(*it);
}

void Pizza::rimuoviIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it))
      throw new std::domain_error(
          "Errore: Non è possibile rimuovere la farina"
          "da una pizza.");
    if (!checkIngrediente(*it))
      throw new std::domain_error(
          "Errore: L'ingrediente da rimuovere non è"
          "presente nella pizza selezionata.");
    removeIngrediente(*it);
  }
}

Pizza* Pizza::clone() const { return new Pizza(*this); }

// Ritorna il prezzo di vendita della pizza di invocazione.
double Pizza::getPrezzo() const {
  double somma = 0;
  for (Lista<Ingrediente*>::const_Iterator it = ingredienti.const_begin();
       it != ingredienti.const_end(); ++it) {
    if ((*it)->isLocal()) somma += extra;
  }
  return (getPrezzoBase() + somma);
}

const Lista<const Consumabile*>* Pizza::getComposizione() const {
  Lista<const Consumabile*>* lista = new Lista<const Consumabile*>();
  for (auto it = ingredienti.const_begin(); it != ingredienti.const_end();
       ++it) {
    lista->push_back(*it);
  }
  return lista;
}

// non è disponibile la modifica degli ingredienti
void Pizza::modifica(Risorsa* modificato) {
  setNome(modificato->getNome());
  setDisponibilita(modificato->getDisponibilita());
  setPrezzoBase(dynamic_cast<Articolo*>(modificato)->getPrezzoBase());
}

void Pizza::carica(const QJsonObject& pizzaJSON,
                   const std::unordered_map<uint, Risorsa*>* keymap) {
  setID((*(pizzaJSON.constFind("ID"))).toInt());
  setNome((*(pizzaJSON.constFind("Nome"))).toString().toStdString());
  setDisponibilita((*(pizzaJSON.constFind("Disponibilita"))).toBool());
  setPrezzoBase((*(pizzaJSON.constFind("Prezzo"))).toDouble());
  QJsonArray* ingredientiJSON =
      new QJsonArray((*(pizzaJSON.constFind("Ingredienti"))).toArray());
  for (auto it = ingredientiJSON->constBegin();
       it != ingredientiJSON->constEnd(); ++it) {
    Ingrediente* tmp = dynamic_cast<Ingrediente*>(keymap->at((*it).toInt()));
    if (tmp)
      ingredienti.push_back(tmp);
    else
      setDisponibilita(false);
  }
  delete ingredientiJSON;
}

void Pizza::salva(QJsonObject& pizzaJSON) const {
  // ID
  pizzaJSON.insert("ID", static_cast<int>(getIdRisorsa()));
  // Nome
  pizzaJSON.insert("Nome", QString::fromStdString(getNome()));
  // Disponibilita
  pizzaJSON.insert("Disponibilita", getDisponibilita());
  // Prezzo
  pizzaJSON.insert("Prezzo", getPrezzoBase());
  // Ingredienti
  QJsonArray* ingredientiJSON = new QJsonArray();
  for (auto it = ingredienti.const_begin(); it != ingredienti.const_end(); ++it)
    ingredientiJSON->append(static_cast<double>((*it)->getIdRisorsa()));
  pizzaJSON.insert("Ingredienti", *ingredientiJSON);
  delete ingredientiJSON;
  // Extra
  pizzaJSON.insert("Extra", extra);
  //
  pizzaJSON.insert("tipo", "pizza");
}
