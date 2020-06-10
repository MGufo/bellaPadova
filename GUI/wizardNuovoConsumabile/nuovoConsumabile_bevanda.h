#ifndef NUOVOCONSUMABILE_BEVANDA_H
#define NUOVOCONSUMABILE_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>

#include "wizard_nuovoconsumabile.h"
class NuovoConsumabile_bevanda : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_bevanda(QWidget* parent = nullptr);
  int nextId() const override;
private:
  QFormLayout* layoutBevanda;
};

#endif // NUOVOCONSUMABILE_BEVANDA_H
