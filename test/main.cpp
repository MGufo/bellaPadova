#include <iostream>
#include <QDate>
#include <string>
#include "../core/bottiglia.h"
#include "../core/lattina.h"
using std::string;
int main()
{
  //string nome, bool disponibilita, double prezzo,
  //                     unsigned int qta, double costo, QDate dataAcquisto,
  //                     QDate dataScadenza, double capacitaBevanda
    Bottiglia pepsi("pepsi", true, 3, 6, 5, QDate::currentDate(), QDate::currentDate(), 1);
    Lattina fanta("fanta", true, 2, 6, 5, QDate::currentDate(), QDate::currentDate(), 0.5);
    Bottiglia* pepsi2 = pepsi.clone();
    std::cout << pepsi.getPrezzo() << std::endl;
    std::cout << pepsi2->getPrezzo() << std::endl;
    return 0;
}
