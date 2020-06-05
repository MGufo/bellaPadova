#ifndef WIZARDNUOVOARTICOLO_H
#define WIZARDNUOVOARTICOLO_H

#include <QWidget>
#include <QWizard>

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);

signals:

public slots:
  //void accept() override;
};

#endif // WIZARDNUOVOARTICOLO_H
