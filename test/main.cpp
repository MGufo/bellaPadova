#include <iostream>
#include <QDate>
#include "../core/farina.h"
#include "../core/pizza.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    //Ingrediente * i = new Ingrediente("pomodoro",true,10,5,*(new QDate(2020,4,19)), QDate::currentDate(),true);
    //Farina * f = new Farina(2,*(new QDate(2020,4,25)),"farina",true,10, QDate::currentDate(),true, "farro");

    Lista<Ingrediente*>* ingre = new Lista<Ingrediente*>();
    Farina * f = new Farina(2,*(new QDate(2020,4,25)),"farina",true,10, QDate::currentDate(),false, "farro");
    Ingrediente * i = new Ingrediente("pomodoro",true,10,5,*(new QDate(2020,4,19)), QDate::currentDate(),true);
    Ingrediente * i2 = new Ingrediente("mozzarella",true,7,4,*(new QDate(2020,4,24)), QDate::currentDate(),true);


    ingre->push_back(f);
    ingre->push_back(i);
    //ingre->push_back(i2);

    auto iter = ingre->end();
    //std::cout << (iter.punt ? iter.punt->info->getCosto() : 69) << std::endl;
    //std::cout << (iter.prec ? iter.prec->info->getCosto() : 420) << std::endl;

    //auto iter = ingre->insert(ingre->begin(),f);
    /*
    std::cout << (*iter)->getCosto() << std::endl;
    auto it = ingre->begin();
    std::cout << (*it)->getCosto() << std::endl;
    */
    /*for(auto iterator = --(ingre->end()); iterator != --(ingre->begin()); --iterator){
        std::cout << (*iterator)->getCosto() << std::endl;
    }*/

    /*Lista<Ingrediente*>::Nodo* tempissimo = new Lista<Ingrediente*>::Nodo(f,nullptr,nullptr);
    std::cout << tempissimo->info->getCosto() << std::endl;*/

    //Pizza* margherita = new Pizza("margherita",true,5,ingre);
    //std::cout << margherita->getPrezzo() << std::endl;

    return 0;

}
