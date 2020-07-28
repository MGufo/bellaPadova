#include "nuovoArticolo_dettagli.h"

NuovoArticolo_dettagli::NuovoArticolo_dettagli(QWidget* parent) : QWizardPage(parent), content(nullptr){
    layoutDettagli = new QVBoxLayout(this);
    connect(this,SIGNAL(riempiWizardConIngredienti()),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaIngredientiInWizard()));
    setLayout(layoutDettagli);
}

int NuovoArticolo_dettagli::nextId() const{
    return WizardNuovoArticolo::PAGE_End;
}

void NuovoArticolo_dettagli::setActualPage(){
    //TODO: implemento pagine del wizard come wizardNuovoConsumabile
    if(content){
        layoutDettagli->removeWidget(content);
        delete content;
    }
    if(field("optionPizza").toBool()){   //costruzione wizard pizza
        setTitle("Aggiunta di una nuova pizza al Menù");
        setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi "
                    "aggiungi gli ingredienti che la compongono");
        content = new NuovoArticolo_pizza(this);
        emit riempiWizardConIngredienti();
    }
    else{   //costruzione wizard bevanda
        setTitle("Aggiunta di una nuova bevanda al Menù");
        setSubTitle("Seleziona una bevanda presente nell'inventario per inserirla nel menù");
        content = new NuovoArticolo_bevanda(this);
    }
    layoutDettagli->addWidget(content);
}

void NuovoArticolo_dettagli::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
    //registerField
    if(field("optionPizza").toBool()){
        auto ptr = static_cast<NuovoArticolo_pizza*>(content);
        registerField("nomePizza*", ptr->getNomePizza());
        registerField("prezzoPizza*", ptr->getPrezzoPizza());
        registerField("pomodoro", ptr->getPomodoro());
        registerField("mozzarella", ptr->getMozzarella());
        auto ingredients = ptr->getIngredientiCheckBoxWrapper()->children();
        for(auto it = ++(ingredients.cbegin()); it != ingredients.cend(); ++it){
            IngredientCheckBox* tmp = dynamic_cast<IngredientCheckBox*>(*it);
            string s = std::to_string(tmp->getId());
            QString id(QString::fromStdString(s));
            registerField(id, tmp);
        }
    }
    else{
        auto ptr = static_cast<NuovoArticolo_bevanda*>(content);
        registerField("nomeBevanda*", ptr->getNomeBevanda());
        registerField("prezzoBevanda*", ptr->getPrezzoBevanda());
        registerField("capacitaBevanda*", ptr->getCapacitaBevanda());
        registerField("optionBottiglia", ptr->getRadioBottiglia());
    }
}
