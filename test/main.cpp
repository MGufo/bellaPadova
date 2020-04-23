#include <iostream>
#include <QDate>
#include <string>
#include "../core/contatto.h"
using std::string;
int main()
{

    Contatto gabriel("Gabriel", "Via Gioacchino Rossini", "123456789");
    std::cout << gabriel.getNome() << " " << gabriel.getIndirizzo() << " " << gabriel.getTelefono() << std::endl;
    gabriel.setNome("AndVrea");
    std::cout << gabriel.getNome() << std::endl;
    Lista<const string>* punt = new Lista<const string>(gabriel.getContatto());
    for(auto it=punt->begin(); it!=punt->end(); ++it)
      std::cout << *it << " ";
    return 0;
}
