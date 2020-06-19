#ifndef NUOVOCONSUMABILE_DETTAGLI_H
#define NUOVOCONSUMABILE_DETTAGLI_H

#include <QWidget>
#include <QWizardPage>
#include <QCheckBox>
#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>
#include <QValidator>

#include "wizard_nuovoconsumabile.h"

class NuovoConsumabile_dettagli : public QWizardPage{
  Q_OBJECT
public:
  NuovoConsumabile_dettagli(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QFormLayout* layoutDettagli;
  QLineEdit* nomeConsumabile = nullptr;
  QLineEdit* quantitaConsumabile = nullptr;
  QLineEdit* costoConsumabile = nullptr;
  QDateEdit* dataAcquisto = nullptr;
  QWidget* campoExtra = nullptr;
  void fieldRegistration();
  void setActualPage();
  void initializePage() override;
};

#endif // NUOVOCONSUMABILE_INGREDIENTE_H
