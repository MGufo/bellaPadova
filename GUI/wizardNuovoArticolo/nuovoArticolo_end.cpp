#include "nuovoArticolo_end.h"

NuovoArticolo_end::NuovoArticolo_end(QWidget* parent) : QWizardPage(parent) {
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = new QFormLayout(this);
    connect(this,SIGNAL(riempiWizardConElementiCheckati(bool)),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiCheckatiInWizard(bool)));
    setLayout(layoutEnd);
}

void NuovoArticolo_end::setActualPage(){
    if(layoutEnd) delete layoutEnd;
    layoutEnd = new QFormLayout(this);
    QLabel* ptr = nullptr;
    ptr = findChild<QLabel*>("nomePizza");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("prezzoPizza");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("pomodoro");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("mozzarella");
    if(ptr) layoutEnd->removeRow(ptr);

    if(field("optionPizza").toBool()){
        QLabel* nomePizza = new QLabel(field("nomePizza").toString(), this);
        nomePizza->setObjectName("nomePizza");
        layoutEnd->addRow("Nome:", nomePizza);

        QLabel* prezzoPizza = new QLabel(field("prezzoPizza").toString(), this);
        nomePizza->setObjectName("prezzoPizza");
        layoutEnd->addRow("Prezzo:", prezzoPizza);

        QLabel* pomodoro = new QLabel(((field("pomodoro").toBool()) ? "Si" : "No"), this);
        nomePizza->setObjectName("pomodoro");
        layoutEnd->addRow("Pomodoro:", pomodoro);

        QLabel* mozzarella = new QLabel(((field("mozzarella").toBool()) ? "Si" : "No"), this);
        nomePizza->setObjectName("mozzarella");
        layoutEnd->addRow("Mozzarella:", mozzarella);

        QWidget* wrapper = new QWidget(this);
        wrapper->setObjectName("ingredientiVisualizationWrapper");
        QVBoxLayout* ingredientsLayout = new QVBoxLayout(wrapper);
        wrapper->setLayout(ingredientsLayout);
        layoutEnd->addRow("Ingredienti:", wrapper);

        emit riempiWizardConElementiCheckati(true);

        /*
        //una funzione del controller si occuperà di prendere tutti gli ingredienti disponibili presenti nell'inventario
        //TODO:
        //-recuperare tutti gli ingredienti dall'inventario
        //-verificare per ogni id di ingredienti se è stato checkato dall'utente e in caso farlo visualizzare inserendolo nel layout
        */
        /*
        QLabel* ing1 = new QLabel("curcuma",this);
        QLabel* ing2 = new QLabel("porcospino",this);
        QLabel* ing3 = new QLabel("diospino",this);
        QLabel* ing4 = new QLabel("boiamerda",this);
        ingredientsLayout->addWidget(ing1);
        ingredientsLayout->addWidget(ing2);
        ingredientsLayout->addWidget(ing3);
        ingredientsLayout->addWidget(ing4);
        */
    }
}

void NuovoArticolo_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}

/* QDialog
 * "Il nuovo articolo è stato inserito con successo nel Menù!"
*/
