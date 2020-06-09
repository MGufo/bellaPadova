#include "contabilizzazione.h"
#include <iostream>
Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){

  // "Titolo" finestra
  QLabel* scegliPeriodo = new QLabel("Scegli Periodo", this);

  // Selezione periodo e pulsante "calcola"
  QHBoxLayout* layoutDate = new QHBoxLayout();
  QLabel* labelInizio = new QLabel("Data Inizio", this);
  QDateEdit *dataInizio= new QDateEdit(this);
  dataInizio->setObjectName("dataInizio");
  QLabel* labelFine = new QLabel("Data Fine", this);
  QDateEdit* dataFine = new QDateEdit(this);
  dataFine->setObjectName("dataFine");
  QPushButton* calcola = new QPushButton("Calcola", this);
  connect(calcola, SIGNAL(clicked()), this, SLOT(calcoloFatturato()));

  layoutDate->addWidget(labelInizio);
  layoutDate->addWidget(dataInizio);
  layoutDate->addWidget(labelFine);
  layoutDate->addWidget(dataFine);
  layoutDate->addWidget(calcola);

  // Label e risultato
  QHBoxLayout* layoutRisultato = new QHBoxLayout();
  QLabel* guadagno = new QLabel("Guadagno/Perdita:", this);
  QLineEdit* mostraGuadagno = new QLineEdit("" ,this);
  mostraGuadagno->setObjectName("mGuadagno");

  layoutRisultato->addWidget(guadagno);
  layoutRisultato->addWidget(mostraGuadagno);

  // "Assemblaggio" widget figli nel main layout
  layoutContabilizzazione = new QVBoxLayout(this);

  layoutContabilizzazione->addWidget(scegliPeriodo);
  layoutContabilizzazione->addLayout(layoutDate);
  layoutContabilizzazione->addLayout(layoutRisultato);

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

