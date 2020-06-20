#include "wizard_nuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new NuovoArticolo_intro);
  setPage(PAGE_Pizza, new NuovoArticolo_pizza);
  setPage(PAGE_Bevanda, new NuovoArticolo_bevanda);
  setPage(PAGE_End, new NuovoArticolo_end);
  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoArticolo::accept(){

}
