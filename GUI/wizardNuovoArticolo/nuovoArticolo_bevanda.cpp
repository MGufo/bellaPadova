#include "nuovoArticolo_bevanda.h"

NuovoArticolo_bevanda::NuovoArticolo_bevanda(QWidget* parent) : QWizardPage(parent){
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
  QLineEdit* nomeBevanda = new QLineEdit(infoWrapper);
  registerField("nomeBevanda*", nomeBevanda);
  QLineEdit* prezzoBevanda = new QLineEdit(infoWrapper);
  registerField("prezzoBevanda*", prezzoBevanda);
  QLineEdit* capacitaBevanda = new QLineEdit(infoWrapper);
  registerField("capacitaBevanda*", capacitaBevanda);
  layoutInfo->addRow("Nome", nomeBevanda);
  layoutInfo->addRow("Prezzo", prezzoBevanda);
  layoutInfo->addRow("Capacità", capacitaBevanda);

  layoutBevanda = new QVBoxLayout(this);
  layoutBevanda->addWidget(tipologiaWrapper);
  layoutBevanda->addWidget(infoWrapper);
  setLayout(layoutBevanda);
}

int NuovoArticolo_bevanda::nextId() const{
  return WizardNuovoArticolo::PAGE_End;
}
