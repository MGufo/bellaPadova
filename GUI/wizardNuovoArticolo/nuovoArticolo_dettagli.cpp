#include "nuovoArticolo_dettagli.h"

NuovoArticolo_dettagli::NuovoArticolo_dettagli(QWidget* parent) :
  QWizardPage(parent), content(nullptr){
    layoutDettagli = new QVBoxLayout(this);
    connect(this,SIGNAL(riempiWizardConElementiArticolo(bool)),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiInWizardArticolo(bool)));
    setLayout(layoutDettagli);
}

int NuovoArticolo_dettagli::nextId() const{
    return WizardNuovoArticolo::PAGE_End;
}

void NuovoArticolo_dettagli::setActualPage(){
    if(content){
        layoutDettagli->removeWidget(content);
        delete content;
    }
    if(field("optionPizza").toBool()){
        //costruzione wizard pizza
        setTitle("Aggiunta di una nuova pizza al Menù");
        setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi "
                    "aggiungi gli ingredienti che la compongono");
        content = new NuovoArticolo_pizza(this);
        emit riempiWizardConElementiArticolo(true);
    }
    else{
        //costruzione wizard bevanda
        setTitle("Aggiunta di una nuova bevanda al Menù");
        setSubTitle("Seleziona una bevanda presente nell'inventario per inserirla nel menù");
        content = new NuovoArticolo_bevanda(this);
        emit riempiWizardConElementiArticolo(false);
    }
    layoutDettagli->addWidget(content);
}

void NuovoArticolo_dettagli::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
    //registerField
    if(field("optionPizza").toBool()){
        auto ptr = static_cast<NuovoArticolo_pizza*>(content);
        registerField("nomePizza*", ptr->getNomePizza());
        registerField("prezzoPizza*", ptr->getPrezzoPizza());
    }
}

bool NuovoArticolo_dettagli::validatePage(){
  if(field("optionPizza").toBool()){
    auto ptr = static_cast<NuovoArticolo_pizza*>(content);
    if(ptr){
      if(ptr->getPrezzoPizza()->text().toDouble() <= 0){
        QMessageBox messageDialog;
        messageDialog.setText(QString("Errore: Il prezzo dev'essere un numero"
                                    " maggiore di 0."));
        messageDialog.exec();
        return false;
      }
    }
  }
  return true;
}
