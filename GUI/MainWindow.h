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

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private:
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
  QMenuBar* drawMenubar() const;
};

#endif
