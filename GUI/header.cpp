#include "header.h"
#include <iostream>

Header::Header(QWidget *parent) : QWidget(parent){
  layoutHeader = new QHBoxLayout(this);
  QLabel* bellaPadova = new QLabel("Pizzeria Bella Padova",this);
  QLabel* indirizzo = new QLabel("Via Gioacchino Rossini, 20",this);
  QLabel* telefono = new QLabel("1234567890", this);
  layoutHeader->addWidget(bellaPadova);
  layoutHeader->addWidget(indirizzo);
  layoutHeader->addWidget(telefono);
  //analogClock* orologio = new analogClock(this);
  DigitalClock* orologio = new DigitalClock(this);
  layoutHeader->addWidget(orologio);
  setStyleHeader();
  setLayout(layoutHeader);
}

void Header::setStyleHeader(){
  layoutHeader->setSpacing(0);
  layoutHeader->setMargin(0);
  setMinimumSize(QSize(900,100));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  //layoutHeader->setContentsMargins(-1,-1,-1,0);
}
