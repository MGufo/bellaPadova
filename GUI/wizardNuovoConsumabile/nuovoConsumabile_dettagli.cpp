#include "nuovoConsumabile_dettagli.h"
NuovoConsumabile_dettagli::NuovoConsumabile_dettagli(QWidget*parent) : QWizardPage(parent){
  setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");

  QLineEdit* nomeConsumabile = new QLineEdit(this);
  registerField("nome*", nomeConsumabile);
  QLineEdit* quantitaConsumabile = new QLineEdit(this);
  registerField("quantita*", quantitaConsumabile);
  QLineEdit* costoConsumabile = new QLineEdit(this);

  QDateEdit* dataAcquisto = new QDateEdit(QDate::currentDate(), this);
  registerField("DataAcquisto", dataAcquisto);

  layoutDettagli = new QFormLayout(this);
  layoutDettagli->addRow("Nome:", nomeConsumabile);
  layoutDettagli->addRow("N° Confezioni:", quantitaConsumabile);
  layoutDettagli->addRow("Costo:", costoConsumabile);
  layoutDettagli->addRow("Data Acquisto:", dataAcquisto);
  //setPagina();
  setLayout(layoutDettagli);
}

int NuovoConsumabile_dettagli::nextId() const{
  return WizardNuovoConsumabile::PAGE_End;
}

void NuovoConsumabile_dettagli::setPagina(){
  if(campoExtra) layoutDettagli->removeRow(campoExtra);
  if(field("optionIngrediente").toBool()){
    setTitle("Aggiunta di un nuovo ingrediente all'Inventario");
    setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");
    campoExtra = new QCheckBox(this);
    layoutDettagli->addRow("Locale:", campoExtra);
  }
  else{
    setTitle("Aggiunta di una nuova bevanda all'Inventario");
    setSubTitle("Inserisci le informazioni relative alla bevanda da inserire");
    campoExtra = new QLineEdit(this);
    layoutDettagli->addRow("Capacità bevanda:", campoExtra);
  }
}

void NuovoConsumabile_dettagli::initializePage(){
  QWizardPage::initializePage();
  setPagina();
}
