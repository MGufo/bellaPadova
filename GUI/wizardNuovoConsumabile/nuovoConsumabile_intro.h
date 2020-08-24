#ifndef NUOVOCONSUMABILE_INTRO_H
#define NUOVOCONSUMABILE_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include "GUI/wizardNuovoConsumabile/wizard_nuovoConsumabile.h"

class NuovoConsumabile_intro : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_intro(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutIntro;
  QRadioButton* optionBevanda;
  QRadioButton* optionIngrediente;
  QRadioButton* optionFarina;
};

#endif // NUOVOCONSUMABILE_INTRO_H
