#include <iostream>
#include <QDate>
#include <string>
#include "../core/ingrediente.h"
#include "../core/pizza.h"
#include "../core/qontainer.h"
#include "../core/comanda.h"
using std::string;

int main(){
  Farina* normale = new Farina();
  Ingrediente* mozz = new Ingrediente("mozzarella", true, 10, 5, QDate::currentDate());
  Ingrediente* pomm = new Ingrediente("pomodoro", true, 10, 5, QDate::currentDate(), true);
  Lista<Ingrediente*>* list = new Lista<Ingrediente*>();

  list->push_back(normale);
  list->push_back(mozz);
  list->push_back(pomm);
  Pizza* marghe = new Pizza("margherita", true, 4, *list);
  Pizza* mari = new Pizza("marinara", true, 4, *list);
  Pizza* boschi = new Pizza("boscaiola", true, 4, *list);

  unordered_map<Articolo*, unsigned int> ordine;
  ordine[marghe] = 2;
  Comanda piergiorgio(ordine, Contatto("AndyM", "Via Prova 123", "123456789"), QTime::currentTime());

  piergiorgio.inserisciArticolo(mari, 1);


  // std::cout << piergiorgio.getOraConsegna().toString().toStdString() <<std::endl;
  // std::cout << piergiorgio.getCliente().getNome()<<std::endl;
  // std::cout << piergiorgio.getCliente().getIndirizzo()<<std::endl;
  // std::cout << piergiorgio.getCliente().getTelefono()<<std::endl;

  std::cout << (piergiorgio.getOrdinazione()).at(mari) << std::endl;
  std::cout << (piergiorgio.getOrdinazione()).at(boschi) << std::endl;
  std::cout << (piergiorgio.getOrdinazione()).at(marghe) << std::endl;
  return 0;
}
