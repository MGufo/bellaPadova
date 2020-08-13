#include "comandagui.h"

ComandaGUI::ComandaGUI(QWidget *parent, pacchettoComanda* pC) : QWidget(parent){
  // Info comanda
  if(pC){
    ID = pC->ID;
    oraConsegna = pC->oraConsegna;
    nomeCliente = pC->nome;
  }
  layoutComanda = new QVBoxLayout(this);
  wrapperComanda = new QPushButton(this);
  wrapperComanda->setObjectName("wrapperComanda");
  QVBoxLayout* layoutWrapper = new QVBoxLayout(wrapperComanda);
  QHBoxLayout* layoutButtons = new QHBoxLayout();
  QLabel* orario = new QLabel("Orario", wrapperComanda);
  orario->setObjectName("Orario");
  QLabel* comandaId = new QLabel("Comanda ", wrapperComanda);
  comandaId->setObjectName("ComandaId");
  rimuovi = new QPushButton("Rimuovi", wrapperComanda);
  rimuovi->setObjectName("Rimuovi");
  completata = new QPushButton("Completata", wrapperComanda);
  completata->setObjectName("Completata");
  layoutButtons->addWidget(rimuovi);
  layoutButtons->addWidget(completata);

  layoutWrapper->addWidget(orario);
  layoutWrapper->addWidget(comandaId);
  layoutWrapper->addLayout(layoutButtons);
  wrapperComanda->setLayout(layoutWrapper);

  layoutComanda->addWidget(wrapperComanda);
  setLayout(layoutComanda);

  rimuovi->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  completata->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  wrapperComanda->setMinimumHeight(200);
  wrapperComanda->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
  connect(wrapperComanda, SIGNAL(pressed()), this, SLOT(showDetails()));
}

void ComandaGUI::showDetails(){
  dettagli = new PaginaComanda(this);
  dettagli->setWindowFlags(Qt::Window);
  dettagli->show();
}
