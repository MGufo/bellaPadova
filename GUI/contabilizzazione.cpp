#include "contabilizzazione.h"
#include <iostream>
Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){

  // "Titolo" finestra
  QLabel* scegliPeriodo = new QLabel("Scegli Periodo", this);
  scegliPeriodo->setObjectName("scegliPeriodo");
  QLabel* guadagnoPerdita = new QLabel("Guadagno/Perdita", this);
  guadagnoPerdita->setObjectName("guadagnoPerdita:");
  QWidget* wrapper_Date = new QWidget(this);
  QLabel* labelInizio = new QLabel("Data Inizio: ", wrapper_Date);
  QLabel* labelFine = new QLabel("Data Fine: ", wrapper_Date);
  // Selezione periodo e pulsante "calcola"
  QDateEdit *dataInizio= new QDateEdit(wrapper_Date);
  dataInizio->setObjectName("dataInizio");
  QDateEdit* dataFine = new QDateEdit(wrapper_Date);
  dataFine->setObjectName("dataFine");
  QPushButton* calcola = new QPushButton("Calcola", this);
  calcola->setObjectName("Calcola");
  connect(calcola, SIGNAL(clicked()), this, SLOT(calcoloFatturato()));

  // Label e risultato
  QLineEdit* mostraGuadagno = new QLineEdit("" ,this);
  mostraGuadagno->setObjectName("mGuadagno");

  // "Assemblaggio" widget figli nel main layout
  layoutContabilizzazione = new QVBoxLayout(this);
  layoutDate = new QHBoxLayout(wrapper_Date);
  layoutContabilizzazione->addWidget(scegliPeriodo);
  layoutDate->addWidget(labelInizio);
  layoutDate->addWidget(dataInizio);
  layoutDate->addWidget(labelFine);
  layoutDate->addWidget(dataFine);
  layoutContabilizzazione->addWidget(wrapper_Date);
  layoutContabilizzazione->addWidget(calcola, 0, Qt::AlignCenter);
  layoutContabilizzazione->addWidget(guadagnoPerdita);
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
