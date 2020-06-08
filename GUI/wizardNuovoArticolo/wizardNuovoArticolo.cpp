#include "wizardNuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new wizard_intro);
  setPage(PAGE_Pizza, new wizard_pizza);
  setPage(PAGE_Bevanda, new wizard_bevanda);
  setPage(PAGE_End, new wizard_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}
