#ifndef WIZARD_END_H
#define WIZARD_END_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

#include "wizardNuovoArticolo.h"

class wizard_end : public QWizardPage{
  Q_OBJECT
public:
  wizard_end(QWidget* parent = nullptr);

private:
  QVBoxLayout* layoutEnd;
};

#endif // WIZARD_END_H
