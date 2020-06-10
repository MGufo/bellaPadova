#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QStringList>
#include "GUI/tabellacomposita.h"
#include "wizardNuovoConsumabile/wizard_nuovoconsumabile.h"

class Inventario : public QWidget
{
    Q_OBJECT
public:
    explicit Inventario(QWidget *parent = nullptr);

signals:

public slots:

private:
  QVBoxLayout* layoutInventario;
  void setStyleInventario();
  WizardNuovoConsumabile* nuovoConsumabile;

private slots:
  void drawWizard();
};

#endif // INVENTARIO_H
