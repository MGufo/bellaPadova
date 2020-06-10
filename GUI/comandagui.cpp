#include "comandagui.h"

ComandaGUI::ComandaGUI(QWidget *parent) : QWidget(parent){
    layoutComanda = new QVBoxLayout(this);
    QPushButton* wrapperComanda = new QPushButton(this);
    QVBoxLayout* layoutWrapper = new QVBoxLayout(wrapperComanda);

    QHBoxLayout* layoutButtons = new QHBoxLayout();
    QLabel* orario = new QLabel("Orario", wrapperComanda);
    QLabel* comandaId = new QLabel("Comanda #1", wrapperComanda);
    QPushButton* rimuovi = new QPushButton("Rimuovi", wrapperComanda);
    QPushButton* completata = new QPushButton("Completata", wrapperComanda);
    layoutButtons->addWidget(rimuovi);
    layoutButtons->addWidget(completata);

    layoutWrapper->addWidget(orario);
    layoutWrapper->addWidget(comandaId);
    layoutWrapper->addLayout(layoutButtons);
    wrapperComanda->setLayout(layoutWrapper);

    layoutComanda->addWidget(wrapperComanda);
    setLayout(layoutComanda);
    wrapperComanda->setStyleSheet("background-color: darkgreen;");

    rimuovi->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    completata->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    wrapperComanda->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
