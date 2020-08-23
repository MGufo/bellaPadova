#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QErrorMessage>
#include <QMenuBar>
#include <QFile>
#include <QTabWidget>
#include <QList>
#include <QSpinBox>

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
  void pulisciComande();
  void visualizzaComande();
  void riapriComanda(uint);

signals:
  void saveAndExit();

 public slots:
  void mostraErrore(const QString&);
  void calcoloFatturato(const QDate&, const QDate&);
  void creaNuovoArticolo(pacchettoArticolo*);
  void creaNuovoConsumabile(pacchettoConsumabile*);
  void modificaArticolo(pacchettoArticolo*);
  void modificaConsumabile(pacchettoConsumabile*);
  void eliminaArticolo(uint);
  void eliminaConsumabile(uint);
  //true = pizza
  //false = bevanda
  void creaNuovaComanda(pacchettoComanda*);
  void modificaComanda(pacchettoComanda*);
  void eliminaComanda(uint);
  void richiediDettagliComanda(uint);
  void aumentaCurrent();
  void visualizzaElementiInWizardArticolo(bool) const;
  void visualizzaElementiCheckatiInWizardArticolo(bool) const;
  void visualizzaElementiInWizardComanda() const;
  void visualizzaElementiCheckatiInWizardComanda() const;
  void visualizzaMenuInComanda(uint) const;

protected:
  void closeEvent(QCloseEvent *);
private:
  Controller* controller;
  QVBoxLayout* mainLayout;
  void setStylePizzeria();
  QMenuBar* drawMenubar() const;

};

#endif
