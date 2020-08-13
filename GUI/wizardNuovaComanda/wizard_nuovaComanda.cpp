#include "wizard_nuovaComanda.h"

WizardNuovaComanda::WizardNuovaComanda(QWidget *parent) : QWizard(parent){
    setPage(PAGE_Dettagli, new NuovaComanda_dettagli(this));
    setPage(PAGE_End, new NuovaComanda_end(this));
    setStartId(PAGE_Intro);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("Aggiunta nuova comanda"));

    connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(assegnaBottoni(int)));
    connect(page(PAGE_Dettagli), SIGNAL(completeChanged()), this, SLOT(handlerBottoni()));

    // Stile wizard (tranne MacOS)
    #ifndef Q_OS_MAC
    setWizardStyle(ModernStyle);
  #endif
}

void WizardNuovaComanda::assegnaBottoni(int id){
    if(id == WizardNuovoArticolo::PAGE_Intro)
       button(QWizard::BackButton)->hide();
}

void WizardNuovaComanda::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}