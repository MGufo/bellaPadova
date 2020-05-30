#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  QScrollArea* scrollAreaIngr = new  QScrollArea(this);
  QScrollArea* scrollAreaBev = new  QScrollArea(this);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);

  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);
  QPushButton* modificaDati = new QPushButton("Modifica", this);

  layoutPulsanti->addWidget(newConsumabile);
  layoutPulsanti->addWidget(modificaDati);

  QLabel* ingredienti = new QLabel("Inventario", this);
  // tabella ingredienti
  QTableWidget* tabIngredienti = new QTableWidget(0, 5, scrollAreaIngr);
  QHeaderView* headerIngredienti = new QHeaderView(Qt::Horizontal,tabIngredienti);

  QStringList* headerIngredientiLabels = new QStringList();
  headerIngredientiLabels->push_back(QString("Nome"));
  headerIngredientiLabels->push_back(QString("Confezioni"));
  headerIngredientiLabels->push_back(QString("Costo"));
  headerIngredientiLabels->push_back(QString("Data Acquisto"));
  headerIngredientiLabels->push_back(QString("Locale"));


  tabIngredienti->setHorizontalHeaderLabels(*headerIngredientiLabels);
  tabIngredienti->setHorizontalHeader(headerIngredienti);


  //layout wrapper tabella
  QVBoxLayout* wrapperIngredienti = new QVBoxLayout(scrollAreaIngr);
  QVBoxLayout* wrapperBevande = new QVBoxLayout(scrollAreaBev);

  QLabel* bevande = new QLabel("Bevande", this);
  // tabella ingredienti
  QTableWidget* tabBevande = new QTableWidget(0, 5, scrollAreaBev);
  QHeaderView* headerBevande = new QHeaderView(Qt::Horizontal,tabBevande);
  QStringList* headerBevandeLabels = new QStringList(*headerIngredientiLabels);
  tabBevande->setHorizontalHeaderLabels(*headerBevandeLabels);
  tabBevande->setHorizontalHeader(headerBevande);



  //layout wrapper tabella

  wrapperIngredienti->addWidget(ingredienti);
  wrapperIngredienti->addWidget(tabIngredienti);

  wrapperBevande->addWidget(bevande);
  wrapperBevande->addWidget(tabBevande);

  scrollAreaIngr->setLayout(wrapperIngredienti);
  scrollAreaIngr->setLayout(wrapperBevande);

  //aggiunta scroll area al main layout
  layoutInventario->addWidget(scrollAreaIngr);
  layoutInventario->addWidget(scrollAreaBev);

  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}
