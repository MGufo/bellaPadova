#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QList>

#include "../core/pizzeria.h"
#include "../core/utils.h"
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
  uint getIndexOf(const Lista<Comanda*>&, const uint) const;
  pacchettoComanda* impacchettaComanda(const Comanda*, bool) const;
  pacchetto* trovaPacchetto(uint) const;
 public:
  explicit Controller(Pizzeria*,  uint, uint, QObject* parent = nullptr);
  void setView(MainWindow*);
  void calcoloFatturato(const QDate&, const QDate&);
  void creaNuovoArticolo(pacchettoArticolo*);
  void creaNuovoConsumabile(pacchettoConsumabile*);
  void modificaConsumabile(pacchettoConsumabile*);
  void eliminaConsumabile(uint);
  void modificaArticolo(pacchettoArticolo*);
  void eliminaArticolo(uint);
  void creaNuovaComanda(pacchettoComanda*);
  void modificaComanda(pacchettoComanda*);
  void eliminaComanda(uint);
  void eseguiComanda();
  QList<pacchetto*>* recuperaInventario() const;
  QList<pacchetto*>* recuperaMenu() const;
  QList<pacchettoComanda*>* recuperaComande() const;
  const pacchettoComanda* recuperaInfoComanda(uint) const;
  QList<pacchetto*>* recuperaContenutoComanda(uint) const;
  const QList<pacchetto*>* recuperaMenuPerComanda(uint) const;
  const QList<pacchetto *> *recuperaMenuPerWizardNuovaComanda() const;
  bool canQuit() const;
  void eliminaPacchettiRisorsa(QList<pacchetto*>*) const;
  void eliminaPacchettiComanda(QList<pacchettoComanda*>*) const;

 public slots:
  void caricaComande();
  void caricaRisorse();
  void salvaComande();
  void salvaRisorse();
  void saveAndExit();
};

#endif
