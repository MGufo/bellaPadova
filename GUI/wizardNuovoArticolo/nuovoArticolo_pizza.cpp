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

  // Ingredienti base pizza
  QWidget* wrapperBasePizza = new QWidget(this);
  pomodoro = new QCheckBox("Pomodoro", wrapperBasePizza);
  mozzarella = new QCheckBox("Mozzarella", wrapperBasePizza);
  QVBoxLayout* layoutBase = new QVBoxLayout(wrapperBasePizza);
  layoutBase->addWidget(pomodoro);
  layoutBase->addWidget(mozzarella);

  // Ingredienti
  QScrollArea* scrollArea = new QScrollArea(this);
  scrollArea->setStyleSheet("background-color: #eeeeee");

  ingredientiCheckBoxWrapper = new QWidget(scrollArea);
  ingredientiCheckBoxWrapper->setObjectName("ingredientiCheckBoxWrapper");
  QVBoxLayout* ingredientiCheckboxLayout = new QVBoxLayout(ingredientiCheckBoxWrapper);
  //una funzione del controller si occuperà di prendere tutti gli ingredienti presenti nell'inventario
  //IngredientCheckBox* i1 = new IngredientCheckBox("ananas",1,ingredientiCheckBoxWrapper);
  //IngredientCheckBox* i2 = new IngredientCheckBox("funghi",2,ingredientiCheckBoxWrapper);
  //ingredientiCheckboxLayout->addWidget(i1);
  //ingredientiCheckboxLayout->addWidget(i2);
//  for(int i=0; i<10; ++i){
//    QCheckBox* checkBox = new QCheckBox(checkboxWrapper);
//    checkboxLayout->addWidget(checkBox);
//  }
  scrollArea->setWidget(ingredientiCheckBoxWrapper);

  layoutPizza = new QGridLayout(this);
  layoutPizza->addWidget(wrapperInfo,0,0,2,4);
  layoutPizza->addWidget(wrapperBasePizza,0,4,2,2);
  layoutPizza->addWidget(scrollArea, 3, 0, 6, 6);
  setLayout(layoutPizza);
}

QLineEdit *NuovoArticolo_pizza::getNomePizza() const{   return nomePizza;}

QLineEdit *NuovoArticolo_pizza::getPrezzoPizza() const{   return prezzoPizza;}

QCheckBox *NuovoArticolo_pizza::getPomodoro() const{    return pomodoro;}

QCheckBox *NuovoArticolo_pizza::getMozzarella() const{  return mozzarella;}

QWidget *NuovoArticolo_pizza::getIngredientiCheckBoxWrapper() const{    return ingredientiCheckBoxWrapper;}
