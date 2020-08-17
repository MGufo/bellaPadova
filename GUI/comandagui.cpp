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
  QVBoxLayout* layoutWrapper = new QVBoxLayout(wrapperComanda);
  QHBoxLayout* layoutButtons = new QHBoxLayout();
  QLabel* orario = new QLabel(oraConsegna.toString("hh:mm"), wrapperComanda);
  orario->setObjectName("Orario");
  QString contenutoID = "Comanda " + QString::fromStdString(std::to_string(ID));
  QLabel* comandaId = new QLabel(contenutoID, wrapperComanda);
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

  setWindowTitle(contenutoID);
}

void ComandaGUI::showDetails(){
  dettagli = new PaginaComanda(this);
  dettagli->setWindowFlags(Qt::Window);
  wrapperComanda->setEnabled(false);
  dettagli->show();
}

void ComandaGUI::enableButton(){ wrapperComanda->setEnabled(true); }

void ComandaGUI::removeClicked(){ emit eliminaComanda(ID); }

uint ComandaGUI::getID() const { return ID; }

QTime ComandaGUI::getOraConsegna() const { return oraConsegna; }
