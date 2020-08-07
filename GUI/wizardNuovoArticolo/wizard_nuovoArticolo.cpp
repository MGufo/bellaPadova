#include "wizard_nuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new NuovoArticolo_intro(this));
  setPage(PAGE_Dettagli, new NuovoArticolo_dettagli(this));
  setPage(PAGE_End, new NuovoArticolo_end(this));
  setStartId(PAGE_Intro);
  setWindowTitle(tr("Aggiunta articolo al Menù"));
  connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(assegnaBottoni(int)));
  connect(page(PAGE_Dettagli), SIGNAL(completeChanged()), this, SLOT(handlerBottoni()));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoArticolo::accept(){
    QWizard::accept();
    pacchetto* p = nullptr;
    if(field("optionPizza").toBool()){
        p = new pacchettoPizza(0,field("nomePizza").toString().toStdString(),true,field("prezzoPizza").toDouble());
        pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(p);

        //recupero la farina
        QTableWidget* farineTabellaWrapper = findChild<QTableWidget*>("farineWrapper");
        for(int i=0; i<farineTabellaWrapper->rowCount() ; i++){
            QRadioButton* radioFarina = dynamic_cast<QRadioButton*>(farineTabellaWrapper->cellWidget(i,1));
            if(radioFarina->isChecked()){
                uint ID = std::stoi(farineTabellaWrapper->item(i,0)->text().toStdString());
                string nome = farineTabellaWrapper->item(i,2)->text().toStdString();
                pP->ingredienti[ID] = nome;
            }
        }
        //recupero gli ingredienti
    }
}

void WizardNuovoArticolo::assegnaBottoni(int id){
    if(id == WizardNuovoArticolo::PAGE_Intro)
       button(QWizard::BackButton)->hide();
    /*if(button(QWizard::NextButton)->isEnabled())
       button(QWizard::NextButton)->setStyleSheet("background-color: #2b78e4;");
    else
       button(QWizard::NextButton)->setStyleSheet("background-color: #999999;");*/
}

void WizardNuovoArticolo::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}
