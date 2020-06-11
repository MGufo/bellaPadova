#include "nuovoConsumabile_intro.h"
nuovoConsumabile_intro::nuovoConsumabile_intro(QWidget* parent):QWizardPage
                                                                (parent){
  setTitle("Ingrediente o bevanda?");
  setSubTitle("Seleziona il tipo di consumabile da inserire nell'Inventario");

  optionIngrediente = new QRadioButton("Ingrediente");
  optionIngrediente->setChecked(true);
  registerField("optionIngrediente", optionIngrediente);
  optionBevanda = new QRadioButton("Bevanda");
  registerField("optionBevanda", optionBevanda);

  layoutIntro = new QVBoxLayout(this);
  layoutIntro->addWidget(optionIngrediente);
  layoutIntro->addWidget(optionBevanda);
  setLayout(layoutIntro);
}

int nuovoConsumabile_intro::nextId() const{
  return WizardNuovoConsumabile::PAGE_Dettagli;
}

void nuovoConsumabile_intro::initializePage(){
  QWizardPage::initializePage();
}
