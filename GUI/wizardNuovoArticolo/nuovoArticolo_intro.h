#ifndef NUOVOARTICOLO_INTRO_H
#define NUOVOARTICOLO_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include "wizard_nuovoArticolo.h"

class NuovoArticolo_intro : public QWizardPage{
  Q_OBJECT
public:
  NuovoArticolo_intro(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutIntro;
  QRadioButton* optionPizza;
  QRadioButton* optionBevanda;
};

#endif // NUOVOARTICOLO_INTRO_H
