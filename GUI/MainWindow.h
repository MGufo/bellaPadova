#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QErrorMessage>
#include <QMenuBar>
#include <QFile>
#include <QTabWidget>
#include <QList>

#include "GUI/comande.h"
#include "GUI/menu.h"
#include "GUI/inventario.h"
#include "GUI/contabilizzazione.h"
#include "GUI/header.h"
#include "GUI/controller.h"
#include "GUI/pacchetti.h"

class Controller;
class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(Controller* c, QWidget* parent = nullptr);
  ~MainWindow();
  void aggiornaContabilizzazione(double);
  void pulisciInventario();
  void aggiornaInventario(pacchetto*);
  void visualizzaInventario();
  void aggiornaMenu(pacchetto*);
  void visualizzaMenu();
  void mostraErrore(const QString&);

signals:
  void saveAndExit();

 public slots:
  void calcoloFatturato(const QDate&, const QDate&);
  void creaNuovoConsumabile(pacchetto*);
  void modificaConsumabile(pacchetto*);
  void eliminaConsumabile(uint);
  //true = pizza
  //false = bevanda
  void visualizzaElementiInWizard(bool) const;
  void visualizzaElementiCheckatiInWizard(bool) const;

protected:
  void closeEvent(QCloseEvent *event);
private:
  Controller* controller;
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
  QMenuBar* drawMenubar() const;

};

#endif
