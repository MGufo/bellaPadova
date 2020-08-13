#ifndef NUOVACOMANDA_DETTAGLI_H
#define NUOVACOMANDA_DETTAGLI_H

#include <QWidget>
#include <QWizardPage>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTimeEdit>
#include <QTableWidget>
#include <QHeaderView>

#include "GUI/wizardNuovaComanda/wizard_nuovaComanda.h"

class NuovaComanda_dettagli : public QWizardPage{
    Q_OBJECT
public:
    NuovaComanda_dettagli(QWidget* parent = nullptr);
    //int nextId() const override;
private:
    QTimeEdit* orario = nullptr;
    QLineEdit* nome = nullptr;
    QLineEdit* indirizzo = nullptr;
    QLineEdit* telefono = nullptr;
    QTableWidget* pizze = nullptr;
    QTableWidget* bevande = nullptr;
    bool previouslyInizialized;
    void initializePage() override;
};

#endif // NUOVACOMANDA_DETTAGLI_H
