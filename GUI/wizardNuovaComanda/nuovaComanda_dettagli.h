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
    int nextId() const override;
private:
    QWidget* wrapper = nullptr;
    QHBoxLayout* layoutWrapper = nullptr;
    QTimeEdit* orario = nullptr;
    QLineEdit* nome = nullptr;
    QLineEdit* indirizzo = nullptr;
    QLineEdit* telefono = nullptr;
    QTableWidget* pizze = nullptr;
    QTableWidget* bevande = nullptr;
    bool previouslyInizialized;
    void initializePage() override;

    void setNewPizzeWidget();
    void setNewBevandeWidget();
signals:
    void riempiWizardConElementiComanda();
};

#endif // NUOVACOMANDA_DETTAGLI_H
