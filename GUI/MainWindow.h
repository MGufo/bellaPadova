#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QErrorMessage>
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
  MainWindow(Controller* c, QWidget* parent = nullptr);
  ~MainWindow();
  void aggiornaContabilizzazione(double);

 public slots:
  void calcoloFatturato(const QDate&, const QDate&);
  void mostraErrore(const QString&);

private:
  Controller* controller;
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
  QMenuBar* drawMenubar() const;

};

#endif
