#ifndef WIZARDNUOVOCONSUMABILE_H
#define WIZARDNUOVOCONSUMABILE_H

#include <QWidget>
#include <QWizard>

#include "nuovoConsumabile_intro.h"
#include "nuovoConsumabile_dettagli.h"
#include "nuovoConsumabile_end.h"

class WizardNuovoConsumabile : public QWizard{
  Q_OBJECT
public:
  enum {PAGE_Intro, PAGE_Dettagli, PAGE_End};
  explicit WizardNuovoConsumabile(QWidget* parent = nullptr);

  void accept() override;
};

#endif // WIZARDNUOVOCONSUMABILE_H
