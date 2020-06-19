#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include "GUI/tabellacomposita.h"
#include "wizardNuovoArticolo/wizard_nuovoArticolo.h"

class Menu : public QWidget
{
  Q_OBJECT

private:
  QVBoxLayout* layoutMenu;
  WizardNuovoArticolo* nuovoArticolo;
  void setStyleMenu();

private slots:
  void drawWizard();
  void invioDatiArticolo();
public:
  explicit Menu(QWidget *parent = nullptr);

signals:
  //
  void invioDatiPizza();
  //id della bevanda contenuta nell'inventario da inserire nel menu
  void invioDatiBevanda(unsigned int);

public slots:
};

#endif // MENU_H
