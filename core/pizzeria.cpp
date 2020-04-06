#include "pizzeria.h"

Pizzeria::Pizzeria(string nome, string indirizzo, string telefono) 
: contatto(new Contatto(nome, indirizzo, telefono)), gestore(new Gestore()){}

const Lista<const string&> Pizzeria::getContatto() const{
    return contatto->getContatto();
}
