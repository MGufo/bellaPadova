#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Disponibilità");
  headerLabels->push_back("Confezioni");
  headerLabels->push_back("Costo d'acquisto");
  headerLabels->push_back("Data Acquisto");
  headerLabels->push_back("Locale");
  TabellaComposita* tabIngredienti = new TabellaComposita(this, "Ingredienti", headerLabels);
  tabIngredienti->setObjectName("tabIngredienti");
  headerLabels->pop_back();
  headerLabels->push_back("Capacità");
  headerLabels->push_back("Prezzo di vendita");
  headerLabels->push_back("Tipologia");
  TabellaComposita* tabBevande = new TabellaComposita(this, "Bevande", headerLabels);
  tabBevande->setObjectName("tabBevande");

  layoutInventario->addWidget(tabIngredienti);
  layoutInventario->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout();
  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);
  newConsumabile->setObjectName("Consumabile");
  connect(newConsumabile, SIGNAL(clicked()), this, SLOT(drawWizard()));
  QPushButton* modificaDati = new QPushButton("Modifica", this);
  modificaDati->setObjectName("Modifica");
  layoutPulsanti->addWidget(newConsumabile);
  layoutPulsanti->addWidget(modificaDati);
  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}

// SLOT
void Inventario::drawWizard(){
  nuovoConsumabile = new WizardNuovoConsumabile(this);
  nuovoConsumabile->show();
}
