#ifndef WIZARD_BEVANDA_H
#define WIZARD_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QFormLayout>
#include <QTextEdit>

#include "./GUI/wizardNuovoArticolo/wizardNuovoArticolo.h"

class wizard_bevanda : public QWizardPage{
  Q_OBJECT
public:
  wizard_bevanda(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutBevanda;
};
#endif // WIZARD_BEVANDA_H
