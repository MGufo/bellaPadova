#include "comande.h"

Comande::Comande(QWidget *parent) : QWidget(parent){

  /////////////////////////////////
  // Sezione comande da eseguire //
  /////////////////////////////////

  QLabel* label_inEsecuzione = new QLabel("In Esecuzione:", this);
  label_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_inEsecuzione->setObjectName("inEsecuzione");
  QScrollArea* scroll_inEsecuzione = new QScrollArea(this);
  QWidget* wrapper_inEsecuzione = new QWidget(scroll_inEsecuzione);
  wrapper_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  wrapper_inEsecuzione->setObjectName("wrapperInEsecuzione");
  wrapper_inEsecuzione->setContentsMargins(0, 1, 0, 1);
  //dettaglioComanda* comanda1 = new dettaglioComanda(wrapper_inEsecuzione);
  //dettaglioComanda* comanda2 = new dettaglioComanda(wrapper_inEsecuzione);
  ComandaGUI* comanda3 = new ComandaGUI(wrapper_inEsecuzione);
  comanda3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  ComandaGUI* comanda4 = new ComandaGUI(wrapper_inEsecuzione);
  comanda4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


  QHBoxLayout* layout_inEsecuzione = new QHBoxLayout(scroll_inEsecuzione);
  wrapper_inEsecuzione->setLayout(layout_inEsecuzione);
  //layout_inEsecuzione->addWidget(comanda1);
  //layout_inEsecuzione->addWidget(comanda2);
  layout_inEsecuzione->addWidget(comanda3);
  layout_inEsecuzione->addWidget(comanda4);
  scroll_inEsecuzione->setWidget(wrapper_inEsecuzione);
  scroll_inEsecuzione->setMinimumSize(580, 265);
  scroll_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  scroll_inEsecuzione->setWidgetResizable(true);

  //////////////////////////////
  // Sezione comande eseguite //
  //////////////////////////////

  QLabel* label_concluse = new QLabel("Concluse:", this);
  label_concluse->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_concluse->setObjectName("concluse");
  QScrollArea* scroll_eseguite = new QScrollArea(this);
  scroll_eseguite->setContentsMargins(0, 1, 0, 1);

  QWidget* wrapper_eseguite = new QWidget(scroll_eseguite);
  wrapper_eseguite->setObjectName("wrapperEseguite");
  //aggiungere roba al widget


  QHBoxLayout* layout_eseguite = new QHBoxLayout(wrapper_eseguite);
  wrapper_eseguite->setLayout(layout_eseguite);
  scroll_eseguite->setWidget(wrapper_eseguite);
  scroll_eseguite->setMinimumSize(580, 100);
  scroll_eseguite->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  QPushButton* newComanda = new QPushButton(this);
  newComanda->setText("Nuova Comanda");
  newComanda->setObjectName("newComanda");
  newComanda->setMinimumWidth(300);
  newComanda->setMaximumHeight(90);

  comandeLayout = new QVBoxLayout(this);
  comandeLayout->addWidget(label_inEsecuzione);
  comandeLayout->addWidget(scroll_inEsecuzione);
  comandeLayout->addWidget(label_concluse);
  comandeLayout->addWidget(scroll_eseguite);
  comandeLayout->addWidget(newComanda, 0, Qt::AlignHCenter);
  comandeLayout->setContentsMargins(0,0,0,0);

  setStyleComande();
  setLayout(comandeLayout);
}

void Comande::setStyleComande(){
  comandeLayout->setSpacing(10);
  comandeLayout->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
