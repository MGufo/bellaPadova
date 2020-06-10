#include "wizard_nuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new WizardPage_intro);
  setPage(PAGE_Pizza, new WizardPage_pizza);
  setPage(PAGE_Bevanda, new WizardPage_bevanda);
  setPage(PAGE_End, new WizardPage_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}
