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
  QStringList* labelsFarine = new QStringList();
  labelsFarine->push_back("ID");
  labelsFarine->push_back("");
  labelsFarine->push_back("Nome");
  labelsFarine->push_back("Locale");
  labelsFarine->push_back("Tipo Farina");
  farineWrapper = new QTableWidget(0,5,this);
  farineWrapper->setObjectName("farineWrapper");
  farineWrapper->setMinimumWidth(520);
  // farineWrapper->setMaximumWidth(2100);
  QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(farineWrapper->sizePolicy().hasHeightForWidth());
  farineWrapper->setSizePolicy(sizePolicy);
  QHeaderView* headerFarine = new QHeaderView(Qt::Horizontal,farineWrapper);
  headerFarine->setSectionResizeMode(headerFarine->ResizeToContents);
  farineWrapper->setHorizontalHeaderLabels(*labelsFarine);
  farineWrapper->setHorizontalHeader(headerFarine);

  // Ingredienti
  QStringList* labelsIngredienti = new QStringList();
  labelsIngredienti->push_back("ID");
  labelsIngredienti->push_back("");
  labelsIngredienti->push_back("Nome");
  labelsIngredienti->push_back("Locale");
  ingredientiWrapper = new QTableWidget(0,4,this);
  ingredientiWrapper->setObjectName("ingredientiWrapper");
  ingredientiWrapper->setMinimumWidth(350);
  // ingredientiWrapper->setMaximumWidth(2100);
  QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  sizePolicy2.setHorizontalStretch(0);
  sizePolicy2.setVerticalStretch(0);
  sizePolicy2.setHeightForWidth(ingredientiWrapper->sizePolicy().hasHeightForWidth());
  ingredientiWrapper->setSizePolicy(sizePolicy2);
  QHeaderView* headerIngredienti = new QHeaderView(Qt::Horizontal,ingredientiWrapper);
  headerIngredienti->setSectionResizeMode(headerIngredienti->ResizeToContents);
  ingredientiWrapper->setHorizontalHeaderLabels(*labelsIngredienti);
  ingredientiWrapper->setHorizontalHeader(headerIngredienti);

  layoutPizza = new QVBoxLayout(this);
  layoutPizza->addWidget(wrapperInfo,0,Qt::AlignHCenter);
  layoutPizza->addWidget(farineWrapper);
  layoutPizza->addWidget(ingredientiWrapper);
  setLayout(layoutPizza);
}

QLineEdit *NuovoArticolo_pizza::getNomePizza() const{ return nomePizza;}

QLineEdit *NuovoArticolo_pizza::getPrezzoPizza() const{ return prezzoPizza;}

QTableWidget *NuovoArticolo_pizza::getIngredientiWrapper() const{   return ingredientiWrapper;}

QTableWidget *NuovoArticolo_pizza::getFarineWrapper() const{   return farineWrapper;}
