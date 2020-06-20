#ifndef NUOVOCONSUMABILE_END_H
#define NUOVOCONSUMABILE_END_H

#include <QWidget>
#include <QWizardPage>
#include <QFormLayout>

#include "wizard_nuovoConsumabile.h"

class NuovoConsumabile_end : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_end(QWidget* parent = nullptr);
private:
  QFormLayout* layoutEnd;
  QLabel* nomeConsumabile = nullptr;
  QLabel* quantitaConsumabile = nullptr;
  QLabel* costoConsumabile = nullptr;
  QLabel* dataAcquisto = nullptr;
  QLabel* campoExtra = nullptr;
  void setInitialPage();
  void setActualPage();
  void initializePage() override;
};

#endif // NUOVOCONSUMABILE_END_H
