#ifndef WIZARD_NUOVOCONSUMABILE_H
#define WIZARD_NUOVOCONSUMABILE_H

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
};

#endif // WIZARD_NUOVOCONSUMABILE_H
