#include "wizard_nuovoConsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new nuovoConsumabile_intro);
  setPage(PAGE_Dettagli, new NuovoConsumabile_dettagli);
  setPage(PAGE_End, new NuovoConsumabile_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));

#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoConsumabile::accept(){
  QWizard::accept();
  if(field("optionIngrediente").toBool())
    pacchetto_ingrediente(0, field("nome"), true, field("quantita"), field("costo"), field("dataAcquisto"), field("locale"));
  else
    pacchetto_bevanda(0, field("nome"), true, field("quantita"), field("costo"), field("dataAcquisto"), field("locale"));

  // TODO: Cercare come collegare oggetti distinti tramite segnali e slot
}
