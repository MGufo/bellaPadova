#include "wizard_nuovaComanda.h"

WizardNuovaComanda::WizardNuovaComanda(QWidget *parent) : QWizard(parent){
    setPage(PAGE_Dettagli, new NuovaComanda_dettagli(this));
    setPage(PAGE_End, new NuovaComanda_end(this));
    setStartId(PAGE_Dettagli);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("Aggiunta nuova comanda"));

    connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(assegnaBottoni(int)));
    connect(page(PAGE_Dettagli), SIGNAL(completeChanged()), this, SLOT(handlerBottoni()));
    connect(this, SIGNAL(nuovaComanda(pacchettoComanda*)),
            this->parentWidget()->parentWidget()->parentWidget()->parentWidget(),
            SLOT(creaNuovaComanda(pacchettoComanda*)));

    // Stile wizard (tranne MacOS)
    #ifndef Q_OS_MAC
    setWizardStyle(ModernStyle);
  #endif
}

void WizardNuovaComanda::assegnaBottoni(int id){
    if(id == WizardNuovaComanda::PAGE_Dettagli)
       button(QWizard::BackButton)->hide();
}

void WizardNuovaComanda::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}
