#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QStringList>
#include "GUI/tabellacomposita.h"
#include "wizardNuovoArticolo/wizard_nuovoArticolo.h"

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
  WizardNuovoArticolo* nuovoArticolo;

private slots:
  void drawWizard();
};

#endif // INVENTARIO_H
