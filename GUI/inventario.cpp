#include "inventario.h"

Inventario::Inventario(QWidget *parent) : QWidget(parent){
  layoutInventario = new QVBoxLayout(this);

  headerLabels = new QStringList();
  headerLabels->push_back("ID");
  headerLabels->push_back("Nome");
  headerLabels->push_back("Disponibilità");
  headerLabels->push_back("Confezioni");
  headerLabels->push_back("Costo Acquisto");
  headerLabels->push_back("Data Acquisto");
  headerLabels->push_back("Locale");
  headerLabels->push_back("Tipo Farina");
  tabIngredienti = new TabellaRisorse(this, "Ingredienti", headerLabels);
  tabIngredienti->setHeaderDimension(TabellaRisorse::inventario);
  tabIngredienti->setObjectName("tabIngredientiInventario");
  tabIngredienti->setMaximumHeight(300);
  tabIngredienti->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  headerLabels->pop_back();
  headerLabels->pop_back();
  headerLabels->push_back("Capacità");
  headerLabels->push_back("Prezzo Vendita");
  headerLabels->push_back("Tipologia");
  tabBevande = new TabellaRisorse(this, "Bevande", headerLabels);
  tabBevande->setHeaderDimension(TabellaRisorse::bevandeI);
  tabBevande->setObjectName("tabBevandeInventario");
  tabBevande->setMaximumHeight(300);
  tabBevande->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

  setLayout(layoutInventario);
}

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
