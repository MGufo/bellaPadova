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

  // Ingredienti
  QScrollArea* scrollArea = new QScrollArea(this);
  scrollArea->setWidgetResizable(true);
  scrollArea->setStyleSheet("background-color: #eeeeee");
  ingredientiCheckBoxWrapper = new QWidget(scrollArea);
  ingredientiCheckBoxWrapper->setObjectName("ingredientiCheckBoxWrapper");
  QVBoxLayout* ingredientiCheckboxLayout = new QVBoxLayout(ingredientiCheckBoxWrapper);
  ingredientiCheckBoxWrapper->setLayout(ingredientiCheckboxLayout);
  scrollArea->setWidget(ingredientiCheckBoxWrapper);

  layoutPizza = new QGridLayout(this);
  layoutPizza->addWidget(wrapperInfo,0,0,2,6,Qt::AlignHCenter);
  layoutPizza->addWidget(scrollArea, 3, 0, 6, 6);
  setLayout(layoutPizza);
}

QLineEdit *NuovoArticolo_pizza::getNomePizza() const{   return nomePizza;}

QLineEdit *NuovoArticolo_pizza::getPrezzoPizza() const{   return prezzoPizza;}

QWidget *NuovoArticolo_pizza::getIngredientiCheckBoxWrapper() const{    return ingredientiCheckBoxWrapper;}
