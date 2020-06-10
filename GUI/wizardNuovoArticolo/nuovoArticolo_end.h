#ifndef WIZARD_END_H
#define WIZARD_END_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

#include "wizard_nuovoArticolo.h"

class WizardPage_end : public QWizardPage{
  Q_OBJECT
public:
  WizardPage_end(QWidget* parent = nullptr);
};

#endif // WIZARD_END_H
