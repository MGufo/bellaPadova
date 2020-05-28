#include "comande.h"

Comande::Comande(QWidget *parent) : QWidget(parent)
{
    comandeLayout = new QVBoxLayout(this);
    QLabel* inEsecuzione = new QLabel("In Esecuzione:", this);
    QLabel* concluse = new QLabel("Concluse:", this);

    comandeLayout->addWidget(inEsecuzione);
    comandeLayout->addWidget(concluse);
    setStyleComande();
    setLayout(comandeLayout);
}

void Comande::setStyleComande(){
    comandeLayout->setSpacing(0);
    comandeLayout->setMargin(0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
