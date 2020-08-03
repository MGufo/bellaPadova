#include "pizza.h"

#include "farina.h"

double Pizza::extra = 0.50;

void Pizza::addIngrediente(Ingrediente* i) { ingredienti.push_back(i); }

void Pizza::removeIngrediente(Ingrediente* i) {
  Lista<Ingrediente*>::Iterator it = ingredienti.find(i);
  if (it.isValid()) ingredienti.erase(it);
}

Pizza::Pizza() {}

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

void Pizza::aggiungiIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it))
      throw new std::domain_error("Errore: La lista di ingredienti non può"
                                  "contenere farine.");
    if(checkIngrediente(*it))
      throw new std::domain_error("Errore: L'ingrediente " + (*it)->getNome() +
                                  " è già presente nella lista di ingredienti.");
}
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it)
    addIngrediente(*it);
}

void Pizza::rimuoviIngredienti(const Lista<Ingrediente*>& ingr) {
  for (auto it = ingr.const_begin(); it != ingr.const_end(); ++it) {
    if (dynamic_cast<Farina*>(*it))
      throw new std::domain_error("Errore: Non è possibile rimuovere la farina"
                                  "da una pizza.");
    if (!checkIngrediente(*it))
      throw new std::domain_error("Errore: L'ingrediente da rimuovere non è"
                                  "presente nella pizza selezionata.");
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

void Pizza::modificaComposizione(Consumabile* daModificare, Consumabile* modificato){
    auto it = ingredienti.find(dynamic_cast<Ingrediente*>(daModificare));
    if(it.isValid()){
        (*it)->setNome(modificato->getNome());
        (*it)->setDisponibilita(modificato->getDisponibilita());
        (*it)->setQuantita(modificato->getQuantita());
        (*it)->setCosto(modificato->getCosto());
        (*it)->setDataAcquisto(modificato->getDataAcquisto());
        (*it)->setLocal(dynamic_cast<Ingrediente*>(modificato)->isLocal());
    }
}

void Pizza::carica(const QJsonObject& pizzaJSON,
                   const std::unordered_map<uint, Risorsa*>* keymap) {
  setID((*(pizzaJSON.constFind("ID"))).toInt());
  setNome((*(pizzaJSON.constFind("Nome"))).toString().toStdString());
  setDisponibilita((*(pizzaJSON.constFind("Disponibilita"))).toBool());
  setPrezzoBase((*(pizzaJSON.constFind("Prezzo"))).toDouble());
  QJsonArray* ingredientiJSON =
      new QJsonArray((*(pizzaJSON.constFind("Ingredienti"))).toArray());
  for(auto it = ingredientiJSON->constBegin();
      it != ingredientiJSON->constEnd(); ++it){
      ingredienti.push_back(dynamic_cast<Ingrediente*>(
                              keymap->at((*it).toInt())));
  }
  delete ingredientiJSON;
}

void Pizza::salva(QJsonObject& pizzaJSON) const{
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
  for(auto it = ingredienti.const_begin(); it != ingredienti.const_end(); ++it)
    ingredientiJSON->append(static_cast<double>((*it)->getIdRisorsa()));
  pizzaJSON.insert("Ingredienti", *ingredientiJSON);
  delete ingredientiJSON;
  // Extra
  pizzaJSON.insert("Extra", extra);
  //
  pizzaJSON.insert("tipo", "pizza");
}
