#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget *parent) : QWidget(parent) {
    wrapperContenuto = new QWidget(this);
    layoutContenuto = new QHBoxLayout(wrapperContenuto);
    inizializzaPizze(wrapperContenuto);
    inizializzaBevande(wrapperContenuto);
    inizializzaWrapperInfo(wrapperContenuto);
    layoutContenuto->addWidget(wrapperInfo);
    layoutContenuto->addWidget(Pizze);
    layoutContenuto->addWidget(Bevande);
    wrapperContenuto->setLayout(layoutContenuto);
    wrapperPulsanti = new QWidget(this);
    newArticolo = new QPushButton(wrapperPulsanti);
    modificaDati = new QPushButton(wrapperPulsanti);
    layoutPulsanti = new QHBoxLayout(wrapperPulsanti);
    layoutPulsanti->addWidget(newArticolo);
    layoutPulsanti->addWidget(modificaDati);
    wrapperPulsanti->setLayout(layoutPulsanti);
    layoutPaginaComande = new QVBoxLayout(this);
    layoutPaginaComande->addWidget(wrapperContenuto);
    layoutPaginaComande->addWidget(wrapperPulsanti);
    setLayout(layoutPaginaComande);
}

PaginaComanda::~PaginaComanda() {}

void PaginaComanda::inizializzaPizze(QWidget* _parent){
    QStringList* headerLabels = new QStringList();
    headerLabels->push_back("Nome");
    headerLabels->push_back("Quantità");

    Pizze = new TabellaComposita(_parent, "Pizze", headerLabels);
    Pizze->setObjectName("tabPizzeComanda");
}

void PaginaComanda::inizializzaBevande(QWidget* _parent){
    QStringList* headerLabels = new QStringList();
    headerLabels->push_back("Nome");
    headerLabels->push_back("Quantità");

    Bevande = new TabellaComposita(_parent, "Bevande", headerLabels);
    Bevande->setObjectName("tabBevandeComanda");
}

void PaginaComanda::inizializzaWrapperInfo(QWidget* _parent){
    wrapperInfo = new QWidget(_parent);
    QLineEdit* orario = new QLineEdit(wrapperInfo);
    QLineEdit* nome = new QLineEdit(wrapperInfo);
    QLineEdit* indirizzo = new QLineEdit(wrapperInfo);
    QLineEdit* telefono = new QLineEdit(wrapperInfo);
    QFormLayout* info = new QFormLayout(wrapperInfo);
    info->addRow("Orario: ", orario);
    info->addRow("Nome: ", nome);
    info->addRow("Indirizzo: ", indirizzo);
    info->addRow("Telefono: ", telefono);
    QLabel* totale = new QLabel(wrapperInfo);
    info->addRow("Totale: ", totale);
    wrapperInfo->setLayout(info);
}
