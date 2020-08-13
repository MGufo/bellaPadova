#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QList>

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
  bool comandeSalvate = true, risorseSalvate = true;

 public:
  explicit Controller(Pizzeria*,  uint, uint, QObject* parent = nullptr);
  void setView(MainWindow*);
  void calcoloFatturato(const QDate&, const QDate&);
  void creaNuovoConsumabile(pacchetto*);
  void modificaConsumabile(pacchetto*);
  void eliminaConsumabile(uint);
  void creaNuovoArticolo(pacchetto*);
  void modificaArticolo(pacchetto*);
  void eliminaArticolo(uint);
  void creaNuovaComanda(pacchetto*);
  void modificaComanda(pacchetto*);
  void eliminaComanda(uint);
  QList<pacchetto*>* recuperaInventario() const;
  QList<pacchetto*>* recuperaMenu() const;
  QList<pacchettoComanda*>* recuperaComande() const;
  bool canQuit() const;

 public slots:
  void caricaComande();
  void caricaRisorse();
  void salvaComande();
  void salvaRisorse();
  void modificaComande();
  void modificaRisorse();
  void saveAndExit();
};

#endif
