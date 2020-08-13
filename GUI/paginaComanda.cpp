#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget *parent) : QWidget(parent) {
  // Creazione wrapper contenuto e relativi subwidget
  wrapperContenuto = new QWidget(this);
  inizializzaPizze(wrapperContenuto);
  inizializzaBevande(wrapperContenuto);
  inizializzaWrapperInfoComanda(wrapperContenuto);
  // Creazione layout wrapper contenuto e aggiunta dei subwidget
  layoutContenuto = new QGridLayout(wrapperContenuto);
  layoutContenuto->addWidget(wrapperInfoComanda, 0, 0, 5, 5, Qt::AlignLeft);
  layoutContenuto->addWidget(Pizze, 0, 6, 5, 5);
  layoutContenuto->addWidget(Bevande, 6, 6, 5, 5);
  wrapperContenuto->setLayout(layoutContenuto);
  // Creazione wrapper pulsanti e relativi pulsanti
  wrapperPulsanti = new QWidget(this);
  newArticolo = new QPushButton(wrapperPulsanti);
  modificaDati = new QPushButton(wrapperPulsanti);
  // Creazione layout wrapper pulsanti e aggiunta dei subwidget
  layoutPulsanti = new QHBoxLayout(wrapperPulsanti);
  layoutPulsanti->addWidget(newArticolo);
  layoutPulsanti->addWidget(modificaDati);
  wrapperPulsanti->setLayout(layoutPulsanti);
  // Creazione layout principale e aggiunta dei due wrapper
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

void PaginaComanda::inizializzaWrapperInfoComanda(QWidget* _parent){
  wrapperInfoComanda = new QWidget(_parent);
  QLineEdit* orario = new QLineEdit(wrapperInfoComanda);
  QLineEdit* nome = new QLineEdit(wrapperInfoComanda);
  QLineEdit* indirizzo = new QLineEdit(wrapperInfoComanda);
  QLineEdit* telefono = new QLineEdit(wrapperInfoComanda);
  QFormLayout* info = new QFormLayout(wrapperInfoComanda);
  info->addRow("Orario: ", orario);
  info->addRow("Nome: ", nome);
  info->addRow("Indirizzo: ", indirizzo);
  info->addRow("Telefono: ", telefono);
  QLabel* totale = new QLabel(wrapperInfoComanda);
  info->addRow("Totale: ", totale);
  wrapperInfoComanda->setLayout(info);
}
