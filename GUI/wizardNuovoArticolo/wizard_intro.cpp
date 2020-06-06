#include "wizard_intro.h"

wizard_Intro::wizard_Intro(): QWizardPage(parent){
  layoutIntro = new QVBoxLayout(this);

  QLabel* prompt = new QLabel(this);
  prompt->setText("Seleziona la tipologia di articolo da inserire al Menù:");
  prompt->setWordWrap(true);

  QRadioButton* optionPizza = new QRadioButton("Pizza", this);
  QRadioButton* optionBevanda = new QRadioButton("Bevanda", this);
  optionPizza->setChecked(true);

  layoutIntro->addWidget(prompt);
  layoutIntro->addWidget(optionPizza);
  layoutIntro->addWidget(optionBevanda);

  setLayout(layoutIntro);
  setSubTitle("Pizza o Bevanda?");
}
