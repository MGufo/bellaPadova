#ifndef WIZARDNUOVOARTICOLO_H
#define WIZARDNUOVOARTICOLO_H

#include <QWidget>
#include <QWizard>
#include <QMessageBox>
#include <QString>

#include "GUI/wizardNuovoArticolo/nuovoArticolo_intro.h"
#include "GUI/wizardNuovoArticolo/nuovoArticolo_dettagli.h"
#include "GUI/wizardNuovoArticolo/nuovoArticolo_pizza.h"
#include "GUI/wizardNuovoArticolo/nuovoArticolo_bevanda.h"
#include "GUI/wizardNuovoArticolo/nuovoArticolo_end.h"

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  enum { PAGE_Intro, PAGE_Dettagli, PAGE_End};
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);

  void accept() override;
public slots:
  void assegnaBottoni(int);
};

#endif // WIZARDNUOVOARTICOLO_H
