#ifndef WIZARD_NUOVOCONSUMABILE_H
#define WIZARD_NUOVOCONSUMABILE_H

#include <QWidget>
#include <QWizard>

class WizardNuovoConsumabile : public QWizard{
  Q_OBJECT
public:
  enum {PAGE_Intro, PAGE_Ingrediente, PAGE_Bevanda, PAGE_End};
  explicit WizardNuovoConsumabile(QWidget* parent = nullptr);
};

#endif // WIZARD_NUOVOCONSUMABILE_H
