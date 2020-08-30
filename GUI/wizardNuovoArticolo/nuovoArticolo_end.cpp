#include "nuovoArticolo_end.h"
#include <iostream>

NuovoArticolo_end::NuovoArticolo_end(QWidget* parent) : QWizardPage(parent) {
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = new QFormLayout(this);
    connect(this,SIGNAL(riempiWizardConElementiCheckati(bool)),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiCheckatiInWizardArticolo(bool)));
    setLayout(layoutEnd);
}

void NuovoArticolo_end::setActualPage(){
    //eliminazione dei campi precedenti se esistono
    QLabel* ptr = nullptr;
    ptr = findChild<QLabel*>("nomePizza");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("prezzoPizza");
    if(ptr) layoutEnd->removeRow(ptr);
    QWidget* ptr1 = findChild<QWidget*>("ingredientiVisualizationWrapper");
    if(ptr1) layoutEnd->removeRow(ptr1);
    ptr1 = findChild<QWidget*>("farinaVisualizationWrapper");
    if(ptr1) layoutEnd->removeRow(ptr1);
    ptr1 = findChild<QWidget*>("bevandeVisualizationWrapper_articoli");
    if(ptr1) layoutEnd->removeRow(ptr1);


    if(field("optionPizza").toBool()){
        QLabel* nomePizza = new QLabel(field("nomePizza").toString(), this);
        nomePizza->setObjectName("nomePizza");
        layoutEnd->addRow("Nome:", nomePizza);

        QLabel* prezzoPizza = new QLabel(field("prezzoPizza").toString(), this);
        prezzoPizza->setObjectName("prezzoPizza");
        layoutEnd->addRow("Prezzo:", prezzoPizza);

        QWidget* wrapperFarina = new QWidget(this);
        wrapperFarina->setObjectName("farinaVisualizationWrapper");
        QVBoxLayout* farinaLayout = new QVBoxLayout(wrapperFarina);
        wrapperFarina->setLayout(farinaLayout);
        layoutEnd->addRow("Farina:", wrapperFarina);

        QWidget* wrapperIngredienti = new QWidget(this);
        wrapperIngredienti->setObjectName("ingredientiVisualizationWrapper");
        QVBoxLayout* ingredientsLayout = new QVBoxLayout(wrapperIngredienti);
        wrapperIngredienti->setLayout(ingredientsLayout);
        layoutEnd->addRow("Ingredienti:", wrapperIngredienti);

        emit riempiWizardConElementiCheckati(true);
    }
    else{
        QWidget* wrapperBevande = new QWidget(this);
        wrapperBevande->setObjectName("bevandeVisualizationWrapper_articoli");
        QVBoxLayout* bevandeLayout = new QVBoxLayout(wrapperBevande);
        wrapperBevande->setLayout(bevandeLayout);
        layoutEnd->addRow("Bevande:", wrapperBevande);

        emit riempiWizardConElementiCheckati(false);
    }
}

void NuovoArticolo_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}

