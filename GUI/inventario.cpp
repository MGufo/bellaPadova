#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  //QScrollArea* ingredienti = new QScrollArea(this);
  TabellaComposita* tabIngredienti = new TabellaComposita(this, "Ingredienti");
  //ingredienti->setWidget(tabIngredienti);
  //QScrollArea* bevande = new QScrollArea(this);
  TabellaComposita* tabBevande = new TabellaComposita(this, "Bevande");
  //bevande->setWidget(tabBevande);


  layoutInventario->addWidget(tabIngredienti);
  layoutInventario->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);
  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);
  QPushButton* modificaDati = new QPushButton("Modifica", this);
  layoutPulsanti->addWidget(newConsumabile);
  layoutPulsanti->addWidget(modificaDati);
  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}
