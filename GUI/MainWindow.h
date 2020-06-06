#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QFile>
#include <QTabWidget>
#include "GUI/comande.h"
#include "GUI/menu.h"
#include "GUI/inventario.h"
#include "GUI/contabilizzazione.h"
#include "GUI/header.h"
#include "GUI/controller.h"
class Controller;
class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 public slots:
  void win_calcoloFatturato(const QDate&, const QDate&);

private:
  Controller* controller;
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
  QMenuBar* drawMenubar() const;
};

#endif
