#include "nuovoConsumabile_dettagli.h"
#include <iostream>

NuovoConsumabile_dettagli::NuovoConsumabile_dettagli(QWidget*parent) : QWizardPage(parent), previouslyInizialized(false){
  setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");
  layoutDettagli = new QFormLayout(this);

  nomeConsumabile = new QLineEdit(this);
  quantitaConsumabile = new QLineEdit(this);
  costoConsumabile = new QLineEdit(this);
  dataAcquisto = new QDateEdit(QDate::currentDate(), this);

  layoutDettagli->addRow("Nome:", nomeConsumabile);
  layoutDettagli->addRow("N° Confezioni:", quantitaConsumabile);
  layoutDettagli->addRow("Costo:", costoConsumabile);
  layoutDettagli->addRow("Data Acquisto:", dataAcquisto);

  setLayout(layoutDettagli);
}

int NuovoConsumabile_dettagli::nextId() const{
    return WizardNuovoConsumabile::PAGE_End;
}

void NuovoConsumabile_dettagli::setActualPage(){
  if(campoExtra) layoutDettagli->removeRow(campoExtra);
  if(field("optionIngrediente").toBool()){
    setTitle("Aggiunta di un nuovo ingrediente all'Inventario");
    setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");
    campoExtra = new QCheckBox(this);
    registerField("locale", campoExtra);
    layoutDettagli->addRow("Locale:", campoExtra);
  }
  else{
    setTitle("Aggiunta di una nuova bevanda all'Inventario");
    setSubTitle("Inserisci le informazioni relative alla bevanda da inserire");
    campoExtra = new QLineEdit(this);
    registerField("capacita*", campoExtra);
    layoutDettagli->addRow("Capacità bevanda:", campoExtra);
  }
}

void NuovoConsumabile_dettagli::initializePage(){
  QWizardPage::initializePage();
  if(!previouslyInizialized){
      registerField("nome*", nomeConsumabile);
      registerField("quantita*", quantitaConsumabile);
      registerField("costo*", costoConsumabile);
      registerField("dataAcquisto", dataAcquisto);
  }
  setActualPage();
  previouslyInizialized = true;
}
