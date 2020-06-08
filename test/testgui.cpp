#include "testgui.h"
#include <QList>
#include <QMetaObject>
#include <iostream>
#include <QApplication>
#include <typeinfo>
#include <QLabel>

testGUI::testGUI(QWidget* parent) : QWidget(parent){
  layout = new QVBoxLayout(this);
  testLabel* label = new testLabel(this);
  label->setObjectName("testLabel");
  layout->addWidget(label);
  setLayout(layout);
}

testLabel::testLabel(QWidget *parent, int X) : QWidget(parent){
  layout2 = new QHBoxLayout(this);
  x = X;
  testButton* test2 = new testButton(this);
  test2->setObjectName("testButton");
  layout2->addWidget(test2);
  setLayout(layout2);
}

testButton::testButton(QWidget *parent, double X) : QWidget(parent){
  y = X;
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  testGUI* view = new testGUI();
  std::cout << view->findChild<testButton*>("testButton")->y << std::endl;
  //return app.exec();
}
