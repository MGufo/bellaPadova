#ifndef NUOVOCONSUMABILE_INGREDIENTE_H
#define NUOVOCONSUMABILE_INGREDIENTE_H

#include <QWidget>
#include <QWizardPage>
#include <QCheckBox>
#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>

#include "wizard_nuovoconsumabile.h"

class NuovoConsumabile_ingrediente : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_ingrediente(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QFormLayout* layoutIngrediente;
};

#endif // NUOVOCONSUMABILE_INGREDIENTE_H
