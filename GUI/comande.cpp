#include "comande.h"

Comande::Comande(QWidget *parent) : QWidget(parent){

  // Sezione comande da eseguire
  QLabel* label_inEsecuzione = new QLabel("In Esecuzione:", this);
  label_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  QScrollArea* scroll_inEsecuzione = new QScrollArea(this);
  QWidget* wrapper_inEsecuzione = new QWidget(scroll_inEsecuzione);
  Comanda_GUI* comanda1 = new Comanda_GUI(wrapper_inEsecuzione);
  QHBoxLayout* layout_inEsecuzione = new QHBoxLayout(wrapper_inEsecuzione);
  wrapper_inEsecuzione->setLayout(layout_inEsecuzione);
  layout_inEsecuzione->addWidget(comanda1);
  scroll_inEsecuzione->setWidget(wrapper_inEsecuzione);
  scroll_inEsecuzione->setMinimumSize(580, 100);
  scroll_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  //////////////////////////////
  // Sezione comande eseguite //
  //////////////////////////////

  QLabel* label_concluse = new QLabel("Concluse:", this);
  label_concluse->setStyleSheet("background-color: yellow;");
  label_concluse->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  QScrollArea* scroll_eseguite = new QScrollArea(this);
  QWidget* wrapper_eseguite = new QWidget(scroll_eseguite);

  //aggiungere roba al widget

  QHBoxLayout* layout_eseguite = new QHBoxLayout(wrapper_eseguite);
  wrapper_eseguite->setLayout(layout_eseguite);
  wrapper_eseguite->setStyleSheet("background-color: red;");
  scroll_eseguite->setWidget(wrapper_eseguite);
  scroll_eseguite->setStyleSheet("background-color: blue;");
  scroll_eseguite->setMinimumSize(580, 100);
  scroll_eseguite->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  comandeLayout = new QVBoxLayout(this);
  comandeLayout->addWidget(label_inEsecuzione);
  comandeLayout->addWidget(scroll_inEsecuzione);
  comandeLayout->addWidget(label_concluse);
  comandeLayout->addWidget(scroll_eseguite);
  comandeLayout->setContentsMargins(0,0,0,0);

  setStyleComande();
  setLayout(comandeLayout);
}

void Comande::setStyleComande(){
  comandeLayout->setSpacing(0);
  comandeLayout->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
