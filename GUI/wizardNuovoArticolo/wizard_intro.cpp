#include "wizard_intro.h"

Wizard_intro::Wizard_intro(QWidget* parent): QWizardPage(parent){
  setTitle("Pizza o Bevanda?");
  setSubTitle("Seleziona la tipologia di articolo da inserire nel Menù");

  layoutIntro = new QVBoxLayout(this);

//  QLabel* prompt = new QLabel(this);
//  prompt->setText("Seleziona la tipologia di articolo da inserire nel Menù:");
//  prompt->setWordWrap(true);

  optionPizza = new QRadioButton("Pizza", this);
  optionBevanda = new QRadioButton("Bevanda", this);
  optionPizza->setChecked(true);

//layoutIntro->addWidget(prompt);
  layoutIntro->addWidget(optionPizza);
  layoutIntro->addWidget(optionBevanda);

  setLayout(layoutIntro);
}

int Wizard_intro::nextId() const{
  if(optionPizza->isChecked())
    return WizardNuovoArticolo::PAGE_Pizza;
  else if(optionBevanda->isChecked())
    return WizardNuovoArticolo::PAGE_Bevanda;
  else
    return WizardNuovoArticolo::PAGE_End;
}
