#include "contabilizzazione.h"
#include <iostream>
Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){
  layoutContabilizzazione = new QVBoxLayout(this);
  QLabel* scegliPeriodo = new QLabel("Scegli Periodo", this);
  QHBoxLayout* layoutDate = new QHBoxLayout();
  QLabel* labelInizio = new QLabel("Data Inizio", this);
  QDateEdit *dataInizio= new QDateEdit(this);
  dataInizio->setObjectName("dataInizio");
  QLabel* labelFine = new QLabel("Data Fine", this);
  QDateEdit* dataFine = new QDateEdit(this);
  dataFine->setObjectName("dataFine");
  QPushButton* calcola = new QPushButton("Calcola", this);
  QLabel* guadagno = new QLabel("Guadagno/Perdita", this);
  QLabel* mostraGuadagno = new QLabel("" ,this);
  mostraGuadagno->setObjectName("mGuadagno");
  connect(calcola,
          SIGNAL(clicked()),
          this,
          SLOT(calcoloFatturato()));

  layoutDate->addWidget(labelInizio);
  layoutDate->addWidget(dataInizio);
  layoutDate->addWidget(labelFine);
  layoutDate->addWidget(dataFine);
  layoutDate->addWidget(calcola);

  layoutContabilizzazione->addWidget(scegliPeriodo);
  layoutContabilizzazione->addLayout(layoutDate);
  layoutContabilizzazione->addWidget(guadagno);
  layoutContabilizzazione->addWidget(mostraGuadagno);

  setStyleContabilizzazione();
  setLayout(layoutContabilizzazione);
}

void Contabilizzazione::setStyleContabilizzazione(){}

// SLOTS
void Contabilizzazione::calcoloFatturato(){
  emit con_calcoloFatturato(
        (findChild<QDateEdit*>("dataInizio")->date()),
        (findChild<QDateEdit*>("dataFine")->date()));
}

