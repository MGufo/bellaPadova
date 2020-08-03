#include "nuovoConsumabile_intro.h"
nuovoConsumabile_intro::nuovoConsumabile_intro(QWidget* parent):QWizardPage
                                                                (parent){
  setTitle("Bevanda, Ingrediente o Farina?");
  setSubTitle("Seleziona il tipo di elemento che vuoi inserire nell'inventario");

  optionBevanda = new QRadioButton("Bevanda");
  registerField("optionBevanda", optionBevanda);
  optionIngrediente = new QRadioButton("Ingrediente");
  optionIngrediente->setChecked(true);
  registerField("optionIngrediente", optionIngrediente);
  optionFarina = new QRadioButton("Farina");
  registerField("optionFarina", optionFarina);

  layoutIntro = new QVBoxLayout(this);
  layoutIntro->addWidget(optionBevanda);
  layoutIntro->addWidget(optionIngrediente);
  layoutIntro->addWidget(optionFarina);
  setLayout(layoutIntro);
}

int nuovoConsumabile_intro::nextId() const{
  return WizardNuovoConsumabile::PAGE_Dettagli;
}
