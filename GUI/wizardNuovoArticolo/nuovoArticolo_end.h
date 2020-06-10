#ifndef NUOVOARTICOLO_END_H
#define NUOVOARTICOLO_END_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

#include "wizard_nuovoArticolo.h"

class NuovoArticolo_end : public QWizardPage{
  Q_OBJECT
public:
  NuovoArticolo_end(QWidget* parent = nullptr);
};

#endif // WIZARD_END_H
