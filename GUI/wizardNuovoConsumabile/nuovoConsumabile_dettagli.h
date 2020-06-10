#ifndef NUOVOCONSUMABILE_DETTAGLI_H
#define NUOVOCONSUMABILE_DETTAGLI_H

#include <QWidget>
#include <QWizardPage>
#include <QCheckBox>
#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>

#include "wizard_nuovoconsumabile.h"

class NuovoConsumabile_dettagli : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_dettagli(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QFormLayout* layoutDettagli;
};

#endif // NUOVOCONSUMABILE_INGREDIENTE_H
