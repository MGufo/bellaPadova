#include "nuovoArticolo_dettagli.h"

NuovoArticolo_dettagli::NuovoArticolo_dettagli(QWidget* parent) : QWizardPage(parent), content(nullptr){
    layoutDettagli = new QVBoxLayout(this);
    setLayout(layoutDettagli);
}

int NuovoArticolo_dettagli::nextId() const{
    return WizardNuovoArticolo::PAGE_End;
}

void NuovoArticolo_dettagli::setActualPage(){
    if(content){
        layoutDettagli->removeWidget(content);
        delete content;
    }
    if(field("optionPizza").toBool()){   //costruzione wizard pizza
        setTitle("Aggiunta di una nuova pizza al Menù");
        setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi "
                    "aggiungi gli ingredienti che la compongono");
        content = new NuovoArticolo_pizza(this);
    }
    else{   //costruzione wizard bevanda
        setTitle("Aggiunta di una nuova bevanda al Menù");
        setSubTitle("Seleziona il formato della bevanda, poi specificane nome, costo e capacità");
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
        auto ingredients = ptr->getIngredientsCheckBoxWrapper()->children();
        for(auto it = ingredients.cbegin(); it != ingredients.cend(); ++it){
            IngredientCheckBox* tmp = static_cast<IngredientCheckBox*>(*it);
            QString id(tmp->getId());
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
