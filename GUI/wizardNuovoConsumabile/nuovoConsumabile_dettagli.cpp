#include "nuovoConsumabile_dettagli.h"
#include <iostream>
NuovoConsumabile_dettagli::NuovoConsumabile_dettagli(QWidget*parent) : QWizardPage(parent){
  setTitle("Aggiunta di un nuovo ingrediente all'Inventario");
  setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");

  QLineEdit* nomeConsumabile = new QLineEdit(this);
  registerField("nome*", nomeConsumabile);
  QLineEdit* quantitaConsumabile = new QLineEdit(this);
  registerField("quantita*", quantitaConsumabile);
  QLineEdit* costoConsumabile = new QLineEdit(this);
  registerField("costo*", costoConsumabile);
  QDateEdit* dataAcquisto = new QDateEdit(QDate::currentDate(), this);
  registerField("DataAcquisto", dataAcquisto);

//  if (field("optionIngrediente").toBool())
//    std::cout << "ghesboro" << std::endl;
//  else
//    std:: cout <<"madonna luia" << std::endl;

  QCheckBox* isLocal = new QCheckBox(this);

  layoutDettagli = new QFormLayout(this);
  layoutDettagli->addRow("Nome:", nomeConsumabile);
  layoutDettagli->addRow("N° Confezioni:", quantitaConsumabile);
  layoutDettagli->addRow("Costo:", costoConsumabile);
  layoutDettagli->addRow("Data Acquisto:", dataAcquisto);
  layoutDettagli->addRow("Locale:", isLocal);

  setLayout(layoutDettagli);
}

int NuovoConsumabile_dettagli::nextId() const{
  return WizardNuovoConsumabile::PAGE_End;
}
