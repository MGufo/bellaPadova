#ifndef WIZARDNUOVACOMANDA_H
#define WIZARDNUOVACOMANDA_H

#include <QWidget>
#include <QWizard>
#include <QAbstractButton>

#include "../pacchetti.h"
#include "nuovaComanda_dettagli.h"
#include "nuovaComanda_end.h"

class WizardNuovaComanda : public QWizard{
  Q_OBJECT
public:
  enum { PAGE_Dettagli, PAGE_End};
  explicit WizardNuovaComanda(QWidget *parent = nullptr);

  //void accept() override;
signals:
  void nuovaComanda(pacchettoComanda*);
public slots:
  void assegnaBottoni(int);
  void handlerBottoni();
};

#endif // WIZARDNUOVACOMANDA_H
