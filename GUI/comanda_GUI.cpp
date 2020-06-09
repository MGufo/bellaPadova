#include "comanda_GUI.h"

Comanda_GUI::Comanda_GUI(QWidget *parent) : QWidget(parent){

  // Informazioni sul cliente
  QFormLayout* comandaInfo = new QFormLayout();
  comandaInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
  QLineEdit* orario = new QLineEdit(this);
  QLineEdit* nome = new QLineEdit(this);
  QLineEdit* indirizzo = new QLineEdit(this);
  QLineEdit* telefono = new QLineEdit(this);
  QLineEdit* costoTotale = new QLineEdit(this);
  comandaInfo->addRow(tr("Orario:"), orario);
  comandaInfo->addRow(tr("Nome:"), nome);
  comandaInfo->addRow(tr("Indirizzo:"), indirizzo);
  comandaInfo->addRow(tr("Telefono:"), telefono);
  comandaInfo->addRow(tr("Totale:"), costoTotale);

  // Contenuto ordine
  QStringList* headerOrdine = new QStringList();
  headerOrdine->push_back("Articolo");
  headerOrdine->push_back("Quantità");
  headerOrdine->push_back("Costo");
  QTableWidget* comandaContenuto = new QTableWidget(1, 3, this);
  comandaContenuto->setHorizontalHeaderLabels(*headerOrdine);
  comandaContenuto->setHorizontalHeader(new QHeaderView((Qt::Horizontal), comandaContenuto));

  // Crezione layout widget comanda e aggiunta subwidget
  layoutComanda = new QGridLayout(this);
  layoutComanda->addLayout(comandaInfo, 0, 0, 5, 5,Qt::AlignCenter);
  layoutComanda->addWidget(comandaContenuto, 6, 0, 5, 5, Qt::AlignCenter);

  setLayout(layoutComanda);
}
