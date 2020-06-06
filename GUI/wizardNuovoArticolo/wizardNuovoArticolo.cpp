#include "wizardNuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new wizard_Intro);
  setPage(PAGE_Pizza, new wizard_Pizza);
  setPage(PAGE_Bevanda, new wizard_Bevanda);
  setPage(PAGE_End, new wizard_End);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));

  connect(this, SIGNAL(helpRequested()), this, SLOT(mostraAiuto()));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
  #endif
}

void WizardNuovoArticolo::mostraAiuto(){
  QString* helpMessage;

  switch(currentId()){
    case PAGE_Intro:
      helpMessage = "Scegli quale tipo di articolo vuoi aggiungere al menù e premi 'avanti', altrimenti premi 'annulla'";
    break;

    default:
      helpMessage = "se sei arrivato a questo punto uno dei programmatori ha sbagliato qualcosa!";
  }
  QMessageBox::information(this, "Serve una mano?", helpMessage);
}
