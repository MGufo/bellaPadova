#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("ID");
  headerLabels->push_back("Nome");
  headerLabels->push_back("Disponibilità");
  headerLabels->push_back("Confezioni");
  headerLabels->push_back("Costo d'acquisto");
  headerLabels->push_back("Data Acquisto");
  headerLabels->push_back("Locale");
  tabIngredienti = new TabellaComposita(this, "Ingredienti e Farine", headerLabels);
  tabIngredienti->setObjectName("tabIngredienti");
  headerLabels->pop_back();
  headerLabels->push_back("Capacità");
  headerLabels->push_back("Prezzo di vendita");
  headerLabels->push_back("Tipologia");
  tabBevande = new TabellaComposita(this, "Bevande", headerLabels);
  tabBevande->setObjectName("tabBevande");

  layoutInventario->addWidget(tabIngredienti);
  layoutInventario->addWidget(tabBevande);

  QHBoxLayout* layoutPulsanti = new QHBoxLayout();
  newConsumabile = new QPushButton("Nuovo Consumabile", this);
  newConsumabile->setObjectName("Consumabile");
  connect(newConsumabile, SIGNAL(clicked()), this, SLOT(drawWizard()));
  modificaDati = new QPushButton("Modifica", this);
  modificaDati->setObjectName("Modifica");
  connect(modificaDati,SIGNAL(clicked(bool)),this,SLOT(modificaTabelle()));

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

void Inventario::modificaTabelle(){
    if(modificaDati->objectName()=="Modifica"){
        newConsumabile->setVisible(false);
        tabIngredienti->rendiEditabile();
        tabBevande->rendiEditabile();
        tabIngredienti->cambiaColoreBordoCella();
        tabBevande->cambiaColoreBordoCella();
        modificaDati->setText("Finisci di Modificare");
        modificaDati->setObjectName("FineModifica");
    }
    else{
        newConsumabile->setVisible(true);
        tabIngredienti->cambiaColoreBordoCella(false);
        tabBevande->cambiaColoreBordoCella(false);
        tabIngredienti->rendiEditabile(false);
        tabBevande->rendiEditabile(false);
        modificaDati->setText("Modifica");
        modificaDati->setObjectName("Modifica");
    }
}
