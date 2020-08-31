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
  bool getPaginaEditabile() const;

public slots:
  void modificaTabelle();

signals:

private:
  bool paginaEditabile;
  QPushButton* newConsumabile;
  QPushButton* modificaDati;
  TabellaRisorse* tabIngredienti;
  TabellaRisorse* tabBevande;
  QStringList* headerLabels;
  QVBoxLayout* layoutInventario;
  WizardNuovoConsumabile* nuovoConsumabile;

private slots:
  void drawWizard();
};

#endif // INVENTARIO_H
