#include "nuovoArticolo_bevanda.h"

NuovoArticolo_bevanda::NuovoArticolo_bevanda(QWidget* parent) : QWidget(parent){

    // elenco di bevande tra cui scegliere da inserire nel menù
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("background-color: #eeeeee");
    bevandeRadioButtonWrapper = new QWidget(scrollArea);
    bevandeRadioButtonWrapper->setObjectName("bevandeRadioButtonWrapper");
    QVBoxLayout* bevandeRadioButtonLayout = new QVBoxLayout(bevandeRadioButtonWrapper);
    bevandeRadioButtonWrapper->setLayout(bevandeRadioButtonLayout);
    scrollArea->setWidget(bevandeRadioButtonWrapper);

    layoutBevanda = new QVBoxLayout(this);
    layoutBevanda->addWidget(scrollArea);
    setLayout(layoutBevanda);
}

QWidget *NuovoArticolo_bevanda::getBevandeRadioButtonWrapper() const{
    return bevandeRadioButtonWrapper;
}
