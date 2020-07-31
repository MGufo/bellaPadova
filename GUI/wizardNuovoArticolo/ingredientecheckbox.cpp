#include "ingredientecheckbox.h"

IngredienteCheckBox::IngredienteCheckBox(QString nomeIngrediente, unsigned int idIngrediente, QWidget *parent) : QCheckBox(parent), id(idIngrediente){
    setText(nomeIngrediente);
}

unsigned int IngredienteCheckBox::getId() const{
    return id;
}
