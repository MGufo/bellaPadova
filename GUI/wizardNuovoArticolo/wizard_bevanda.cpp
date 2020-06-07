#include "wizard_bevanda.h"

wizard_bevanda::wizard_bevanda(QWidget* parent) : QWizardPage(parent){
  setTitle("Aggiunta di una nuova bevanda al Menù");
  setSubTitle("Seleziona il formato della bevanda, poi specificane nome, costo e capacità");

  // Tipologia bevanda
  QWidget* tipologiaWrapper = new QWidget(this);
  QRadioButton* radioBottiglia = new QRadioButton("Bottiglia", tipologiaWrapper);
  QRadioButton* radioLattina = new QRadioButton("Lattina", tipologiaWrapper);
  QHBoxLayout* layoutTipologia = new  QHBoxLayout(tipologiaWrapper);
  layoutTipologia->addWidget(radioBottiglia);
  layoutTipologia->addWidget(radioLattina);

  // Informazioni Bevanda
  QWidget* infoWrapper = new QWidget(this);
  QFormLayout* layoutInfo = new QFormLayout(infoWrapper);
  QTextEdit* nome = new QTextEdit(infoWrapper);
  QTextEdit* prezzo = new QTextEdit(infoWrapper);
  QTextEdit* capacita = new QTextEdit(infoWrapper);
  layoutInfo->addRow("Nome", nome);
  layoutInfo->addRow("Prezzo", prezzo);
  layoutInfo->addRow("Capacità", capacita);

  layoutBevanda = new QVBoxLayout(this);
  layoutBevanda->addWidget(tipologiaWrapper);
  layoutBevanda->addWidget(infoWrapper);

  setLayout(layoutBevanda);
}

int wizard_bevanda::nextId() const{
  return WizardNuovoArticolo::PAGE_End;
}
