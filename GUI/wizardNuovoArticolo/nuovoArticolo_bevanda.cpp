#include "wizard_bevanda.h"

WizardPage_bevanda::WizardPage_bevanda(QWidget* parent) : QWizardPage(parent){
  setTitle("Aggiunta di una nuova bevanda al Menù");
  setSubTitle("Seleziona il formato della bevanda, poi specificane nome, costo e capacità");

  // Tipologia bevanda
  QWidget* tipologiaWrapper = new QWidget(this);
  QRadioButton* radioBottiglia = new QRadioButton("Bottiglia", tipologiaWrapper);
  radioBottiglia->setChecked(true);
  QRadioButton* radioLattina = new QRadioButton("Lattina", tipologiaWrapper);
  QHBoxLayout* layoutTipologia = new  QHBoxLayout(tipologiaWrapper);
  layoutTipologia->addWidget(radioBottiglia);
  layoutTipologia->addWidget(radioLattina);

  // Informazioni Bevanda
  QWidget* infoWrapper = new QWidget(this);
  QFormLayout* layoutInfo = new QFormLayout(infoWrapper);
  layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
  QLineEdit* nome = new QLineEdit(infoWrapper);
  registerField("nomeBevanda*", nome);
  QLineEdit* prezzo = new QLineEdit(infoWrapper);
  registerField("prezzoBevanda*", prezzo);
  QLineEdit* capacita = new QLineEdit(infoWrapper);
  registerField("capacitaBevanda*", capacita);
  layoutInfo->addRow("Nome", nome);
  layoutInfo->addRow("Prezzo", prezzo);
  layoutInfo->addRow("Capacità", capacita);

  layoutBevanda = new QVBoxLayout(this);
  layoutBevanda->addWidget(tipologiaWrapper);
  layoutBevanda->addWidget(infoWrapper);
  setLayout(layoutBevanda);
}

int WizardPage_bevanda::nextId() const{
  return WizardNuovoArticolo::PAGE_End;
}
