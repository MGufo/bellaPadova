#include "nuovoConsumabile_ingrediente.h"

NuovoConsumabile_ingrediente::NuovoConsumabile_ingrediente(QWidget*parent) : QWizardPage(parent){
  setTitle("Aggiunta di un nuovo ingrediente all'Inventario");
  setSubTitle("Inserisci le informazioni relative all'ingrediente da inserire");

  QLineEdit* nome = new QLineEdit(this);
  registerField("nome", nome);
  QLineEdit* quantita = new QLineEdit(this);
  registerField("quantita", quantita);
  QLineEdit* costo = new QLineEdit(this);
  registerField("costo", costo);
  QDateEdit* dataAcquisto = new QDateEdit(QDate::currentDate(), this);
  registerField("DataAcquisto", dataAcquisto);
  QCheckBox* isLocal = new QCheckBox(this);

  layoutIngrediente = new QFormLayout(this);
  layoutIngrediente->addRow("Nome:", nome);
  layoutIngrediente->addRow("N° Confezioni:", quantita);
  layoutIngrediente->addRow("Costo:", costo);
  layoutIngrediente->addRow("Data Acquisto:", dataAcquisto);
  layoutIngrediente->addRow("Locale:", isLocal);

  setLayout(layoutIngrediente);
}

int NuovoConsumabile_ingrediente::nextId() const{
  return WizardNuovoConsumabile::PAGE_End;
}
