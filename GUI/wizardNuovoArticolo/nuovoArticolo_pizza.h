#ifndef NUOVOARTICOLO_PIZZA_H
#define NUOVOARTICOLO_PIZZA_H

#include <QWidget>
#include <QWizardPage>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>

#include "./GUI/wizardNuovoArticolo/wizard_nuovoArticolo.h"

class NuovoArticolo_pizza: public QWizardPage{
  Q_OBJECT
public:
  NuovoArticolo_pizza(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QGridLayout* layoutPizza;
};

#endif // WIZARD_PIZZA_H
