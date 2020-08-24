#include "GUI/wizardNuovoConsumabile/nuovoConsumabile_dettagli.h"
#include <iostream>

NuovoConsumabile_dettagli::NuovoConsumabile_dettagli(QWidget*parent) : QWizardPage(parent), previouslyInizialized(false){
  layoutDettagli = new QFormLayout(this);

  nomeConsumabile = new QLineEdit(this);
  disponibilita = new QCheckBox(this);
  disponibilita->setChecked(true);
  quantitaConsumabile = new QLineEdit(this);
  costoConsumabile = new QLineEdit(this);
  dataAcquisto = new QDateEdit(QDate::currentDate(), this);

  layoutDettagli->addRow("Nome:", nomeConsumabile);
  layoutDettagli->addRow("Disponibile:", disponibilita);
  layoutDettagli->addRow("N° Confezioni:", quantitaConsumabile);
  layoutDettagli->addRow("Costo d'acquisto:", costoConsumabile);
  layoutDettagli->addRow("Data Acquisto:", dataAcquisto);

  setLayout(layoutDettagli);
}

int NuovoConsumabile_dettagli::nextId() const{
    return WizardNuovoConsumabile::PAGE_End;
}

void NuovoConsumabile_dettagli::setActualPage(){
    auto ptr = findChild<QCheckBox*>("locale");
    if(ptr) layoutDettagli->removeRow(ptr);
    auto ptr5 = findChild<QLineEdit*>("tipoFarina");
    if(ptr5) layoutDettagli->removeRow(ptr5);
    auto ptr1 = findChild<QLineEdit*>("capacita");
    if(ptr1) layoutDettagli->removeRow(ptr1);
    auto ptr2 = findChild<QLineEdit*>("prezzo");
    if(ptr2) layoutDettagli->removeRow(ptr2);
    auto ptr3 = findChild<QRadioButton*>("optionLattina");
    if(ptr3) layoutDettagli->removeRow(ptr3);
    auto ptr4 = findChild<QRadioButton*>("optionBottiglia");
    if(ptr4) layoutDettagli->removeRow(ptr4);

  if(field("optionIngrediente").toBool()){
    setTitle("Aggiunta di un nuovo ingrediente all'inventario");
    setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");

    QCheckBox* locale = new QCheckBox(this);
    locale->setObjectName("locale");
    registerField("locale", locale);
    layoutDettagli->addRow("Locale:", locale);
  }
  else if(field("optionFarina").toBool()){
      setTitle("Aggiunta di una nuova farina all'inventario");
      setSubTitle("Inserisci le informazioni relative alla farina da inserire");
      QCheckBox* locale = new QCheckBox(this);
      locale->setObjectName("locale");
      registerField("locale", locale);
      layoutDettagli->addRow("Locale:", locale);

      QLineEdit* tipoFarina = new QLineEdit(this);
      tipoFarina->setObjectName("tipoFarina");
      registerField("tipoFarina*", tipoFarina);
      layoutDettagli->addRow("Tipologia della Farina:", tipoFarina);
  }
  else if(field("optionBevanda").toBool()){
    setTitle("Aggiunta di una nuova bevanda all'inventario");
    setSubTitle("Inserisci le informazioni relative alla bevanda da inserire");

    QLineEdit* capacita = new QLineEdit(this);
    capacita->setObjectName("capacita");
    registerField("capacita*", capacita);
    layoutDettagli->addRow("Capacità bevanda:", capacita);

    QLineEdit* prezzo = new QLineEdit(this);
    prezzo->setObjectName("prezzo");
    registerField("prezzo*", prezzo);
    layoutDettagli->addRow("Prezzo di vendita:", prezzo);

    QRadioButton* optionLattina = new QRadioButton("Lattina",this);
    optionLattina->setObjectName("optionLattina");
    optionLattina->setChecked(true);
    registerField("optionLattina", optionLattina);
    QRadioButton* optionBottiglia = new QRadioButton("Bottiglia",this);
    optionBottiglia->setObjectName("optionBottiglia");
    layoutDettagli->addRow("Lattina", optionLattina);
    layoutDettagli->addRow("Bottiglia", optionBottiglia);
  }
}

void NuovoConsumabile_dettagli::initializePage(){
  QWizardPage::initializePage();
  if(!previouslyInizialized){
      registerField("nome*", nomeConsumabile);
      registerField("disponibilita", disponibilita);
      registerField("quantita*", quantitaConsumabile);
      registerField("costo*", costoConsumabile);
      registerField("dataAcquisto", dataAcquisto);
  }
  setActualPage();
  previouslyInizialized = true;
}
