#ifndef WIZARD_BEVANDA_H
#define WIZARD_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QLineEdit>
#include <QFormLayout>
#include <QRadioButton>
#include <QVBoxLayout>

#include "./GUI/wizardNuovoArticolo/wizardNuovoArticolo.h"

class WizardPage_bevanda : public QWizardPage{
  Q_OBJECT
public:
  WizardPage_bevanda(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutBevanda;
};
#endif // WIZARD_BEVANDA_H
