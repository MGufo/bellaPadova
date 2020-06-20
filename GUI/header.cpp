#include "header.h"
#include <iostream>

Header::Header(QWidget *parent) : QWidget(parent){
  layoutHeader = new QHBoxLayout(this);
  QPixmap image(":/resources/Bella Padova.png");
  QLabel* bellaPadova = new QLabel("", this);
  bellaPadova->setObjectName("bellaPadova");
  bellaPadova->setMinimumWidth(200);
  bellaPadova->setMinimumHeight(200);
  bellaPadova->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  int w = bellaPadova->width();
  int h = bellaPadova->height();
  bellaPadova->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
  QLabel* indirizzo = new QLabel("Via Gioacchino Rossini, 20",this);
  QLabel* telefono = new QLabel("1234567890", this);
  layoutHeader->addWidget(bellaPadova, 0, Qt::AlignLeft);
  layoutHeader->addWidget(indirizzo);
  layoutHeader->addWidget(telefono);
  //analogClock* orologio = new analogClock(this);
  DigitalClock* orologio = new DigitalClock(this);
  orologio->setObjectName("orologio");
  layoutHeader->addWidget(orologio, 0, Qt::AlignCenter);
  setStyleHeader();
  setLayout(layoutHeader);
}

void Header::setStyleHeader(){
  //layoutHeader->setSpacing(0);
  setMinimumSize(QSize(900,200));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
