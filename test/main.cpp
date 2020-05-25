#include <QDate>
#include <QApplication>
#include <iostream>
#include <string>
#include "../core/pizzeria.h"
#include <stdexcept>
#include "../GUI/MainWindow.h"
using std::string;

int main(int argc, char* argv[]) {

  QApplication app(argc, argv);
  Pizzeria bellaPadova;
  MainWindow view;
  view.show();

  return app.exec();
}
//  Farina* normale = new Farina();
//  //Farina* farro = new Farina("farina farro 1kg", true, 10, 2, QDate::currentDate(), false, "farro");
//  Ingrediente* mozz = new Ingrediente("mozzarella", true, 10, 5, QDate::currentDate());
//  Ingrediente* pomm = new Ingrediente("pomodoro", true, 10, 5, QDate::currentDate(), true);

//  Lista<Ingrediente*>* farina = new Lista<Ingrediente*>();
//  Lista<Ingrediente*>* iniziale = new Lista<Ingrediente*>();
//  Lista<Ingrediente*>* daAggiungere= new Lista<Ingrediente*>();
//  Lista<Ingrediente*>* daRimuovere= new Lista<Ingrediente*>();

//  farina->push_back(normale);
//  iniziale->push_back(mozz);
//  iniziale->push_back(pomm);

//  daAggiungere->push_back(wrustel);
//  daAggiungere->push_back(ananas);
//  daAggiungere->push_back(funghi);

//  daRimuovere->push_back(funghi);


//  Pizza* marghe = new Pizza("margherita", true, 4);
//  try{
//    marghe->aggiungiIngredienti(*daAggiungere);
//    marghe->rimuoviIngredienti(*daAggiungere);
//  }catch(...){
//    std::cout << "Hai sbagliato, ebete!" << std::endl;
//  }
//  marghe->aggiungiIngredienti(*iniziale);
//  marghe->setFarina(normale);
//  Ingrediente* wrustel = new Ingrediente("wrustel", true, 10, 5, QDate::currentDate());
//  Ingrediente* funghi = new Ingrediente("funghi", true, 10, 5, QDate::currentDate(), true);
//  Ingrediente* ananas = new Ingrediente("ananas", true, 10, 5, QDate::currentDate(), true);

//  Pizza* mari = new Pizza("marinara", true, 4);
//  Pizza* boschi = new Pizza("boscaiola", true, 4);

//  marghe->addIngredienti(*list);
//  mari->addIngredienti(*list);
//  boschi->addIngredienti(*list);

//  GestoreRisorse gestore;
//  Lattina* Fanta =
//      new Lattina("Fanta", true, 2, 10, 6, QDate::currentDate(), 0.33);
//  Bottiglia* CocaCola =
//      new Bottiglia("Coca Cola", true, 4, 10, 8, QDate::currentDate(), 1.5);

//
//  boschi->addIngrediente(funghi);
//  boschi->addIngrediente(wrustel);
//  gestore.inserisciConsumabileInInventario(normale);
//  gestore.inserisciConsumabileInInventario(farro);

//  gestore.inserisciConsumabileInInventario(wrustel);
//  gestore.inserisciConsumabileInInventario(funghi);
//  gestore.inserisciArticoloInMenu(boschi);

//  gestore.rimuoviConsumabileDaInventario(normale);
//  gestore.rimuoviConsumabileDaInventario(farro);
//  gestore.rimuoviConsumabileDaInventario(wrustel);

//  string nome, bool disponibilita, double prezzo,
//  unsigned int qta, double costo, QDate dataAcquisto, double capacitaBevanda)

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
