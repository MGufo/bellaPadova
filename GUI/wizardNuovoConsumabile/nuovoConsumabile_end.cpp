#include "nuovoConsumabile_end.h"

NuovoConsumabile_end::NuovoConsumabile_end(QWidget *parent) : QWizardPage(parent){
  setTitle("Riepilogo");
  setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
  layoutEnd = new QFormLayout(this);
  setLayout(layoutEnd);
}

void NuovoConsumabile_end::initializePage(){
    QWizardPage::initializePage();
    setInitialPage();
    setActualPage();
}

void NuovoConsumabile_end::setInitialPage(){
    if(nomeConsumabile) layoutEnd->removeRow(nomeConsumabile);
    if(quantitaConsumabile) layoutEnd->removeRow(quantitaConsumabile);
    if(costoConsumabile) layoutEnd->removeRow(costoConsumabile);
    if(dataAcquisto) layoutEnd->removeRow(dataAcquisto);
    if(disponibilita) layoutEnd->removeRow(disponibilita);

    nomeConsumabile = new QLabel(field("nome").toString(), this);
    quantitaConsumabile = new QLabel(field("quantita").toString(), this);
    costoConsumabile = new QLabel(field("costo").toString(), this);
    dataAcquisto = new QLabel(field("dataAcquisto").toDate().toString("dd/MM/yyyy"), this);
    disponibilita = new QLabel(((field("disponibilita").toBool())? "Si" : "No"),this);

    layoutEnd->addRow("Nome:", nomeConsumabile);
    layoutEnd->addRow("N° Confezioni:", quantitaConsumabile);
    layoutEnd->addRow("Costo:", costoConsumabile);
    layoutEnd->addRow("Data Acquisto:", dataAcquisto);
    layoutEnd->addRow("Disponibile:", disponibilita);
}

void NuovoConsumabile_end::setActualPage(){
  //if(campoExtra) layoutEnd->removeRow(campoExtra);
  if(field("optionIngrediente").toBool()){
    auto ptr = findChild<QLabel*>("locale");
    if(ptr) layoutEnd->removeRow(ptr);
    QLabel* locale = new QLabel(((field("locale").toBool())? "Si" : "No"),this);
    locale->setObjectName("locale");
    layoutEnd->addRow("Locale:", locale);
  }
  else{
    auto ptr = findChild<QLabel*>("capacita");
    if(ptr) layoutEnd->removeRow(ptr);
    QLabel* capacita = new QLabel(field("capacita").toString(), this);
    capacita->setObjectName("capacita");
    layoutEnd->addRow("Capacità bevanda:", capacita);
  }
}
/*  messaggio da inserire nel QDialog
setTitle("Il nuovo consumabile è stato inserito con successo nell'Inventario!");
*/
