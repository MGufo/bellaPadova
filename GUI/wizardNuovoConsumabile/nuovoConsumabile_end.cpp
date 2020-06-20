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

    nomeConsumabile = new QLabel(field("nome").toString(), this);
    quantitaConsumabile = new QLabel(field("quantita").toString(), this);
    costoConsumabile = new QLabel(field("costo").toString(), this);
    dataAcquisto = new QLabel(field("dataAcquisto").toString(), this);

    layoutEnd->addRow("Nome:", nomeConsumabile);
    layoutEnd->addRow("N° Confezioni:", quantitaConsumabile);
    layoutEnd->addRow("Costo:", costoConsumabile);
    layoutEnd->addRow("Data Acquisto:", dataAcquisto);
}

void NuovoConsumabile_end::setActualPage(){
  if(campoExtra) layoutEnd->removeRow(campoExtra);
  if(field("optionIngrediente").toBool()){
    campoExtra = new QLabel(((field("locale").toBool())? "Si" : "No"),this);
    layoutEnd->addRow("Locale:", campoExtra);
  }
  else{
    campoExtra = new QLabel(field("capacita").toString(), this);
    layoutEnd->addRow("Capacità bevanda:", campoExtra);
  }
}
/*  messaggio da inserire nel QDialog
setTitle("Il nuovo consumabile è stato inserito con successo nell'Inventario!");
*/
