#include "header.h"
#include <iostream>

Header::Header(QWidget *parent) : QWidget(parent){
  headerLayout = new QHBoxLayout(this);
  QLabel* bellaPadova = new QLabel("Pizzeria Bella Padova",this);
  QLabel* indirizzo = new QLabel("Via Gioacchino Rossini, 20",this);
  QLabel* telefono = new QLabel("1234567890", this);
  headerLayout->addWidget(bellaPadova);
  headerLayout->addWidget(indirizzo);
  headerLayout->addWidget(telefono);
  analogClock* orologio = new analogClock(this);
  headerLayout->addWidget(orologio);
  setStyleHeader();
  setLayout(headerLayout);
}

void Header::setStyleHeader(){
  headerLayout->setSpacing(0);
  headerLayout->setMargin(0);
  setMinimumSize(QSize(900,200));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  //headerLayout->setContentsMargins(-1,-1,-1,0);
}
