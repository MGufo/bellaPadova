#include "nuovoArticolo_pizza.h"

NuovoArticolo_pizza::NuovoArticolo_pizza(QWidget *parent) : QWizardPage(parent){
  setTitle("Aggiunta di una nuova pizza al Menù");
  setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi "
              "aggiungi gli ingredienti che la compongono");

  // Informazioni pizza
  QWidget* wrapperInfo = new QWidget(this);
  QLineEdit* nome = new QLineEdit(wrapperInfo);
  registerField("nomePizza*", nome);
  QLineEdit* prezzo = new QLineEdit(wrapperInfo);
  registerField("prezzoPizza*", prezzo);
  QFormLayout* layoutInfo = new QFormLayout(wrapperInfo);
  layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
  layoutInfo->addRow("Nome pizza:", nome);
  layoutInfo->addRow("Prezzo pizza:", prezzo);

  // Ingredienti base pizza
  QWidget* wrapperBasePizza = new QWidget(this);
  QCheckBox* pomodoro = new QCheckBox("Pomodoro", wrapperBasePizza);
  QCheckBox* mozzarella = new QCheckBox("Mozzarella", wrapperBasePizza);
  QVBoxLayout* layoutBase = new QVBoxLayout(wrapperBasePizza);
  layoutBase->addWidget(pomodoro);
  layoutBase->addWidget(mozzarella);

  // Ingredienti
  QScrollArea* scrollArea = new QScrollArea(this);
  QWidget* checkboxWrapper = new QWidget(scrollArea);
  QVBoxLayout* checkboxLayout = new QVBoxLayout(checkboxWrapper);
  for(int i=0; i<10; ++i){
    QCheckBox* checkBox = new QCheckBox(checkboxWrapper);
    checkboxLayout->addWidget(checkBox);
  }
  scrollArea->setWidget(checkboxWrapper);

  layoutPizza = new QGridLayout(this);
  layoutPizza->addWidget(wrapperInfo,0,0,2,4);
  layoutPizza->addWidget(wrapperBasePizza,0,4,2,2);
  layoutPizza->addWidget(scrollArea, 3, 0, 6, 6);
  setLayout(layoutPizza);
}

int NuovoArticolo_pizza::nextId() const{
    return WizardNuovoArticolo::PAGE_End;
}
