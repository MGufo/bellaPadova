#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent){
  layoutMenu = new QVBoxLayout(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Ingredienti");
  headerLabels->push_back("Prezzo");
  TabellaComposita* tabPizze = new TabellaComposita(this, "Pizze", headerLabels);
  headerLabels->erase(++(headerLabels->begin()));
  TabellaComposita* tabBevande = new TabellaComposita(this, "Bevande", headerLabels);

  layoutMenu->addWidget(tabPizze);
  layoutMenu->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);
  QPushButton* newArticolo = new QPushButton("Nuovo Articolo", this);
  connect(newArticolo, SIGNAL(clicked()), this, SLOT(drawWizard()));
  QPushButton* modificaDati = new QPushButton("Modifica", this);
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
  nuovoArticolo = new WizardNuovoArticolo(this);
  nuovoArticolo->show();
}
