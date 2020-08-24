#ifndef NUOVOARTICOLO_DETTAGLI_H
#define NUOVOARTICOLO_DETTAGLI_H

#include <QObject>
#include <QWidget>
#include <QWizardPage>
#include <QFormLayout>
#include <string>
using std::string;

#include "GUI/wizardNuovoArticolo/wizard_nuovoArticolo.h"

class NuovoArticolo_dettagli : public QWizardPage{
  Q_OBJECT
public:
    NuovoArticolo_dettagli(QWidget* parent = nullptr);
    int nextId() const override;

private:
    QVBoxLayout* layoutDettagli;
    QWidget* content;
    void setActualPage();
    void initializePage() override;

signals:
    //true = pizza
    //false = bevanda
    void riempiWizardConElementiArticolo(bool);
};

#endif // NUOVOARTICOLO_DETTAGLI_H
