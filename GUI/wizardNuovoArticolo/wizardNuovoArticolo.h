#ifndef WIZARDNUOVOARTICOLO_H
#define WIZARDNUOVOARTICOLO_H

#include <QWidget>
#include <QWizard>
#include <QMessageBox>
#include <QString>

#include "GUI/wizardNuovoArticolo/wizard_intro.h"
#include "GUI/wizardNuovoArticolo/wizard_pizza.h"
#include "GUI/wizardNuovoArticolo/wizard_bevanda.h"
#include "GUI/wizardNuovoArticolo/wizard_end.h"

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  enum { PAGE_Intro, PAGE_Pizza, PAGE_Bevanda, PAGE_End};
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);
};

#endif // WIZARDNUOVOARTICOLO_H
