#include <iostream>
#include <QDate>
#include <string>
#include "../core/ingrediente.h"
#include "../core/pizza.h"
#include "../core/qontainer.h"
using std::string;
int main(){
    Ingrediente* mozz = new Ingrediente("mozzarella", true, 10, 5, QDate::currentDate());
    Lista<Ingrediente*>* list = new Lista<Ingrediente*>();

    list->insert(list->begin(),mozz);

    Pizza* marghe = new Pizza("mozzarella", true, 10, list);
    delete marghe;
    delete mozz;
    std::cout << "ghesboro" << std::endl;

    return 0;
}
