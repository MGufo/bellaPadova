#include "wizard_nuovoConsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new nuovoConsumabile_intro);
  setPage(PAGE_Dettagli, new NuovoConsumabile_dettagli);
  setPage(PAGE_End, new NuovoConsumabile_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));
  connect(this, SIGNAL(nuovoConsumabile(pacchetto*)),
          this->parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(creaNuovoConsumabile(pacchetto*)));
  connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(assegnaBottoni(int)));
  connect(page(PAGE_Dettagli), SIGNAL(completeChanged()), this, SLOT(handlerBottoni()));
#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoConsumabile::accept(){
  QWizard::accept();
  pacchetto* p = nullptr;
  if(field("optionIngrediente").toBool())
    p = new pacchettoIngrediente(
          0, field("nome").toString().toStdString(), field("disponibilita").toBool(),
          field("quantita").toUInt(), field("costo").toDouble(),
          field("dataAcquisto").toDate(), field("locale").toBool());
  else if(field("optionFarina").toBool()){
    p = new pacchettoFarina(0, field("nome").toString().toStdString(), field("disponibilita").toBool(),
                            field("quantita").toUInt(), field("costo").toDouble(),
                            field("dataAcquisto").toDate(), field("locale").toBool(),field("tipoFarina").toString().toStdString());
  }
  else if(field("optionBevanda").toBool()){
    p = new pacchettoBevanda(
          0, field("nome").toString().toStdString(), field("disponibilita").toBool(), field("prezzo").toDouble(),
          field("quantita").toUInt(), field("costo").toDouble(),
          field("dataAcquisto").toDate(), field("capacita").toFloat(), field("optionLattina").toBool());
  }
  emit nuovoConsumabile(p);
}

void WizardNuovoConsumabile::assegnaBottoni(int id){
    if(id == WizardNuovoConsumabile::PAGE_Intro)
       button(QWizard::BackButton)->hide();
    if(button(QWizard::NextButton)->isEnabled())
       button(QWizard::NextButton)->setStyleSheet("background-color: #2b78e4;");
    else
       button(QWizard::NextButton)->setStyleSheet("background-color: #999999;");
}

void WizardNuovoConsumabile::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}
