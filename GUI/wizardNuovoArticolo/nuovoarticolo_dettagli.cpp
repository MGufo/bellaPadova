#include "nuovoarticolo_dettagli.h"

nuovoArticolo_dettagli::nuovoArticolo_dettagli(QWidget* parent) : QWizardPage(parent), previouslyInizialized(false){
    layoutDettagli = new QFormLayout(this);

    setLayout(layoutDettagli);
}

int nuovoArticolo_dettagli::nextId() const{
    return WizardNuovoArticolo::PAGE_End;
}

void nuovoArticolo_dettagli::setActualPage(){
    if(){   //costruzione wizard pizza
        setTitle("Aggiunta di una nuova pizza al Menù");
        setSubTitle("Fornisci un nome e un prezzo alla pizza da inserire, poi aggiungi gli ingredienti che la compongono");

        // Informazioni pizza
        QWidget* wrapperInfo = new QWidget(this);
        QLineEdit* nomePizza = new QLineEdit(wrapperInfo);
        registerField("nomePizza*", nomePizza);
        QLineEdit* prezzoPizza = new QLineEdit(wrapperInfo);
        registerField("prezzoPizza*", prezzoPizza);
        QFormLayout* layoutInfo = new QFormLayout(wrapperInfo);
        layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        layoutInfo->addRow("Nome pizza:", nomePizza);
        layoutInfo->addRow("Prezzo pizza:", prezzoPizza);

        // Ingredienti base pizza
        QWidget* wrapperBasePizza = new QWidget(this);
        QCheckBox* pomodoro = new QCheckBox("Pomodoro", wrapperBasePizza);
        QCheckBox* mozzarella = new QCheckBox("Mozzarella", wrapperBasePizza);
        QVBoxLayout* layoutBase = new QVBoxLayout(wrapperBasePizza);
        layoutBase->addWidget(pomodoro);
        layoutBase->addWidget(mozzarella);

        // Ingredienti
        QScrollArea* scrollArea = new QScrollArea(this);
        scrollArea->setStyleSheet("background-color: #eeeeee");
        QWidget* checkboxWrapper = new QWidget(scrollArea);
        checkboxWrapper->setObjectName("checkboxWrapper");
        QVBoxLayout* checkboxLayout = new QVBoxLayout(checkboxWrapper);
        for(int i=0; i<10; ++i){
          QCheckBox* checkBox = new QCheckBox(checkboxWrapper);
          checkboxLayout->addWidget(checkBox);
        }
        scrollArea->setWidget(checkboxWrapper);

        layoutDettagli = new QGridLayout(this);
        layoutDettagli->addWidget(wrapperInfo,0,0,2,4);
        layoutDettagli->addWidget(wrapperBasePizza,0,4,2,2);
        layoutDettagli->addWidget(scrollArea, 3, 0, 6, 6);
    }
    else{   //costruzione wizard bevanda
        setTitle("Aggiunta di una nuova bevanda al Menù");
        setSubTitle("Seleziona il formato della bevanda, poi specificane nome, costo e capacità");

        // Tipologia bevanda
        QWidget* tipologiaWrapper = new QWidget(this);
        QRadioButton* radioBottiglia = new QRadioButton("Bottiglia", tipologiaWrapper);
        radioBottiglia->setChecked(true);
        QRadioButton* radioLattina = new QRadioButton("Lattina", tipologiaWrapper);
        QHBoxLayout* layoutTipologia = new  QHBoxLayout(tipologiaWrapper);
        layoutTipologia->addWidget(radioBottiglia);
        layoutTipologia->addWidget(radioLattina);

        // Informazioni Bevanda
        QWidget* infoWrapper = new QWidget(this);
        QFormLayout* layoutInfo = new QFormLayout(infoWrapper);
        layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        QLineEdit* nomeBevanda = new QLineEdit(infoWrapper);
        registerField("nomeBevanda*", nomeBevanda);
        QLineEdit* prezzoBevanda = new QLineEdit(infoWrapper);
        registerField("prezzoBevanda*", prezzoBevanda);
        QLineEdit* capacitaBevanda = new QLineEdit(infoWrapper);
        registerField("capacitaBevanda*", capacitaBevanda);
        layoutInfo->addRow("Nome", nomeBevanda);
        layoutInfo->addRow("Prezzo", prezzoBevanda);
        layoutInfo->addRow("Capacità", capacitaBevanda);

        layoutBevanda = new QVBoxLayout(this);
        layoutBevanda->addWidget(tipologiaWrapper);
        layoutBevanda->addWidget(infoWrapper);
        setLayout(layoutBevanda);
    }
}

void nuovoArticolo_dettagli::initializePage(){
    QWizardPage::initializePage();
    if(!previouslyInizialized){
        //registerField
    }
    setActualPage();
    previouslyInizialized = true;
}
