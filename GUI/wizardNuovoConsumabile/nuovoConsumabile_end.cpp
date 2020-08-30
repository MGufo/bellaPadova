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
    if(disponibilita) layoutEnd->removeRow(disponibilita);
    if(quantitaConsumabile) layoutEnd->removeRow(quantitaConsumabile);
    if(costoConsumabile) layoutEnd->removeRow(costoConsumabile);
    if(dataAcquisto) layoutEnd->removeRow(dataAcquisto);

    nomeConsumabile = new QLabel(field("nome").toString(), this);
    disponibilita = new QLabel(((field("disponibilita").toBool())? "Si" : "No"),this);
    quantitaConsumabile = new QLabel(field("quantita").toString(), this);
    costoConsumabile = new QLabel(field("costo").toString(), this);
    dataAcquisto = new QLabel(field("dataAcquisto").toDate().toString("dd/MM/yyyy"), this);

    layoutEnd->addRow("Nome:", nomeConsumabile);
    layoutEnd->addRow("Disponibile:", disponibilita);
    layoutEnd->addRow("N° Confezioni:", quantitaConsumabile);
    layoutEnd->addRow("Costo:", costoConsumabile);
    layoutEnd->addRow("Data Acquisto:", dataAcquisto);
}

void NuovoConsumabile_end::setActualPage(){
  QLabel* ptr = nullptr;
  ptr = findChild<QLabel*>("locale");
  if(ptr) layoutEnd->removeRow(ptr);
  ptr = findChild<QLabel*>("tipoFarina");
  if(ptr) layoutEnd->removeRow(ptr);
  ptr = findChild<QLabel*>("capacita");
  if(ptr) layoutEnd->removeRow(ptr);
  ptr = findChild<QLabel*>("prezzo");
  if(ptr) layoutEnd->removeRow(ptr);
  ptr = findChild<QLabel*>("tipologia");
  if(ptr) layoutEnd->removeRow(ptr);

  if(field("optionIngrediente").toBool()){
    QLabel* locale = new QLabel(((field("locale").toBool())? "Si" : "No"),this);
    locale->setObjectName("locale");
    layoutEnd->addRow("Locale:", locale);
  }
  else if(field("optionFarina").toBool()){
      QLabel* locale = new QLabel(((field("locale").toBool())? "Si" : "No"),this);
      locale->setObjectName("locale");
      layoutEnd->addRow("Locale:", locale);

      QLabel* tipoFarina = new QLabel(field("tipoFarina").toString(), this);
      tipoFarina->setObjectName("tipoFarina");
      layoutEnd->addRow("Tipologia della Farina:", tipoFarina);
  }
  else if(field("optionBevanda").toBool()){
    QLabel* capacita = new QLabel(field("capacita").toString(), this);
    capacita->setObjectName("capacita");
    layoutEnd->addRow("Capacità bevanda:", capacita);

    QLabel* prezzo = new QLabel(field("prezzo").toString(), this);
    prezzo->setObjectName("prezzo");
    layoutEnd->addRow("Prezzo:", prezzo);

    QLabel* tipologia = new QLabel((field("optionLattina").toBool() ? "Lattina" : "Bottiglia"), this);
    tipologia->setObjectName("tipologia");
    layoutEnd->addRow("Tipologia:", tipologia);
  }
}
