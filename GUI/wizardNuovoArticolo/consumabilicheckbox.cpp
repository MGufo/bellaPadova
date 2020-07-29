#include "consumabilicheckbox.h"

ConsumabiliCheckBox::ConsumabiliCheckBox(QString nomeIngrediente, unsigned int idIngrediente, QWidget *parent) : QCheckBox(parent), id(idIngrediente){
    setText(nomeIngrediente);
}

unsigned int ConsumabiliCheckBox::getId() const{
    return id;
}
