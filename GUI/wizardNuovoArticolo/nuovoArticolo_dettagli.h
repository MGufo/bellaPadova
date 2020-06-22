#ifndef NUOVOARTICOLO_DETTAGLI_H
#define NUOVOARTICOLO_DETTAGLI_H

#include <QObject>
#include <QWidget>
#include <QWizardPage>
#include <QFormLayout>

#include "wizard_nuovoArticolo.h"

class nuovoArticolo_dettagli : public QWizardPage{
  Q_OBJECT
public:
    nuovoArticolo_dettagli(QWidget* parent = nullptr);
    int nextId() const override;

private:
    QLayout* layoutDettagli;

    bool previouslyInizialized;
    void setActualPage();
    void initializePage() override;
};

#endif // NUOVOARTICOLO_DETTAGLI_H
