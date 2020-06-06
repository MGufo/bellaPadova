#ifndef WIZARD_PIZZA_H
#define WIZARD_PIZZA_H

#include <QWidget>
#include <QWizardPage>

class wizard_Pizza: public QWizardPage{
  Q_OBJECT
public:
  wizard_Pizza(QWidget* parent);
  int nextId() const override;

private:
  QVBoxLayout* layoutPizza;
};

#endif // WIZARD_INTRO_H
