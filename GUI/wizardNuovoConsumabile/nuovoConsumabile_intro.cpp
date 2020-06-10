#include "nuovoConsumabile_intro.h"
#include <iostream>
nuovoConsumabile_intro::nuovoConsumabile_intro(QWidget* parent):QWizardPage
                                                                (parent){
  setTitle("Ingrediente o bevanda?");
  setSubTitle("Seleziona il tipo di consumabile da inserire nell'Inventario");

  optionIngrediente = new QRadioButton("Ingrediente", this);
  optionIngrediente->setChecked(true);
  registerField("optionIngrediente", optionIngrediente);
  optionBevanda = new QRadioButton("Bevanda",this);
  registerField("optionBevanda", optionBevanda);

  layoutIntro = new QVBoxLayout(this);
  layoutIntro->addWidget(optionIngrediente);
  layoutIntro->addWidget(optionBevanda);
  setLayout(layoutIntro);
  bool tmp = field("optionIngrediente").toBool();
  if (tmp)
    std::cout << "ghesboro" << std::endl;
  else
    std:: cout <<"madonna luia" << std::endl;
}

int nuovoConsumabile_intro::nextId() const{
  return WizardNuovoConsumabile::PAGE_Dettagli;
}
