#include "nuovaComanda_end.h"

NuovaComanda_end::NuovaComanda_end(QWidget* parent) : QWizardPage(parent){
    setTitle("Riepilogo");
    setSubTitle("Controlla di aver inserito i dati correttamente e premi \"Finish\" per concludere l'operazione");
    layoutPagina = new QVBoxLayout(this);

    connect(this,SIGNAL(riempiWizardConElementiCheckati()),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiCheckatiInWizardComanda()));
    setLayout(layoutPagina);
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
    ptr1 = findChild<QWidget*>("bevandeVisualizationWrapper_comande");
    if(ptr1) layoutEnd->removeRow(ptr1);

    //creazione dei nuovi campi
    QScrollArea* scrollArea = new QScrollArea(this);
    layoutPagina->addWidget(scrollArea);
    QWidget* wrapper = new QWidget(scrollArea);
    wrapper->setObjectName("wrapperScrollComanda");
    layoutEnd = new QFormLayout(wrapper);
    wrapper->setLayout(layoutEnd);
    wrapper->setMinimumSize(1000,400);

    QLabel* orarioComanda = new QLabel(field("orario").toTime().toString("hh:mm:ss"), this);
    orarioComanda->setObjectName("orarioComanda");
    layoutEnd->addRow("Orario:", orarioComanda);

    QLabel* nomeComanda = new QLabel(field("nome").toString(), wrapper);
    nomeComanda->setObjectName("nomeComanda");
    layoutEnd->addRow("Nome:", nomeComanda);

    QLabel* indirizzoComanda = new QLabel(field("indirizzo").toString(), wrapper);
    indirizzoComanda->setObjectName("indirizzoComanda");
    layoutEnd->addRow("Indirizzo:", indirizzoComanda);

    QLabel* telefonoComanda = new QLabel(field("telefono").toString(), wrapper);
    telefonoComanda->setObjectName("telefonoComanda");
    layoutEnd->addRow("Telefono:", telefonoComanda);

    QWidget* wrapperPizze = new QWidget(wrapper);
    wrapperPizze->setObjectName("pizzeVisualizationWrapper");
    QVBoxLayout* pizzeLayout = new QVBoxLayout(wrapperPizze);
    wrapperPizze->setLayout(pizzeLayout);
    layoutEnd->addRow("Pizze:", wrapperPizze);

    QWidget* wrapperBevande = new QWidget(wrapper);
    wrapperBevande->setObjectName("bevandeVisualizationWrapper_comande");
    QVBoxLayout* bevandeLayout = new QVBoxLayout(wrapperBevande);
    wrapperBevande->setLayout(bevandeLayout);
    layoutEnd->addRow("Bevande:", wrapperBevande);

    scrollArea->setWidget(wrapper);

    emit riempiWizardConElementiCheckati();
}

void NuovaComanda_end::initializePage(){
    QWizardPage::initializePage();
    setActualPage();
}
