#include "nuovoArticolo_intro.h"

NuovoArticolo_intro::NuovoArticolo_intro(QWidget* parent): QWizardPage(parent){
  setTitle("Pizza o Bevanda?");
  setSubTitle("Seleziona il tipo di articolo da inserire nel Menù");

  optionPizza = new QRadioButton("Pizza", this);
  optionPizza->setChecked(true);
  registerField("optionPizza", optionPizza);
  optionBevanda = new QRadioButton("Bevanda", this);
  registerField("optionBevanda", optionBevanda);

  layoutIntro = new QVBoxLayout(this);
  layoutIntro->addWidget(optionPizza);
  layoutIntro->addWidget(optionBevanda);
  setLayout(layoutIntro);
}

int NuovoArticolo_intro::nextId() const{
  return WizardNuovoArticolo::PAGE_Dettagli;
}
