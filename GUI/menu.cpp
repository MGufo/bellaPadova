#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent){
  layoutMenu = new QVBoxLayout(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("ID");
  headerLabels->push_back("Nome");
  headerLabels->push_back("Disponibilità");
  headerLabels->push_back("Prezzo");
  headerLabels->push_back("Ingredienti");
  TabellaComposita* tabPizze = new TabellaComposita(this, "Pizze", headerLabels);
  tabPizze->setObjectName("tabPizze");
  headerLabels->erase(--(headerLabels->end()));
  headerLabels->push_back("Capacità");
  headerLabels->push_back("Tipologia");
  TabellaComposita* tabBevande = new TabellaComposita(this, "Bevande", headerLabels);
  tabBevande->setObjectName("tabBevande");
  layoutMenu->addWidget(tabPizze);
  layoutMenu->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout();
  QPushButton* newArticolo = new QPushButton("Nuovo Articolo", this);
  newArticolo->setObjectName("Articolo");
  connect(newArticolo, SIGNAL(clicked()), this, SLOT(drawWizard()));
  QPushButton* modificaDati = new QPushButton("Modifica", this);
  modificaDati->setObjectName("Modifica");
  layoutPulsanti->addWidget(newArticolo);
  layoutPulsanti->addWidget(modificaDati);
  layoutMenu->addLayout(layoutPulsanti);

  setStyleMenu();
  setLayout(layoutMenu);
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

