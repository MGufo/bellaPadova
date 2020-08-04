#include "nuovoArticolo_end.h"
#include <iostream>

NuovoArticolo_end::NuovoArticolo_end(QWidget* parent) : QWizardPage(parent) {
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = new QFormLayout(this);
    connect(this,SIGNAL(riempiWizardConElementiCheckati(bool)),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiCheckatiInWizard(bool)));
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


    if(field("optionPizza").toBool()){
        QLabel* nomePizza = new QLabel(field("nomePizza").toString(), this);
        nomePizza->setObjectName("nomePizza");
        layoutEnd->addRow("Nome:", nomePizza);

        QLabel* prezzoPizza = new QLabel(field("prezzoPizza").toString(), this);
        prezzoPizza->setObjectName("prezzoPizza");
        layoutEnd->addRow("Prezzo:", prezzoPizza);

        QWidget* wrapper = new QWidget(this);
        wrapper->setObjectName("ingredientiVisualizationWrapper");
        QVBoxLayout* ingredientsLayout = new QVBoxLayout(wrapper);
        wrapper->setLayout(ingredientsLayout);
        layoutEnd->addRow("Ingredienti:", wrapper);

        emit riempiWizardConElementiCheckati(true);
    }
    else{

    }
}

void NuovoArticolo_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}

/* QDialog
 * "Il nuovo articolo è stato inserito con successo nel Menù!"
*/
