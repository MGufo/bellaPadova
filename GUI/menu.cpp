#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent){
  tmp = new QVBoxLayout(this);
  placeholder = new QLabel("testo del menu", tmp->parentWidget());
  setLayout(tmp);
}
