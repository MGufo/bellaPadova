#include "nuovoArticolo_pizza.h"

NuovoArticolo_pizza::NuovoArticolo_pizza(QWidget *parent) : QWidget(parent){

  // Informazioni pizza
  QWidget* wrapperInfo = new QWidget(this);
  nomePizza = new QLineEdit(wrapperInfo);
  prezzoPizza = new QLineEdit(wrapperInfo);
  QFormLayout* layoutInfo = new QFormLayout(wrapperInfo);
  layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
  layoutInfo->addRow("Nome:", nomePizza);
  layoutInfo->addRow("Prezzo:", prezzoPizza);

  // Farina
  QScrollArea* scrollAreaF = new QScrollArea(this);
  scrollAreaF->setWidgetResizable(true);
  scrollAreaF->setStyleSheet("background-color: #eeeeee");
  farineRadioButtonWrapper = new QWidget(scrollAreaF);
  farineRadioButtonWrapper->setObjectName("farineRadioButtonWrapper");
  QVBoxLayout* farineRadioButtonLayout = new QVBoxLayout(farineRadioButtonWrapper);
  farineRadioButtonWrapper->setLayout(farineRadioButtonLayout);
  scrollAreaF->setWidget(farineRadioButtonWrapper);

  // Ingredienti
  QScrollArea* scrollAreaI = new QScrollArea(this);
  scrollAreaI->setWidgetResizable(true);
  scrollAreaI->setStyleSheet("background-color: #eeeeee");
  ingredientiCheckBoxWrapper = new QWidget(scrollAreaI);
  ingredientiCheckBoxWrapper->setObjectName("ingredientiCheckBoxWrapper");
  QVBoxLayout* ingredientiCheckboxLayout = new QVBoxLayout(ingredientiCheckBoxWrapper);
  ingredientiCheckBoxWrapper->setLayout(ingredientiCheckboxLayout);
  scrollAreaI->setWidget(ingredientiCheckBoxWrapper);

  layoutPizza = new QGridLayout(this);
  layoutPizza->addWidget(wrapperInfo,0,0,2,6,Qt::AlignHCenter);
  layoutPizza->addWidget(scrollAreaF, 3, 0, 6, 6);
  layoutPizza->addWidget(scrollAreaI, 7, 0, 10, 6);
  setLayout(layoutPizza);
}

QLineEdit *NuovoArticolo_pizza::getNomePizza() const{ return nomePizza;}

QLineEdit *NuovoArticolo_pizza::getPrezzoPizza() const{ return prezzoPizza;}

QWidget *NuovoArticolo_pizza::getIngredientiCheckBoxWrapper() const{ return ingredientiCheckBoxWrapper;}

QWidget *NuovoArticolo_pizza::getFarineRadioButtonWrapper() const{ return farineRadioButtonWrapper;}
