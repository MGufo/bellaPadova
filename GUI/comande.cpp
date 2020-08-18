#include "comande.h"

Comande::Comande(QWidget *parent) : QWidget(parent){

  /////////////////////////////////
  // Sezione comande da eseguire //
  /////////////////////////////////

  QLabel* label_inEsecuzione = new QLabel("In Esecuzione:", this);
  label_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_inEsecuzione->setObjectName("inEsecuzione");
  scroll_inEsecuzione = new QScrollArea(this);
  wrapper_inEsecuzione = new QWidget(scroll_inEsecuzione);
  wrapper_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  wrapper_inEsecuzione->setObjectName("wrapperInEsecuzione");
  wrapper_inEsecuzione->setContentsMargins(0, 1, 0, 1);
//  ComandaGUI* comanda3 = new ComandaGUI(wrapper_inEsecuzione);
//  comanda3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//  ComandaGUI* comanda4 = new ComandaGUI(wrapper_inEsecuzione);
//  comanda4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  layout_inEsecuzione = new QHBoxLayout(scroll_inEsecuzione);
  wrapper_inEsecuzione->setLayout(layout_inEsecuzione);
  //layout_inEsecuzione->addWidget(comanda1);
  //layout_inEsecuzione->addWidget(comanda2);+
  scroll_inEsecuzione->setWidget(wrapper_inEsecuzione);
  scroll_inEsecuzione->setMinimumSize(580, 265);
  scroll_inEsecuzione->setMaximumHeight(340);
  scroll_inEsecuzione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  scroll_inEsecuzione->setWidgetResizable(true);

  //////////////////////////////
  // Sezione comande eseguite //
  //////////////////////////////

  QLabel* label_concluse = new QLabel("Concluse:", this);
  label_concluse->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_concluse->setObjectName("concluse");
  scroll_eseguite = new QScrollArea(this);
  scroll_eseguite->setContentsMargins(0, 1, 0, 1);

  wrapper_eseguite = new QWidget(scroll_eseguite);
  wrapper_eseguite->setObjectName("wrapperEseguite");

  layout_eseguite = new QHBoxLayout(wrapper_eseguite);
  wrapper_eseguite->setLayout(layout_eseguite);
  scroll_eseguite->setWidget(wrapper_eseguite);
  scroll_eseguite->setMinimumSize(580, 100);
  scroll_eseguite->setMaximumHeight(200);
  scroll_eseguite->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  //////////////////////////////
  // Sezione bottoni in fondo //
  //////////////////////////////

  newComanda = new QPushButton(this);
  newComanda->setText("Nuova Comanda");
  newComanda->setObjectName("newComanda");
  newComanda->setMaximumHeight(90);

  prossimaComanda = new QPushButton(this);
  prossimaComanda->setText("Esegui Comanda Corrente");
  prossimaComanda->setObjectName("eseguiComanda");
  prossimaComanda->setMaximumHeight(90);

  wrapper_bottoniComande = new QWidget(this);
  wrapper_bottoniComande->setObjectName("wrapperBottoni");
  layout_bottoni = new QHBoxLayout(wrapper_bottoniComande);
  layout_bottoni->addWidget(newComanda);
  layout_bottoni->addWidget(prossimaComanda);
  wrapper_bottoniComande->setLayout(layout_bottoni);

  comandeLayout = new QVBoxLayout(this);
  comandeLayout->addWidget(label_inEsecuzione);
  comandeLayout->addWidget(scroll_inEsecuzione);
  comandeLayout->addWidget(label_concluse);
  comandeLayout->addWidget(scroll_eseguite);
  comandeLayout->addWidget(wrapper_bottoniComande);
  comandeLayout->setContentsMargins(0,0,0,0);

  connect(newComanda, SIGNAL(clicked()), this, SLOT(drawWizard()));

  connect(prossimaComanda, SIGNAL(clicked()),
          this, SLOT(eseguiComandaHandler()));

  connect(this, SIGNAL(eseguiComanda()),
          parentWidget()->parentWidget(), SLOT(aumentaCurrent()));

  connect(this, SIGNAL(checkNextOrderButtonStatus(bool)),
          this, SLOT(setStyleNextOrderButton(bool)));

  setStyleComande();
  setLayout(comandeLayout);
  setObjectName("widgetComande");
}

void Comande::aggiungiComanda(pacchettoComanda* pC){
  ComandaGUI* comanda = new ComandaGUI(this, pC);
    if(pC->eseguita)
      layout_eseguite->addWidget(comanda);
    else{
      layout_inEsecuzione->addWidget(comanda);
      emit setStyleNextOrderButton(true);
    }
}

uint Comande::getPrimaComanda(const QList<ComandaGUI*>& comandeGUI) const{
  QTime t(23,59,59);
  auto ptr = comandeGUI.cbegin();
  for(auto it = comandeGUI.cbegin(); it != comandeGUI.cend(); ++it)
    if(((*it)->getOraConsegna()) < t) ptr = it;
  return (*ptr)->getID();
}

void Comande::setStyleComande(){
  comandeLayout->setSpacing(10);
  comandeLayout->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void Comande::drawWizard(){
  nuovaComanda = new WizardNuovaComanda(this);
  nuovaComanda->show();
}

void Comande::eseguiComandaHandler(){
  QList<ComandaGUI*> comandeGUI = findChildren<ComandaGUI*>();
  if(!comandeGUI.isEmpty())
    //getPrimaComanda(comandeGUI)
    emit eseguiComanda();
  else
    emit checkNextOrderButtonStatus(false);
}

void Comande::setStyleNextOrderButton(bool status){
    prossimaComanda->setEnabled(status);
}

  // TODO: usare findChildren per ottenere il primo figlio di tipo comandaGUI.
  // se findChildren non restituisce il primo figlio toccherà rompersi il cazzo
  // con una funzione findMin che confronti gli orari di consegna (QTime )
