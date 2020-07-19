#include "nuovoConsumabile_dettagli.h"
#include <iostream>

NuovoConsumabile_dettagli::NuovoConsumabile_dettagli(QWidget*parent) : QWizardPage(parent), previouslyInizialized(false){
  layoutDettagli = new QFormLayout(this);

  nomeConsumabile = new QLineEdit(this);
  quantitaConsumabile = new QLineEdit(this);
  costoConsumabile = new QLineEdit(this);
  dataAcquisto = new QDateEdit(QDate::currentDate(), this);
  disponibilita = new QCheckBox(this);

  layoutDettagli->addRow("Nome:", nomeConsumabile);
  layoutDettagli->addRow("N° Confezioni:", quantitaConsumabile);
  layoutDettagli->addRow("Costo:", costoConsumabile);
  layoutDettagli->addRow("Data Acquisto:", dataAcquisto);
  layoutDettagli->addRow("Disponibile:", disponibilita);

  setLayout(layoutDettagli);
}

int NuovoConsumabile_dettagli::nextId() const{
    return WizardNuovoConsumabile::PAGE_End;
}

void NuovoConsumabile_dettagli::setActualPage(){
  //if(campoExtra) layoutDettagli->removeRow(campoExtra);
  if(field("optionIngrediente").toBool()){
    auto ptr = findChild<QCheckBox*>("locale");
    if(ptr) layoutDettagli->removeRow(ptr);
    setTitle("Aggiunta di un nuovo ingrediente all'Inventario");
    setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");
    QCheckBox* locale = new QCheckBox(this);
    locale->setObjectName("locale");
    registerField("locale", locale);
    layoutDettagli->addRow("Locale:", locale);
  }
  else{
    setTitle("Aggiunta di una nuova bevanda all'Inventario");
    setSubTitle("Inserisci le informazioni relative alla bevanda da inserire");
    auto ptr = findChild<QLineEdit*>("capacita");
    if(ptr) layoutDettagli->removeRow(ptr);
    // TODO: aggiungere prezzo e tipologia bevanda
    QLineEdit* capacita = new QLineEdit(this);
    capacita->setObjectName("capacita");
    registerField("capacita*", capacita);
    layoutDettagli->addRow("Capacità bevanda:", capacita);
  }
}

void NuovoConsumabile_dettagli::initializePage(){
  QWizardPage::initializePage();
  if(!previouslyInizialized){
      registerField("nome*", nomeConsumabile);
      registerField("quantita*", quantitaConsumabile);
      registerField("costo*", costoConsumabile);
      registerField("dataAcquisto", dataAcquisto);
      registerField("disponibilita", disponibilita);
  }
  setActualPage();
  previouslyInizialized = true;
}
