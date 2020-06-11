#ifndef NUOVOCONSUMABILE_INTRO_H
#define NUOVOCONSUMABILE_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include "wizard_nuovoconsumabile.h"

class nuovoConsumabile_intro : public QWizardPage{
  Q_OBJECT
public:
  nuovoConsumabile_intro(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutIntro;
  QRadioButton* optionIngrediente;
  QRadioButton* optionBevanda;
  void initializePage() override;
};

#endif // NUOVOCONSUMABILE_INTRO_H
