#include "wizard_nuovoArticolo.h"

WizardNuovoArticolo::WizardNuovoArticolo(QWidget *parent) : QWizard(parent){
  setPage(PAGE_Intro, new NuovoArticolo_intro(this));
  setPage(PAGE_Dettagli, new NuovoArticolo_dettagli(this));
  setPage(PAGE_End, new NuovoArticolo_end(this));
  setStartId(PAGE_Intro);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
  setWindowTitle(tr("Aggiunta articolo al Menù"));
  connect(this, SIGNAL(nuovoArticolo(pacchettoArticolo*)),
          this->parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(creaNuovoArticolo(pacchettoArticolo*)));
  connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(assegnaBottoni(int)));
  connect(page(PAGE_Dettagli), SIGNAL(completeChanged()), this, SLOT(handlerBottoni()));

  // Stile wizard (tranne MacOS)
  #ifndef Q_OS_MAC
  setWizardStyle(ModernStyle);
#endif
}

void WizardNuovoArticolo::accept(){
    QWizard::accept();
    pacchettoArticolo* p = nullptr;
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
        QTableWidget* ingredientiTabellaWrapper = findChild<QTableWidget*>("ingredientiWrapper");
        for(int i=0; i<ingredientiTabellaWrapper->rowCount() ; i++){
            QCheckBox* checkIngr = dynamic_cast<QCheckBox*>(ingredientiTabellaWrapper->cellWidget(i,1));
            if(checkIngr->isChecked()){
                uint ID = std::stoi(ingredientiTabellaWrapper->item(i,0)->text().toStdString());
                string nome = ingredientiTabellaWrapper->item(i,2)->text().toStdString();
                pP->ingredienti[ID] = nome;
            }
        }
    }
    else if(field("optionBevanda").toBool()){
        QTableWidget* bevandeTabellaWrapper = findChild<QTableWidget*>("bevandeWrapper");
        for(int i=0; i<bevandeTabellaWrapper->rowCount() ; i++){
            QRadioButton* radioBevanda = dynamic_cast<QRadioButton*>(bevandeTabellaWrapper->cellWidget(i,1));
            if(radioBevanda->isChecked()){
                uint ID = std::stoi(bevandeTabellaWrapper->item(i,0)->text().toStdString());
                //creo pacchetto fittizzio di cui mi interessa solo l'ID
                p = new pacchettoBevanda(ID,"",true,0,0,0,QDate(),0,true);
            }
        }
    }
    emit nuovoArticolo(p);
}

void WizardNuovoArticolo::assegnaBottoni(int id){
    if(id == WizardNuovoArticolo::PAGE_Intro)
       button(QWizard::BackButton)->hide();
}

void WizardNuovoArticolo::handlerBottoni(){
    assegnaBottoni(nextId()-1);
}
