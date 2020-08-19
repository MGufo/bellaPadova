#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent){
  layoutMenu = new QVBoxLayout(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("ID");
  headerLabels->push_back("Nome");
  headerLabels->push_back("Disponibilità");
  headerLabels->push_back("Prezzo");
  headerLabels->push_back("Ingredienti");
  tabPizze = new TabellaRisorse(this, "Pizze", headerLabels);
  tabPizze->setHeaderDimension(TabellaRisorse::pizze);
  tabPizze->setObjectName("tabPizzeMenu");
  tabPizze->setMaximumHeight(300);
  tabPizze->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  headerLabels->erase(--(headerLabels->end()));
  headerLabels->push_back("Capacità");
  headerLabels->push_back("Tipologia");
  tabBevande = new TabellaRisorse(this, "Bevande", headerLabels);
  tabBevande->setObjectName("tabBevandeMenu");
  tabBevande->setHeaderDimension(TabellaRisorse::bevandeM);
  tabBevande->setMaximumHeight(300);
  tabBevande->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  layoutMenu->addWidget(tabPizze);
  layoutMenu->addWidget(tabBevande);
  QHBoxLayout* layoutPulsanti = new QHBoxLayout();
  newArticolo = new QPushButton("Nuovo Articolo", this);
  newArticolo->setObjectName("Articolo");
  connect(newArticolo, SIGNAL(clicked()), this, SLOT(drawWizard()));
  modificaDati = new QPushButton("Modifica", this);
  modificaDati->setObjectName("Modifica");
  connect(modificaDati, SIGNAL(clicked(bool)), this, SLOT(modificaTabelle()));

  layoutPulsanti->addWidget(newArticolo);
  layoutPulsanti->addWidget(modificaDati);
  layoutMenu->addLayout(layoutPulsanti);

  setStyleMenu();
  setLayout(layoutMenu);
}

void Menu::modificaTabelle(){
  if(modificaDati->objectName()=="Modifica"){
    newArticolo->setVisible(false);
    tabPizze->rendiEditabile();
    tabBevande->rendiEditabile();
    tabPizze->cambiaColoreBordoCella();
    modificaDati->setText("Finisci di Modificare");
    modificaDati->setObjectName("FineModifica");
  }
  else{
    newArticolo->setVisible(true);
    tabPizze->cambiaColoreBordoCella(false);
    tabPizze->rendiEditabile(false);
    tabBevande->rendiEditabile(false);
    modificaDati->setText("Modifica");
    modificaDati->setObjectName("Modifica");
  }
}

void Menu::setStyleMenu(){
  layoutMenu->setSpacing(0);
  layoutMenu->setMargin(0);
  layoutMenu->setContentsMargins(-1,0,-1,-1);
  setMinimumSize(QSize(900,300));
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

// SLOTS
void Menu::drawWizard(){
  if(nuovoArticolo) delete nuovoArticolo;
  nuovoArticolo = new WizardNuovoArticolo(this);
  nuovoArticolo->show();

}

void Menu::invioDatiArticolo(){}

