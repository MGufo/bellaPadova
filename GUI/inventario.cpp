#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);
  nuovoArticolo = new WizardNuovoArticolo(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Confezioni");
  headerLabels->push_back("Costo");
  headerLabels->push_back("Data Acquisto");
  headerLabels->push_back("Locale");
  TabellaComposita* tabIngredienti = new TabellaComposita(this, "Ingredienti", headerLabels);

  headerLabels->push_back("Capacità");
  TabellaComposita* tabBevande = new TabellaComposita(this, "Bevande", headerLabels);

  layoutInventario->addWidget(tabIngredienti);
  layoutInventario->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout(this);
  QPushButton* newConsumabile = new QPushButton("Nuovo Consumabile", this);
  connect(newConsumabile, SIGNAL(clicked()), this, SLOT(drawWizard()));
  QPushButton* modificaDati = new QPushButton("Modifica", this);
  layoutPulsanti->addWidget(newConsumabile);
  layoutPulsanti->addWidget(modificaDati);
  layoutInventario->addLayout(layoutPulsanti);

  setStyleInventario();
  setLayout(layoutInventario);
}

void Inventario::setStyleInventario(){}

// SLOT
void Inventario::drawWizard(){
  nuovoArticolo = new WizardNuovoArticolo(this);
  nuovoArticolo->show();
}
