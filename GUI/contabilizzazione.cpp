#include "contabilizzazione.h"

Contabilizzazione::Contabilizzazione(QWidget *parent) : QWidget(parent){
  layoutContabilizzazione = new QVBoxLayout(this);
  QLabel* scegliPeriodo = new QLabel("Scegli Periodo", this);
  QHBoxLayout* layoutDate = new QHBoxLayout();
  QLabel* labelInizio = new QLabel("Data Inizio", this);
  QDateEdit* dataInizio = new QDateEdit(this);
  QLabel* labelFine = new QLabel("Data Fine", this);
  QDateEdit* dataFine = new QDateEdit();
  QPushButton* calcola = new QPushButton("Calcola", this);
  QLabel* guadagno = new QLabel("Guadagno/Perdita", this);
  QTextEdit* mostraGuadagno = new QTextEdit(this);

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
