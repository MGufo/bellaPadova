#ifndef COMANDE_H
#define COMANDE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include "comandagui.h"
#include "wizardNuovaComanda/wizard_nuovaComanda.h"

class Comande : public QWidget{
  Q_OBJECT
public:
  explicit Comande(QWidget *parent = nullptr);
  void aggiungiComanda(pacchettoComanda*);

private:
  QHBoxLayout* layout_eseguite;
  QHBoxLayout* layout_inEsecuzione;
  QPushButton* newComanda;
  QScrollArea* scroll_eseguite;
  QScrollArea* scroll_inEsecuzione;
  QVBoxLayout* comandeLayout;
  QWidget* wrapper_eseguite;
  QWidget* wrapper_inEsecuzione;
  WizardNuovaComanda* nuovaComanda;
  void setStyleComande();

signals:

private slots:
    void drawWizard();
};

#endif // COMANDE_H
