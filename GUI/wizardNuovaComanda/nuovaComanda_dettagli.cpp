#include "nuovaComanda_dettagli.h"

NuovaComanda_dettagli::NuovaComanda_dettagli(QWidget* parent) : QWizardPage(parent), previouslyInizialized(false){
    setTitle("Aggiunta di una nuova Comanda");
    setSubTitle("Fornisci un  orario, nome, indirizzo e numero telefonico da inserire nella comanda e successivamente "
                "scegli gli articoli da inserirci con le rispettive quantità");
    QVBoxLayout* layoutNuovaComanda = new QVBoxLayout(this);
    wrapper = new QWidget(this);
    layoutWrapper = new QHBoxLayout(wrapper);

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

    setNewPizzeWidget();
    setNewBevandeWidget();

    layoutWrapper->addWidget(infoWrapper);

    connect(this,SIGNAL(riempiWizardConElementiComanda()),parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget(),SLOT(visualizzaElementiInWizardComanda()));

    layoutNuovaComanda->addWidget(wrapper);
    setLayout(layoutNuovaComanda);
}

int NuovaComanda_dettagli::nextId() const{
    return WizardNuovaComanda::PAGE_End;
}

void NuovaComanda_dettagli::initializePage(){
    QWizardPage::initializePage();
    if(!previouslyInizialized){
        //registerField
        registerField("orario", orario);
        registerField("nome*", nome);
        registerField("indirizzo*", indirizzo);
        registerField("telefono*", telefono);

        layoutWrapper->removeWidget(pizze);
        layoutWrapper->removeWidget(bevande);
        delete pizze;
        delete bevande;
        setNewPizzeWidget();
        setNewBevandeWidget();
    }

    previouslyInizialized = true;

    emit riempiWizardConElementiComanda();
}

void NuovaComanda_dettagli::setNewPizzeWidget(){
    QStringList* labelsPizze = new QStringList();
    labelsPizze->push_back("");
    labelsPizze->push_back("Nome");
    labelsPizze->push_back("Quantità");

    pizze = new QTableWidget(0,3,wrapper);
    pizze->setObjectName("pizzeWrapper");
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(pizze->sizePolicy().hasHeightForWidth());
    pizze->setSizePolicy(sizePolicy);
    QHeaderView* headerPizze = new QHeaderView(Qt::Horizontal,pizze);
    headerPizze->setSectionResizeMode(headerPizze->ResizeToContents);
    pizze->setHorizontalHeaderLabels(*labelsPizze);
    pizze->setHorizontalHeader(headerPizze);
    pizze->verticalHeader()->setVisible(false);

    layoutWrapper->addWidget(pizze);
}

void NuovaComanda_dettagli::setNewBevandeWidget(){
    QStringList* labelsBevande = new QStringList();
    labelsBevande->push_back("");
    labelsBevande->push_back("Nome");
    labelsBevande->push_back("Quantità");

    bevande = new QTableWidget(0,3,wrapper);
    bevande->setObjectName("bevandeWrapper_comande");
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
    bevande->setHorizontalHeaderLabels(*labelsBevande);
    bevande->setHorizontalHeader(headerBevande);
    bevande->verticalHeader()->setVisible(false);

     layoutWrapper->addWidget(bevande);
}
