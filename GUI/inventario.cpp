#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  QScrollArea* scrollArea = new  QScrollArea(this);
  QVBoxLayout* layoutScrollArea = new QVBoxLayout(scrollArea);

  QLabel* ingredienti = new QLabel("Ingredienti: ", this);
  QTableWidget* tabIngredienti = new QTableWidget(1,5,this);

  QTableWidgetItem* thNome = new QTableWidgetItem("Nome", 0);
  QTableWidgetItem* thConfezioni = new QTableWidgetItem("Confezioni", 0);
  QTableWidgetItem* thCosto = new QTableWidgetItem("Costo", 0);
  QTableWidgetItem* thDataAcquisto = new QTableWidgetItem("Data Acquisto", 0);
  QTableWidgetItem* thLocale = new QTableWidgetItem("Locale", 0);

  tabIngredienti->setItem(0, 0, thNome);
  tabIngredienti->setItem(0, 1, thConfezioni);
  tabIngredienti->setItem(0, 2, thCosto);
  tabIngredienti->setItem(0, 3, thDataAcquisto);
  tabIngredienti->setItem(0, 4, thLocale);

  QLabel* bevande = new QLabel("Bevande: ", this);
  QTableWidget* tabBevande = new QTableWidget(1,5,this);






  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);

  QPushButton* editInventario = new QPushButton("Modifica", this);
  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);

  layoutScrollArea->addWidget(ingredienti);
  layoutScrollArea->addWidget(tabIngredienti);
  layoutScrollArea->addWidget(bevande);
  layoutScrollArea->addWidget(tabBevande);
  scrollArea->setLayout(layoutScrollArea);

  layoutPulsanti->addWidget(editInventario);
  layoutPulsanti->addWidget(newConsumabile);

  layoutInventario->addWidget(scrollArea);
  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}
