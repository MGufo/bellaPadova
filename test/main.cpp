#include <QDate>
#include <iostream>
#include <string>

#include "../core/gestoreComande.h"
#include "../core/gestoreRisorse.h"
#include "../core/ingrediente.h"
#include "../core/pizza.h"
#include "../core/qontainer.h"
using std::string;

int main() {
  Farina* normale = new Farina();
  Farina* farro = new Farina("farina farro 1kg", true, 10, 2,
                             QDate::currentDate(), false, "farro");
  Ingrediente* mozz =
      new Ingrediente("mozzarella", true, 10, 5, QDate::currentDate());
  Ingrediente* pomm =
      new Ingrediente("pomodoro", true, 10, 5, QDate::currentDate(), true);
  Lista<Ingrediente*>* list = new Lista<Ingrediente*>();

  list->push_back(normale);
  list->push_back(mozz);
  list->push_back(pomm);
  Pizza* marghe = new Pizza("margherita", true, 4);
  Pizza* mari = new Pizza("marinara", true, 4);
  Pizza* boschi = new Pizza("boscaiola", true, 4);

  marghe->addIngredienti(*list);
  mari->addIngredienti(*list);
  boschi->addIngredienti(*list);

  GestoreRisorse gestore;
  Lattina* Fanta =
      new Lattina("Fanta", true, 2, 10, 6, QDate::currentDate(), 0.33);
  Bottiglia* CocaCola =
      new Bottiglia("Coca Cola", true, 4, 10, 8, QDate::currentDate(), 1.5);

  Ingrediente* wrustel =
      new Ingrediente("wrustel", true, 10, 5, QDate::currentDate());
  Ingrediente* funghi =
      new Ingrediente("funghi", true, 10, 5, QDate::currentDate(), true);
  Ingrediente* ananas =
      new Ingrediente("ananas", true, 10, 5, QDate::currentDate(), true);

  boschi->addIngrediente(funghi);
  boschi->addIngrediente(wrustel);
  gestore.inserisciConsumabileInInventario(normale);
  gestore.inserisciConsumabileInInventario(farro);

  gestore.inserisciConsumabileInInventario(wrustel);
  gestore.inserisciConsumabileInInventario(funghi);
  gestore.inserisciArticoloInMenu(boschi);

  gestore.rimuoviConsumabileDaInventario(normale);
  gestore.rimuoviConsumabileDaInventario(farro);
  gestore.rimuoviConsumabileDaInventario(wrustel);

  return 0;

  //  // string nome, bool disponibilita, double prezzo,
  //  // unsigned int qta, double costo, QDate dataAcquisto, double
  //  capacitaBevanda)

  //  Lattina* Fanta = new Lattina("Fanta", true, 2, 10, 6,
  //  QDate::currentDate(), 0.33); Bottiglia* CocaCola = new Bottiglia("Coca
  //  Cola", true, 4, 10, 8, QDate::currentDate(), 1.5);

  //  Comanda* comanda1 = new Comanda(Contatto("AndyM", "Via Prova 123",
  //  "123456789"), QTime::currentTime()); comanda1->inserisciArticolo(marghe,
  //  2); comanda1->inserisciArticolo(mari, 1);
  //  comanda1->inserisciArticolo(CocaCola, 3);

  //  Comanda* comanda2 = new Comanda(Contatto("gBizz", "Via Stocazzo",
  //  "987654321"), QTime(17,30)); comanda2->inserisciArticolo(boschi, 5);
  //  comanda2->inserisciArticolo(marghe, 1);
  //  comanda2->inserisciArticolo(Fanta, 4);

  //  Comanda* comanda3 = new Comanda(Contatto("Gufo", "Via MeCojoni", "666"),
  //  QTime::currentTime()); comanda3->inserisciArticolo(boschi, 1);

  //  GestoreComande gestore;

  //  gestore.inserisciComanda(comanda1);
  //  gestore.inserisciComanda(comanda2);
  //  gestore.inserisciComanda(comanda3);

  //  gestore.modificaComanda(comanda1, mari);
  //  gestore.modificaComanda(comanda1,marghe, 1);

  //  Lista<Ingrediente*>* daAgg = new Lista<Ingrediente*>();
  //  daAgg->push_back(wrustel);
  //  daAgg->push_back(funghi);
  //  daAgg->push_back(ananas);
  //  Lista<Ingrediente*>* daRim = new Lista<Ingrediente*>();
  //  daRim->push_back(pomm);
  //  gestore.modificaComanda(marghe, daAgg, daRim);
  //  gestore.modificaComanda(comanda2, QTime(17,00));
}
