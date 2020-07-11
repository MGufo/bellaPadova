#include "nuovoArticolo_end.h"

NuovoArticolo_end::NuovoArticolo_end(QWidget* parent) : QWizardPage(parent) {
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = nullptr;
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

        layoutEnd->addRow("Nome:", nomePizza);
        layoutEnd->addRow("Prezzo:", prezzoPizza);
        layoutEnd->addRow("Pomodoro:", pomodoro);
        layoutEnd->addRow("Mozzarella:", mozzarella);

        /*auto ptr = static_cast<NuovoArticolo_pizza*>(content);
        auto ingredients = ptr->getIngredientsCheckBoxWrapper()->children();
        for(auto it = ingredients.cbegin(); it != ingredients.cend(); ++it){
            IngredientCheckBox* tmp = static_cast<IngredientCheckBox*>(*it);
            QString id(tmp->getId());
            QLabel* bar = new QLabel(((field(id).toBool()) ? "Si" : "No"), this);
            layoutEnd->addRow(tmp->text(), bar);
        }*/
    }
}

void NuovoArticolo_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}

/* QDialog
 * "Il nuovo articolo è stato inserito con successo nel Menù!"
*/
