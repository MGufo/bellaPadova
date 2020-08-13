#include "nuovaComanda_dettagli.h"

NuovaComanda_dettagli::NuovaComanda_dettagli(QWidget* parent) : QWizardPage(parent), previouslyInizialized(false){
    QWidget* wrapper = new QWidget(this);
    QHBoxLayout* layoutWrapper = new QHBoxLayout(wrapper);

    QWidget* infoWrapper = new QWidget(wrapper);
    QFormLayout* infoWrapperLayout = new QFormLayout(infoWrapper);

    orario = new QTimeEdit(QTime::currentTime(),infoWrapper);
    nome = new QLineEdit(infoWrapper);
    indirizzo = new QLineEdit(infoWrapper);
    telefono = new QLineEdit(infoWrapper);

    infoWrapperLayout->addRow("Orario:",orario);
    infoWrapperLayout->addRow("Nome:",nome);
    infoWrapperLayout->addRow("Indirizzo:",indirizzo);
    infoWrapperLayout->addRow("Telefono:",telefono);

    QStringList* labels = new QStringList();
    labels->push_back("");
    labels->push_back("Nome");
    labels->push_back("Quantità");

    pizze = new QTableWidget(0,3,wrapper);
    //pizze->setMinimumWidth(850);
    //pizze->setMaximumWidth(2100);
    //pizze->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(pizze->sizePolicy().hasHeightForWidth());
    pizze->setSizePolicy(sizePolicy);
    QHeaderView* headerPizze = new QHeaderView(Qt::Horizontal,pizze);
    headerPizze->setSectionResizeMode(headerPizze->ResizeToContents);
    pizze->setHorizontalHeaderLabels(*labels);
    pizze->setHorizontalHeader(headerPizze);
    pizze->verticalHeader()->setVisible(false);

    bevande = new QTableWidget(0,3,wrapper);
    //bevande->setMinimumWidth(850);
    //bevande->setMaximumWidth(2100);
    //bevande->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(pizze->sizePolicy().hasHeightForWidth());
    bevande->setSizePolicy(sizePolicy2);
    QHeaderView* headerBevande = new QHeaderView(Qt::Horizontal,bevande);
    headerBevande->setSectionResizeMode(headerBevande->ResizeToContents);
    bevande->setHorizontalHeaderLabels(*labels);
    bevande->setHorizontalHeader(headerPizze);
    bevande->verticalHeader()->setVisible(false);

    layoutWrapper->addWidget(infoWrapper);
    layoutWrapper->addWidget(pizze);
    layoutWrapper->addWidget(bevande);

    setLayout(layoutWrapper);
}

int NuovaComanda_dettagli::nextId() const{
    return WizardNuovaComanda::PAGE_End;
}

void NuovaComanda_dettagli::initializePage(){
    QWizardPage::initializePage();
    if(!previouslyInizialized){
        //registerField
        registerField("orario*", orario);
        registerField("nome*", nome);
        registerField("indirizzo*", indirizzo);
        registerField("telefono*", telefono);
    }
    previouslyInizialized = true;
}
