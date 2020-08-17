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
  layoutPaginaComanda->addWidget(newArticolo, 8, 0, 1, 5);
  layoutPaginaComanda->addWidget(modificaDati, 9, 0, 1, 5);
  setStylePaginaComanda();
  setLayout(layoutPaginaComanda);
  connect(this, SIGNAL(enableButton()), parentWidget(), SLOT(enableButton()));
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
  orario->setEnabled(false);
  QLineEdit* nome = new QLineEdit(infoComanda);
  nome->setEnabled(false);
  QLineEdit* indirizzo = new QLineEdit(infoComanda);
  indirizzo->setEnabled(false);
  QLineEdit* telefono = new QLineEdit(infoComanda);
  telefono->setEnabled(false);
  QFormLayout* info = new QFormLayout(infoComanda);
  info->addRow("Orario: ", orario);
  info->addRow("Nome: ", nome);
  info->addRow("Indirizzo: ", indirizzo);
  info->addRow("Telefono: ", telefono);
  QLabel* totale = new QLabel(infoComanda);
  info->addRow("Totale: ", totale);
  infoComanda->setLayout(info);
}

void PaginaComanda::setStylePaginaComanda(){
  setMinimumSize(1200, 600);
  setMaximumSize(1200, 600);
  setObjectName("paginaComanda");
  newArticolo->setObjectName("newArticolo");
  modificaDati->setObjectName("modificaDati");
}

void PaginaComanda::closeEvent(QCloseEvent* event){
  emit enableButton();
  event->accept();
}
