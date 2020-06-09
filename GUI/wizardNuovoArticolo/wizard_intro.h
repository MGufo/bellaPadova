#ifndef WIZARD_INTRO_H
#define WIZARD_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include "wizardNuovoArticolo.h"

class Wizard_intro : public QWizardPage{
  Q_OBJECT
public:
  Wizard_intro(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutIntro;
  QRadioButton* optionPizza;
  QRadioButton* optionBevanda;
};

#endif // WIZARD_INTRO_H
