#include "nuovoArticolo_end.h"

NuovoArticolo_end::NuovoArticolo_end(QWidget* parent) : QWizardPage(parent) {
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = new QFormLayout(this);
    setLayout(layoutEnd);
}

void NuovoArticolo_end::setActualPage(){
    if(layoutEnd) delete layoutEnd;
    layoutEnd = new QFormLayout(this);

    if(field("optionPizza").toBool()){
        QLabel* nomePizza = new QLabel(field("nomePizza").toString(), this);
        QLabel* prezzoPizza = new QLabel(field("prezzoPizza").toString(), this);
        QLabel* pomodoro = new QLabel(((field("pomodoro").toBool()) ? "Si" : "No"), this);
        QLabel* mozzarella = new QLabel(((field("mozzarella").toBool()) ? "Si" : "No"), this);

        QWidget* wrapper = new QWidget(this);
        QVBoxLayout* ingredientsLayout = new QVBoxLayout(wrapper);

        /*
        //una funzione del controller si occuperà di prendere tutti gli ingredienti disponibili presenti nell'inventario
        //TODO:
        //-recuperare tutti gli ingredienti dall'inventario
        //-verificare per ogni id di ingredienti se è stato checkato dall'utente e in caso farlo visualizzare inserendolo nel layout
        */

        QLabel* ing1 = new QLabel("curcuma",this);
        QLabel* ing2 = new QLabel("porcospino",this);
        QLabel* ing3 = new QLabel("diospino",this);
        QLabel* ing4 = new QLabel("boiamerda",this);
        ingredientsLayout->addWidget(ing1);
        ingredientsLayout->addWidget(ing2);
        ingredientsLayout->addWidget(ing3);
        ingredientsLayout->addWidget(ing4);

        layoutEnd->addRow("Nome:", nomePizza);
        layoutEnd->addRow("Prezzo:", prezzoPizza);
        layoutEnd->addRow("Pomodoro:", pomodoro);
        layoutEnd->addRow("Mozzarella:", mozzarella);
        layoutEnd->addRow("Ingredienti:", wrapper);
    }
}

void NuovoArticolo_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}

/* QDialog
 * "Il nuovo articolo è stato inserito con successo nel Menù!"
*/
