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
#include "../pacchetti.h"

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  enum { PAGE_Intro, PAGE_Dettagli, PAGE_End};
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);

  void accept() override;
signals:
  void nuovoArticolo(pacchetto*);
public slots:
  void assegnaBottoni(int);
  void handlerBottoni();
};

#endif // WIZARDNUOVOARTICOLO_H
