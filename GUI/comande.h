#ifndef COMANDE_H
#define COMANDE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include "dettaglioComanda.h"
#include "comandagui.h"
#include "wizardNuovaComanda/wizard_nuovaComanda.h"

class Comande : public QWidget{
  Q_OBJECT
public:
  explicit Comande(QWidget *parent = nullptr);
  void aggiungiComanda(pacchettoComanda*);

private:
  QPushButton* newComanda;
  QVBoxLayout* comandeLayout;
  QHBoxLayout* layout_inEsecuzione;
  QHBoxLayout* layout_eseguite;
  void setStyleComande();
  WizardNuovaComanda* nuovaComanda;

signals:

private slots:
    void drawWizard();
};

#endif // COMANDE_H
