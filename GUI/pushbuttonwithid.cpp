#include "pushbuttonwithid.h"

PushButtonWithId::PushButtonWithId(uint ID, QWidget* parent) : QPushButton(parent), id(ID){
  connect(this,SIGNAL(clicked(bool)),this,SLOT(emitIdOnButtonClicked()));
}

void PushButtonWithId::setId(uint ID){   id = ID;}

void PushButtonWithId::emitIdOnButtonClicked(){
  emit sendId(id);
}
