#include "wizard_pizza.h"

wizard_pizza::wizard_pizza(QWidget *parent) : QWizardPage(parent){
  setTitle("Aggiunta di una nuova pizza al Menù");
  setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi"
              "aggiungi gli ingredienti che la compongono");

  // Informazioni pizza
  QWidget* informazioniWrapper = new QWidget(this);
  QTextEdit* nome = new QTextEdit(informazioniWrapper);
  QTextEdit* prezzo = new QTextEdit(informazioniWrapper);
  QFormLayout* layoutInfo = new QFormLayout(informazioniWrapper);
  layoutInfo->addRow("Nome pizza:", nome);
  layoutInfo->addRow("Prezzo pizza:", prezzo);


//  Versione vecchia (backup)
//  QWidget* informazioniWrapper = new QWidget(this);
//  QLabel* labelNome = new QLabel("Nome pizza:", informazioniWrapper);
//  QTextEdit* nome = new QTextEdit(informazioniWrapper);
//  QLabel* labelPrezzo = new QLabel("Prezzo pizza:", informazioniWrapper);
//  QTextEdit* prezzo = new QTextEdit(informazioniWrapper);
//  QHBoxLayout* layoutInfo = new QHBoxLayout(informazioniWrapper);
//  layoutInfo->addWidget(labelNome);
//  layoutInfo->addWidget(nome);
//  layoutInfo->addWidget(labelPrezzo);
//  layoutInfo->addWidget(prezzo);

  // Ingredienti base pizza
  QWidget* baseWrapper = new QWidget(this);
  QLabel* labelBase = new QLabel("Base pizza:", baseWrapper);
  QCheckBox* pomodoro = new QCheckBox("Pomodoro", baseWrapper);
  QCheckBox* mozzarella = new QCheckBox("Mozzarella", baseWrapper);
  QHBoxLayout* layoutBase = new QHBoxLayout(baseWrapper);
  layoutBase->addWidget(labelBase);
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

  layoutPizza = new QVBoxLayout(this);
  layoutPizza->addWidget(informazioniWrapper);
  layoutPizza->addWidget(baseWrapper);
  layoutPizza->addWidget(checkboxWrapper);

  setLayout(layoutPizza);
}

int wizard_pizza::nextId() const{
  return WizardNuovoArticolo::PAGE_End;
}
