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
  Controller controller(&bellaPadova);
  MainWindow view(&controller);
  controller.setView(&view);
  view.show();

    Farina* normale = new Farina();
    Farina* farro = new Farina("farina di tipo farro 1kg", true, 10, 2, QDate::currentDate(), false, "farro");
    Ingrediente* mozz = new Ingrediente("mozzarella", true, 10, 5, QDate::currentDate());
    Ingrediente* pomm = new Ingrediente("pomodoro", true, 10, 5, QDate::currentDate(), true);
    Ingrediente* wrustel = new Ingrediente("wrustel", true, 10, 5, QDate::currentDate());
    Ingrediente* funghi = new Ingrediente("funghi", true, 10, 5, QDate::currentDate(), true);
    Ingrediente* ananas = new Ingrediente("ananas", true, 10, 5, QDate::currentDate(), true);

    Lista<Ingrediente*>* iniziale = new Lista<Ingrediente*>();
    Lista<Ingrediente*>* daAggiungere= new Lista<Ingrediente*>();
    Lista<Ingrediente*>* daRimuovere= new Lista<Ingrediente*>();

    iniziale->push_back(mozz);
    iniziale->push_back(pomm);

    daAggiungere->push_back(wrustel);
    daAggiungere->push_back(ananas);
    daAggiungere->push_back(funghi);

    daRimuovere->push_back(funghi);


    Pizza* marghe = new Pizza("margherita", true, 4);
    try{
      marghe->aggiungiIngredienti(*iniziale);
    }catch(...){
      std::cout << "Hai sbagliato, ebete!" << std::endl;
    }
    marghe->setFarina(normale);

    Pizza* mari = new Pizza("marinara", true, 4);
    Pizza* boschi = new Pizza("boscaiola", true, 4);
    mari->aggiungiIngredienti(*iniziale);
    mari->setFarina(farro);
    boschi->aggiungiIngredienti(*daAggiungere);
    boschi->setFarina(normale);

    //string nome, bool disponibilita, double prezzo,
    //unsigned int qta, double costo, QDate dataAcquisto, double capacitaBevanda)
    Lattina* Fanta = new Lattina("Fanta", true, 2, 10, 6, QDate::currentDate(), 0.33);
    Bottiglia* CocaCola = new Bottiglia("Coca Cola", true, 4, 10, 8, QDate::currentDate(), 1.5);

    bellaPadova.inserisciConsumabile(normale);
    bellaPadova.inserisciConsumabile(farro);
    bellaPadova.inserisciConsumabile(mozz);
    bellaPadova.inserisciConsumabile(pomm);
    bellaPadova.inserisciConsumabile(wrustel);
    bellaPadova.inserisciConsumabile(ananas);
    bellaPadova.inserisciConsumabile(funghi);
    bellaPadova.inserisciArticolo(boschi);
    bellaPadova.inserisciArticolo(mari);
    bellaPadova.inserisciArticolo(marghe);

    Comanda* comanda1 = new Comanda(1, Contatto("AndyM", "Via Prova 123","123456789"), QTime(20,00), QDate(2020,06,11));
    comanda1->inserisciArticolo(marghe,2);
    comanda1->inserisciArticolo(mari, 1);
    comanda1->inserisciArticolo(CocaCola, 3);

    Comanda* comanda2 = new Comanda(2, Contatto("gBizz", "Via Stocazzo","987654321"), QTime(20,30), QDate(2000,06,11));
    comanda2->inserisciArticolo(boschi, 5);
    comanda2->inserisciArticolo(marghe, 1);
    comanda2->inserisciArticolo(Fanta, 4);

    //TODO: testare inserisciComanda e modificaComanda per vedere se inserisce o meno comande con articoli che hanno
    //gli articoli della composizione non presenti nell'inventario
    bellaPadova.inserisciComanda(comanda1);
    bellaPadova.inserisciComanda(comanda2);

  return app.exec();
}
