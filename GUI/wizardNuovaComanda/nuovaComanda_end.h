#ifndef NUOVACOMANDA_END_H
#define NUOVACOMANDA_END_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QScrollArea>

#include <GUI/wizardNuovaComanda/wizard_nuovaComanda.h>

class NuovaComanda_end : public QWizardPage{
    Q_OBJECT
public:
    NuovaComanda_end(QWidget* parent = nullptr);
private:
    QVBoxLayout* layoutPagina;
    QFormLayout* layoutEnd;
    void setActualPage();
    void initializePage() override;
signals:
    void riempiWizardConElementiCheckati();
};

#endif // NUOVACOMANDA_END_H
