#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include "GUI/tabellarisorse.h"
#include "wizardNuovoArticolo/wizard_nuovoArticolo.h"
class WizardNuovoArticolo;

class Menu : public QWidget
{
  Q_OBJECT

private:
  TabellaRisorse* tabPizze;
  TabellaRisorse* tabBevande;
  QPushButton* newArticolo;
  QPushButton* modificaDati;
  QStringList* headerLabels;
  QVBoxLayout* layoutMenu;
  WizardNuovoArticolo* nuovoArticolo = nullptr;
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

private slots:
  void modificaTabelle();
};

#endif // MENU_H
