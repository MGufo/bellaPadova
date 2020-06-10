#include "wizard_nuovoConsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new nuovoConsumabile_intro);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));

#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}
