#ifndef WIZARD_PIZZA_H
#define WIZARD_PIZZA_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLabel>
#include <QScrollArea>
#include <QTextEdit>

#include "./GUI/wizardNuovoArticolo/wizardNuovoArticolo.h"

class wizard_pizza: public QWizardPage{
  Q_OBJECT
public:
  wizard_pizza(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutPizza;
};

#endif // WIZARD_PIZZA_H
