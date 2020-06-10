#include "nuovoArticolo_intro.h"

NuovoArticolo_intro::NuovoArticolo_intro(QWidget* parent): QWizardPage(parent){
  setTitle("Pizza o Bevanda?");
  setSubTitle("Seleziona il tipo di articolo da inserire nel Menù");

  layoutIntro = new QVBoxLayout(this);

  optionPizza = new QRadioButton("Pizza", this);
  optionBevanda = new QRadioButton("Bevanda", this);
  optionPizza->setChecked(true);

  layoutIntro->addWidget(optionPizza);
  layoutIntro->addWidget(optionBevanda);

  setLayout(layoutIntro);
}

int NuovoArticolo_intro::nextId() const{
  if(optionPizza->isChecked())
    return WizardNuovoArticolo::PAGE_Pizza;
  else if(optionBevanda->isChecked())
    return WizardNuovoArticolo::PAGE_Bevanda;
  else
    return WizardNuovoArticolo::PAGE_Intro;
}
