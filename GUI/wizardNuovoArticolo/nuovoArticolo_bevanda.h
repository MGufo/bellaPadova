#ifndef NUOVOARTICOLO_BEVANDA_H
#define NUOVOARTICOLO_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QLineEdit>
#include <QFormLayout>
#include <QRadioButton>
#include <QVBoxLayout>

#include "./GUI/wizardNuovoArticolo/wizard_nuovoArticolo.h"

class NuovoArticolo_bevanda : public QWizardPage{
  Q_OBJECT
public:
  NuovoArticolo_bevanda(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutBevanda;
};
#endif // WIZARD_BEVANDA_H
