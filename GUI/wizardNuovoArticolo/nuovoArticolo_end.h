#ifndef NUOVOARTICOLO_END_H
#define NUOVOARTICOLO_END_H

#include <QWidget>
#include <QWizardPage>

#include "wizard_nuovoArticolo.h"

class NuovoArticolo_end : public QWizardPage{
  Q_OBJECT
public:
  NuovoArticolo_end(QWidget* parent = nullptr);
private:
  QFormLayout* layoutEnd;
  void setActualPage();
  void initializePage() override;
signals:
  //true = pizza
  //false = bevanda
  riempiWizardConElementiCheckati(bool);
};

#endif // WIZARD_END_H
