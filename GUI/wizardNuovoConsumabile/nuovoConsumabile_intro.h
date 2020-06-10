#ifndef NUOVOCONSUMABILE_INTRO_H
#define NUOVOCONSUMABILE_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

class nuovoConsumabile_intro : public QWizardPage{
  Q_OBJECT
public:
  nuovoConsumabile_intro(QWidget* parent = nullptr);
  int nextId() const override;
};

#endif // NUOVOCONSUMABILE_INTRO_H
