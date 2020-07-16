#include "comandagui.h"

ComandaGUI::ComandaGUI(QWidget *parent) : QWidget(parent){
    layoutComanda = new QVBoxLayout(this);
    QPushButton* wrapperComanda = new QPushButton(this);
    wrapperComanda->setObjectName("wrapperComanda");
    QVBoxLayout* layoutWrapper = new QVBoxLayout(wrapperComanda);
    QHBoxLayout* layoutButtons = new QHBoxLayout();
    QLabel* orario = new QLabel("Orario", wrapperComanda);
    orario->setObjectName("Orario");
    QLabel* comandaId = new QLabel("Comanda #1", wrapperComanda);
    comandaId->setObjectName("ComandaId");
    QPushButton* rimuovi = new QPushButton("Rimuovi", wrapperComanda);
    rimuovi->setObjectName("Rimuovi");
    QPushButton* completata = new QPushButton("Completata", wrapperComanda);
    completata->setObjectName("Completata");
    layoutButtons->addWidget(rimuovi);
    layoutButtons->addWidget(completata);

    layoutWrapper->addWidget(orario);
    layoutWrapper->addWidget(comandaId);
    layoutWrapper->addLayout(layoutButtons);
    wrapperComanda->setLayout(layoutWrapper);

    layoutComanda->addWidget(wrapperComanda);
    setLayout(layoutComanda);

    rimuovi->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    completata->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    wrapperComanda->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
