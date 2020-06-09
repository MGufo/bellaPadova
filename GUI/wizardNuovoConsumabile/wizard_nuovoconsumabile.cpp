#include "wizard_nuovoconsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new );

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));

#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}
