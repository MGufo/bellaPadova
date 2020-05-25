#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFile>
#include "GUI/menu.h"
#include "../GUI/header.h"

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private:
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
};

#endif
