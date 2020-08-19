#include "wizard_nuovaComanda.h"

WizardNuovaComanda::WizardNuovaComanda(QWidget *parent) : QWizard(parent){
    setPage(PAGE_Dettagli, new NuovaComanda_dettagli(this));
    setPage(PAGE_End, new NuovaComanda_end(this));
    setStartId(PAGE_Dettagli);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("Aggiunta nuova comanda"));
    setMinimumSize(1200,800);

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

void WizardNuovaComanda::accept(){
    QWizard::accept();
    pacchettoComanda* p = new pacchettoComanda(0,field("nome").toString().toStdString(),field("indirizzo").toString().toStdString(),field("telefono").toString().toStdString(),field("orario").toTime(),0,false);

    //inserisco le pizze nella comanda
    QTableWidget* pizzeTabellaWrapper = findChild<QTableWidget*>("pizzeWrapper");
    for(int i=0; i<pizzeTabellaWrapper->rowCount() ; i++){
        QCheckBox* checkPizza = dynamic_cast<QCheckBox*>(pizzeTabellaWrapper->cellWidget(i,0));
        if(checkPizza->isChecked()){
            uint ID = pizzeTabellaWrapper->item(i,1)->data(Qt::UserRole).toInt();
            uint qta  = dynamic_cast<QSpinBox*>(pizzeTabellaWrapper->cellWidget(i,2))->value();
            p->ordinazione[ID] = qta;
        }
    }
    //inserisco le bevande nella comanda
    QTableWidget* bevandeTabellaWrapper = findChild<QTableWidget*>("bevandeWrapper_comande");
    for(int i=0; i<bevandeTabellaWrapper->rowCount() ; i++){
        QCheckBox* checkBevanda = dynamic_cast<QCheckBox*>(bevandeTabellaWrapper->cellWidget(i,0));
        if(checkBevanda->isChecked()){
            uint ID = bevandeTabellaWrapper->item(i,1)->data(Qt::UserRole).toInt();
            uint qta  = dynamic_cast<QSpinBox*>(bevandeTabellaWrapper->cellWidget(i,2))->value();
            p->ordinazione[ID] = qta;
        }
    }
    emit nuovaComanda(p);
}

void WizardNuovaComanda::assegnaBottoni(int id){
    if(id == WizardNuovaComanda::PAGE_Dettagli)
       button(QWizard::BackButton)->hide();
}

void WizardNuovaComanda::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}
