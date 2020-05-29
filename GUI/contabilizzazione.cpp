#include "contabilizzazione.h"

Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){
  layoutContabilizzazione = new QVBoxLayout(this);

  QLabel* scegliPeriodo = new QLabel("Scegli Periodo: ", this);

  QHBoxLayout* layoutDate = new QHBoxLayout(this);
  QLabel* labelInizio = new QLabel("Data Inizio:");
  QDateEdit* dataInizio = new QDateEdit();
  QLabel* labelFine = new QLabel("Data Fine:");
  QDateEdit* dataFine = new QDateEdit();
  QPushButton* btnCalcola = new QPushButton("Calcola");

  layoutDate->addWidget(labelInizio);
  layoutDate->addWidget(dataInizio);
  layoutDate->addWidget(labelFine);
  layoutDate->addWidget(dataFine);
  layoutDate->addWidget(btnCalcola);

  QLabel* risultato = new QLabel("Guadagno/Perdita: ", this);

  QPlainTextEdit* mostraRisultato = new QPlainTextEdit(this);

  layoutContabilizzazione->addWidget(scegliPeriodo);
  layoutContabilizzazione->addLayout(layoutDate);
  layoutContabilizzazione->addWidget(risultato);
  layoutContabilizzazione->addWidget(mostraRisultato);

  setStyleContabilizzazione();
  setLayout(layoutContabilizzazione);
}

void Contabilizzazione::setStyleContabilizzazione(){

}
