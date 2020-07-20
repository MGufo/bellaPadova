#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "../core/pizzeria.h"
#include "MainWindow.h"
#include "pacchetti.h"

class MainWindow;
class Controller : public QObject {
  Q_OBJECT

 private:
  Pizzeria* modello;
  MainWindow* vista;
  unsigned int idComande;
  unsigned int idRisorse;

 public:
  explicit Controller(Pizzeria*, QObject* parent = nullptr);
  void setView(MainWindow*);
  void calcoloFatturato(const QDate&, const QDate&);
  void creaNuovoConsumabile(pacchetto*);
  void getInventario() const;

 public slots:
  void caricaComande();
  void caricaRisorse();
  void salvaComande() const;
  void salvaRisorse() const;
  void modificaComande();
  void modificaRisorse();
};

#endif
