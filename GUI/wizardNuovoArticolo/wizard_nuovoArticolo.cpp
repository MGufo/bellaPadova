#include "wizard_nuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new NuovoArticolo_intro(this));
  setPage(PAGE_Dettagli, new NuovoArticolo_dettagli(this));
  setPage(PAGE_End, new NuovoArticolo_end(this));
  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoArticolo::accept(){
    QWizard::accept();
}
