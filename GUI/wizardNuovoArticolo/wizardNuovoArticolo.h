#ifndef WIZARDNUOVOARTICOLO_H
#define WIZARDNUOVOARTICOLO_H

#include <QWidget>
#include <QWizard>
#include <QMessageBox>
#include <QString>

#include "GUI/wizardNuovoArticolo/wizard_intro.h"
#include "GUI/wizardNuovoArticolo/wizard_Pizza.h"
#include "GUI/wizard_Bevanda"
#include "GUI/wizard_End"

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  enum { PAGE_Intro, PAGE_Pizza, PAGE_Bevanda, PAGE_End};
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);

private slots:
  void mostraAiuto();
};

#endif // WIZARDNUOVOARTICOLO_H
