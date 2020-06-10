#ifndef WIZARD_PIZZA_H
#define WIZARD_PIZZA_H

#include <QWidget>
#include <QWizardPage>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>

#include "./GUI/wizardNuovoArticolo/wizardNuovoArticolo.h"

class WizardPage_pizza: public QWizardPage{
  Q_OBJECT
public:
  WizardPage_pizza(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QGridLayout* layoutPizza;
};

#endif // WIZARD_PIZZA_H
