#include "nuovoArticolo_bevanda.h"

NuovoArticolo_bevanda::NuovoArticolo_bevanda(QWidget* parent) : QWidget(parent){

    // Informazioni Bevanda
    QWidget* infoWrapper = new QWidget(this);
    QFormLayout* layoutInfo = new QFormLayout(infoWrapper);
    layoutInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    nomeBevanda = new QLineEdit(infoWrapper);
    prezzoBevanda = new QLineEdit(infoWrapper);
    capacitaBevanda = new QLineEdit(infoWrapper);
    layoutInfo->addRow("Nome", nomeBevanda);
    layoutInfo->addRow("Prezzo", prezzoBevanda);
    layoutInfo->addRow("Capacità", capacitaBevanda);

    // Tipologia bevanda
    QWidget* tipologiaWrapper = new QWidget(this);
    radioBottiglia = new QRadioButton("Bottiglia", tipologiaWrapper);
    radioBottiglia->setChecked(true);
    QRadioButton* radioLattina = new QRadioButton("Lattina", tipologiaWrapper);
    QHBoxLayout* layoutTipologia = new  QHBoxLayout(tipologiaWrapper);
    layoutTipologia->addWidget(radioBottiglia);
    layoutTipologia->addWidget(radioLattina);

    layoutBevanda = new QVBoxLayout(this);
    layoutBevanda->addWidget(infoWrapper);
    layoutBevanda->addWidget(tipologiaWrapper);
    setLayout(layoutBevanda);
}

QLineEdit *NuovoArticolo_bevanda::getNomeBevanda() const{   return nomeBevanda;}

QLineEdit *NuovoArticolo_bevanda::getPrezzoBevanda() const{ return prezzoBevanda;}

QLineEdit *NuovoArticolo_bevanda::getCapacitaBevanda() const{   return capacitaBevanda;}

QRadioButton *NuovoArticolo_bevanda::getRadioBottiglia() const{ return radioBottiglia;}
