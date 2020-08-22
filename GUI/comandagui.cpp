#include "comandagui.h"

ComandaGUI::ComandaGUI(QWidget *parent, pacchettoComanda* pC) : QWidget(parent){
  // Info comanda
  ID = pC->ID;
  eseguita = pC->eseguita;
  oraConsegna = pC->oraConsegna;
  nomeCliente = QString::fromStdString(pC->nome);
  layoutComanda = new QVBoxLayout(this);
  wrapperComanda = new QPushButton(this);
  wrapperComanda->setObjectName("wrapperComanda");
  layoutWrapper = new QVBoxLayout(wrapperComanda);
  layoutButtons = new QHBoxLayout();
  orario = new QLabel(oraConsegna.toString("hh:mm"), wrapperComanda);
  orario->setObjectName("Orario");
  contenutoID = "Comanda " + QString::fromStdString(std::to_string(ID));
  comandaId = new QLabel(contenutoID, wrapperComanda);
  comandaId->setObjectName("ComandaId");
  rimuovi = new QPushButton("Rimuovi", wrapperComanda);
  rimuovi->setObjectName("Rimuovi");
  layoutButtons->addWidget(rimuovi);

  layoutWrapper->addWidget(orario);
  layoutWrapper->addWidget(comandaId);
  layoutWrapper->addLayout(layoutButtons);
  wrapperComanda->setLayout(layoutWrapper);

  layoutComanda->addWidget(wrapperComanda);
  setLayout(layoutComanda);

  rimuovi->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  wrapperComanda->setMinimumHeight(200);
  wrapperComanda->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
  connect(wrapperComanda, SIGNAL(clicked()), this, SLOT(showDetails()));
  connect(rimuovi, SIGNAL(clicked()), this, SLOT(removeClicked()));
  connect(this, SIGNAL(eliminaComanda(uint)),
          parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(eliminaComanda(uint)));
  connect(this, SIGNAL(getInfoComanda(uint)),
          parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(richiediDettagliComanda(uint)));
}

void ComandaGUI::rendiEseguita(){
  wrapperComanda->setObjectName("wrapperComandaEseguita");
  wrapperComanda->setMinimumHeight(80);
  orario->setObjectName("orarioEseguita");
  comandaId->setObjectName("comandaIdEseguita");
  delete rimuovi;
}

void ComandaGUI::showDetails(){
  dettagli = new PaginaComanda(this, ID);
  connect(this, SIGNAL(disableEdit()), dettagli, SLOT(disableEdit()));
  if(eseguita) emit disableEdit();
  dettagli->setWindowFlags(Qt::Window);
  wrapperComanda->setEnabled(false);
  dettagli->setWindowTitle(contenutoID);
  emit getInfoComanda(ID);
  dettagli->show();
}

void ComandaGUI::enableButton(){
  wrapperComanda->setEnabled(true);
  delete dettagli;
}

void ComandaGUI::removeClicked(){ emit eliminaComanda(ID); }

uint ComandaGUI::getID() const { return ID; }

QTime ComandaGUI::getOraConsegna() const { return oraConsegna; }
