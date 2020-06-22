#include "ingredientcheckbox.h"

IngredientCheckBox::IngredientCheckBox(QString nomeIngrediente, unsigned int idIngrediente, QWidget *parent) : QCheckBox(parent), id(idIngrediente){
    setText(nomeIngrediente);
}

unsigned int IngredientCheckBox::getId() const{
    return id;
}
