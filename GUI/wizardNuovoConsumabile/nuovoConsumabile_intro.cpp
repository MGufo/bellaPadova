#include "nuovoConsumabile_intro.h"

nuovoConsumabile_intro::nuovoConsumabile_intro(QWidget* parent):QWizardPage
                                                                (parent){
  setTitle("Ingrediente o bevanda?");
  setSubTitle("Seleziona il tipo di consumabile da inserire nell'Inventario");

  optionIngrediente = new QRadioButton("Ingrediente", this);
  optionIngrediente->setChecked(true);
  optionBevanda = new QRadioButton("Bevanda",this);

  layoutIntro = new QVBoxLayout(this);
  layoutIntro->addWidget(optionIngrediente);
  layoutIntro->addWidget(optionBevanda);
  setLayout(layoutIntro);
}

int nuovoConsumabile_intro::nextId() const{
  if(optionBevanda->isChecked())
    return WizardNuovoConsumabile::PAGE_Bevanda;
  return WizardNuovoConsumabile::PAGE_Ingrediente;
}
