#include "pizza.h"

// Costruttore di default, costruisce una pizza a impasto normale senza ingredienti
Pizza::Pizza(string nome = "focaccia", bool disponibilita = true, double prezzo = 0,
             formatoPizza fo = formatoPizza::normale,
             farina fa = farina::normale,
             contenitoreC<string>* ingr = nullptr)
           : Articolo(nome, disponibilita, prezzo),
             tipoFormato(fo),
             tipoFarina(fa),
             ingredienti(ingr ? new contenitoreC<string>(ingr) : nullptr){}

// Costruttore di copia
// TODO: Implementare copia profonda
Pizza::Pizza(const Pizza& p){}

// Distruttore
//TODO: Implementare distruttore profondo
Pizza::~Pizza();

//non è possibile fare cast da enum a string a meno che non vengano usati
//if-else per decidere cosa ritornare (poco elegante e mantenibile)
formatoPizza Pizza::getTipoFormato() const{
    return tipoFormato;
}

const contenitoreC<string>& Pizza::getIngredienti() const{
    if(!ingredienti)    return nullptr;
    return *ingredienti;
}

//non è possibile fare cast da enum a string a meno che non vengano usati
//if-else per decidere cosa ritornare (poco elegante e mantenibile)
farina Pizza::getTipoFarina() const{
    return farina;
}

void Pizza::setTipoFormato(const unsigned int tf){
    tipoFormato = tf;
}

void Pizza::setTipoFarina(const unsigned int tf){
    tipoFarina = tf;
}

void addIngrediente(const string& i){
    ingredienti->push_back(i);
}
