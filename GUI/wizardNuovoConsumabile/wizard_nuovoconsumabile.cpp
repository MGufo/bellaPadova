#include "wizard_nuovoConsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new nuovoConsumabile_intro);
  setPage(PAGE_Ingrediente, new NuovoConsumabile_ingrediente);
  setPage(PAGE_Bevanda, new NuovoConsumabile_bevanda);
  setPage(PAGE_End, new NuovoConsumabile_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));

#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}
