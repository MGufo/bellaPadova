#include "wizard_nuovoConsumabile.h"

WizardNuovoConsumabile::WizardNuovoConsumabile(QWidget* parent) : QWizard(parent){
  setPage(PAGE_Intro, new nuovoConsumabile_intro);
  setPage(PAGE_Dettagli, new NuovoConsumabile_dettagli);
  setPage(PAGE_End, new NuovoConsumabile_end);

  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta nuovo consumabile all'Inventario"));
  connect(this, SIGNAL(nuovoConsumabile(pacchetto*)),
          this->parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(creaNuovoConsumabile(pacchetto*)));

#ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoConsumabile::accept(){
  QWizard::accept();
  pacchetto* p = nullptr;
  if(field("optionIngrediente").toBool())
    p = new pacchettoIngrediente(
          0, field("nome").toString().toStdString(), field("disponibilita").toBool(),
          field("quantita").toUInt(), field("costo").toDouble(),
          field("dataAcquisto").toDate(), field("locale").toBool());
  else
    // TODO: Aggiungere field("prezzo") e sostituirlo al "12"
    p = new pacchettoBevanda(
          0, field("nome").toString().toStdString(), field("disponibilita").toBool(), 12,
          field("quantita").toUInt(), field("costo").toDouble(),
          field("dataAcquisto").toDate(), field("capacita").toFloat(), false);
          // TODO: Aggiungere field("tipologia") e sostituirlo al "false"
  emit nuovoConsumabile(p);
}
