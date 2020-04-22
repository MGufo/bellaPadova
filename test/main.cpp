#include <iostream>
#include <QDate>
#include "../core/farina.h"
#include "../core/pizza.h"

int main()
{

    //Ingrediente * i = new Ingrediente("pomodoro",true,10,5,*(new QDate(2020,4,19)), QDate::currentDate(),true);
    //Farina * f = new Farina(2,*(new QDate(2020,4,25)),"farina",true,10, QDate::currentDate(),true, "farro");

    Lista<Ingrediente*>* ingre = new Lista<Ingrediente*>();
    Farina * f = new Farina(2,*(new QDate(2020,4,25)),"farina",true,10, QDate::currentDate(),false, "farro");
    Farina * f2 = new Farina(3,*(new QDate(2020,4,26)),"farina",true,11, QDate::currentDate(),true, "merda");
    Ingrediente * i = new Ingrediente("pomodoro",true,10,5,*(new QDate(2020,4,19)), QDate::currentDate(),true);
    Ingrediente * i2 = new Ingrediente("mozzarella",true,7,4,*(new QDate(2020,4,24)), QDate::currentDate(),true);

    ingre->push_back(f);
    ingre->push_back(i);
    ingre->push_back(i2);

    Pizza* margherita = new Pizza("margherita",true,5,ingre);
    std::cout << margherita->getPrezzo() << std::endl;
    Pizza* margh = new Pizza(*margherita);


    return 0;

}
