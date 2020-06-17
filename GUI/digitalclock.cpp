#include <QtWidgets>

#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent){
  setSegmentStyle(Flat);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
  timer->start(1000);
  showTime();
  setStyleLCD();
}

void DigitalClock::showTime(){
  QTime time = QTime::currentTime();
  QString text = time.toString("hh:mm");

  if ((time.second() % 2) == 0) text[2] = ' ';
  display(text);
}

void DigitalClock::setStyleLCD(){
  QPalette* paletteLCD = new QPalette;
  paletteLCD->setColor(QPalette::Window, QColor(0,0,0));
  paletteLCD->setColor(QPalette::WindowText, QColor(255,0,0));
  setPalette(*paletteLCD);
  setAutoFillBackground(true);
  resize(100, 100);
  //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  setMaximumSize(250, 100);
  //setContentsMargins(0,0,0,0);
}
