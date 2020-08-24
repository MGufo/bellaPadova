#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QStringList>
#include "GUI/tabellarisorse.h"
#include "GUI/wizardNuovoConsumabile/wizard_nuovoConsumabile.h"
#include "MainWindow.h"

class Inventario : public QWidget
{
    Q_OBJECT
public:
    explicit Inventario(QWidget *parent = nullptr);
signals:

private:
  QPushButton* newConsumabile;
  QPushButton* modificaDati;
  TabellaRisorse* tabIngredienti;
  TabellaRisorse* tabBevande;
  QStringList* headerLabels;
  QVBoxLayout* layoutInventario;
  WizardNuovoConsumabile* nuovoConsumabile;

private slots:
  void drawWizard();
  void modificaTabelle();
};

#endif // INVENTARIO_H
