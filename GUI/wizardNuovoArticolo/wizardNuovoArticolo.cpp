#include "wizardNuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(Page_tipoArticolo, new tipoArticolo);
  setPage(Page_tipoPizza, new tipoPizza);
  setPage(Page_tipoBevanda, new tipoBevanda);
  setPage(Page_end, new end);

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
  #endif
  setStartId(Page_tipoArticolo);
  setWindowTitle(tr("Aggiunta articolo al menù"));
}
