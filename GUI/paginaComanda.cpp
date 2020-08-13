#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget *parent) : QWidget(parent) {
  // Creazione subwidget infoComanda e tabelle
  inizializzaPizze(this);
  inizializzaBevande(this);
  inizializzaInfoComanda(this);
  // Creazione pulsanti
  inizializzaPulsanti(this);
  // Creazione layout paginaComanda e aggiunta dei subwidget
  layoutPaginaComanda = new QGridLayout(this);
  layoutPaginaComanda->addWidget(infoComanda, 1, 0, 5, 5, Qt::AlignLeft);
  layoutPaginaComanda->addWidget(Pizze, 0, 6, 5, 5);
  layoutPaginaComanda->addWidget(Bevande, 6, 6, 5, 5);
  layoutPaginaComanda->addWidget(newArticolo, 7, 0, 1, 5);
  layoutPaginaComanda->addWidget(modificaDati, 9, 0, 1, 5);
  setLayout(layoutPaginaComanda);
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

void PaginaComanda::inizializzaPulsanti(QWidget* _parent){
  newArticolo = new QPushButton(_parent);
  newArticolo->setText("Nuovo Articolo");
  modificaDati = new QPushButton(_parent);
  modificaDati->setText("Modifica");
}

void PaginaComanda::inizializzaInfoComanda(QWidget* _parent){
  infoComanda = new QWidget(_parent);
  QLineEdit* orario = new QLineEdit(infoComanda);
  QLineEdit* nome = new QLineEdit(infoComanda);
  QLineEdit* indirizzo = new QLineEdit(infoComanda);
  QLineEdit* telefono = new QLineEdit(infoComanda);
  QFormLayout* info = new QFormLayout(infoComanda);
  info->addRow("Orario: ", orario);
  info->addRow("Nome: ", nome);
  info->addRow("Indirizzo: ", indirizzo);
  info->addRow("Telefono: ", telefono);
  QLabel* totale = new QLabel(infoComanda);
  info->addRow("Totale: ", totale);
  infoComanda->setLayout(info);
}
