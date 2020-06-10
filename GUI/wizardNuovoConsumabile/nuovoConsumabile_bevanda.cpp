#include "nuovoConsumabile_bevanda.h"

NuovoConsumabile_bevanda::NuovoConsumabile_bevanda(QWidget* parent) :
QWizardPage(parent){
  setTitle("Aggiunta di una nuova bevanda all'Inventario");
  setSubTitle("Inserisci le informazioni relative alla bevanda da inserire");

  QLineEdit* nome = new QLineEdit(this);
  registerField("nome", nome);
  QLineEdit* quantita = new QLineEdit(this);
  registerField("quantita", quantita);
  QLineEdit* costo = new QLineEdit(this);
  registerField("costo", costo);
  QDateEdit* dataAcquisto = new QDateEdit(QDate::currentDate(), this);
  registerField("dataAcquisto", dataAcquisto);
  QLineEdit* capacita = new QLineEdit(this);
  registerField("capacita", capacita);

  layoutBevanda= new QFormLayout(this);
  layoutBevanda->addRow("Nome:", nome);
  layoutBevanda->addRow("N° Confezioni:", quantita);
  layoutBevanda->addRow("Costo:", costo);
  layoutBevanda->addRow("Data Acquisto:", dataAcquisto);
  layoutBevanda->addRow("Capacità:", capacita);

  setLayout(layoutBevanda);
}

int NuovoConsumabile_bevanda::nextId() const{
  return WizardNuovoConsumabile::PAGE_End;
}
