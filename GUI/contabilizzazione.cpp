#include "contabilizzazione.h"
#include <iostream>
Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){

  // "Titolo" finestra
  QLabel* scegliPeriodo = new QLabel("Scegli Periodo", this);

  // Selezione periodo e pulsante "calcola"
  QDateEdit *dataInizio= new QDateEdit(this);
  dataInizio->setObjectName("dataInizio");
  QDateEdit* dataFine = new QDateEdit(this);
  dataFine->setObjectName("dataFine");
  QPushButton* calcola = new QPushButton("Calcola", this);
  connect(calcola, SIGNAL(clicked()), this, SLOT(calcoloFatturato()));

  // Label e risultato
  QLineEdit* mostraGuadagno = new QLineEdit("" ,this);
  mostraGuadagno->setObjectName("mGuadagno");

  // "Assemblaggio" widget figli nel main layout
  layoutContabilizzazione = new QFormLayout(this);
  layoutContabilizzazione->addWidget(scegliPeriodo);
  layoutContabilizzazione->addRow("Data Inizio: ",dataInizio);
  layoutContabilizzazione->addRow("Data Fine: ", dataFine);
  layoutContabilizzazione->addWidget(calcola);
  layoutContabilizzazione->addWidget(mostraGuadagno);

  setStyleContabilizzazione();
  setLayout(layoutContabilizzazione);
}

void Contabilizzazione::setStyleContabilizzazione(){
  layoutContabilizzazione->setAlignment(layoutContabilizzazione, Qt::AlignCenter);
}


// SLOTS
void Contabilizzazione::calcoloFatturato(){
  emit con_calcoloFatturato(
        (findChild<QDateEdit*>("dataInizio")->date()),
        (findChild<QDateEdit*>("dataFine")->date()));
}

