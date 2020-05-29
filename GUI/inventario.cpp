#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  QScrollArea* scrollArea = new  QScrollArea(this);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);

  QPushButton* editInventario = new QPushButton("Modifica", this);
  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);

  layoutPulsanti->addWidget(editInventario);
  layoutPulsanti->addWidget(newConsumabile);

  layoutInventario->addWidget(scrollArea);
  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}
