#include "nuovaComanda_end.h"

NuovaComanda_end::NuovaComanda_end(QWidget* parent) : QWizardPage(parent){
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutEnd = new QFormLayout(this);
    connect(this,SIGNAL(riempiWizardConElementiCheckati()),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiCheckatiInWizardComanda()));
    setLayout(layoutEnd);
}

void NuovaComanda_end::setActualPage(){
    //eliminazione dei campi precedenti se esistono
    QLabel* ptr = nullptr;
    ptr = findChild<QLabel*>("orarioComanda");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("nomeComanda");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("indirizzoComanda");
    if(ptr) layoutEnd->removeRow(ptr);
    ptr = findChild<QLabel*>("telefonoComanda");
    if(ptr) layoutEnd->removeRow(ptr);
    QWidget* ptr1 = findChild<QWidget*>("pizzeVisualizationWrapper");
    if(ptr1) layoutEnd->removeRow(ptr1);
    ptr1 = findChild<QWidget*>("bevandeVisualizationWrapper");
    if(ptr1) layoutEnd->removeRow(ptr1);

    //creazione dei nuovi campi
    QLabel* orarioComanda = new QLabel(field("orario").toTime().toString("hh:mm:ss"), this);
    orarioComanda->setObjectName("orarioComanda");
    layoutEnd->addRow("Orario:", orarioComanda);

    QLabel* nomeComanda = new QLabel(field("nome").toString(), this);
    nomeComanda->setObjectName("nomeComanda");
    layoutEnd->addRow("Nome:", nomeComanda);

    QLabel* indirizzoComanda = new QLabel(field("indirizzo").toString(), this);
    indirizzoComanda->setObjectName("indirizzoComanda");
    layoutEnd->addRow("Indirizzo:", indirizzoComanda);

    QLabel* telefonoComanda = new QLabel(field("telefono").toString(), this);
    telefonoComanda->setObjectName("telefonoComanda");
    layoutEnd->addRow("Telefono:", telefonoComanda);

    QWidget* wrapperPizze = new QWidget(this);
    wrapperPizze->setObjectName("pizzeVisualizationWrapper");
    QVBoxLayout* pizzeLayout = new QVBoxLayout(wrapperPizze);
    wrapperPizze->setLayout(pizzeLayout);
    layoutEnd->addRow("Pizze:", wrapperPizze);

    QWidget* wrapperBevande = new QWidget(this);
    wrapperBevande->setObjectName("bevandeVisualizationWrapper_comande");
    QVBoxLayout* bevandeLayout = new QVBoxLayout(wrapperBevande);
    wrapperBevande->setLayout(bevandeLayout);
    layoutEnd->addRow("Bevande:", wrapperBevande);

    emit riempiWizardConElementiCheckati();
}

void NuovaComanda_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}
