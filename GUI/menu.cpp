#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent){
  tmp = new QVBoxLayout(this);
  QLabel* placeholder = new QLabel("testo del menu", this);
  tmp->addWidget(placeholder);
  setStyleMenu();
  setLayout(tmp);
}

void Menu::setStyleMenu(){
  tmp->setSpacing(0);
  tmp->setMargin(0);
  tmp->setContentsMargins(-1,0,-1,-1);
  setMinimumSize(QSize(900,300));
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
