#include "dettaglioComanda.h"

dettaglioComanda::dettaglioComanda(QWidget *parent) : QWidget(parent){
  // Wrapper
  layoutComanda = new QVBoxLayout(this);
  QWidget* wrapperComanda = new QWidget(this);
  QGridLayout* layoutWrapper = new QGridLayout(wrapperComanda);
  // Informazioni sul cliente
  QFormLayout* comandaInfo = new QFormLayout();
  comandaInfo->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
  QLineEdit* orario = new QLineEdit(wrapperComanda);
  QLineEdit* nome = new QLineEdit(wrapperComanda);
  QLineEdit* indirizzo = new QLineEdit(wrapperComanda);
  QLineEdit* telefono = new QLineEdit(wrapperComanda);
  QLineEdit* costoTotale = new QLineEdit(wrapperComanda);
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
  QTableWidget* comandaContenuto = new QTableWidget(1, 3, wrapperComanda);
  comandaContenuto->setHorizontalHeaderLabels(*headerOrdine);
  comandaContenuto->setHorizontalHeader(new QHeaderView((Qt::Horizontal), comandaContenuto));

  // Crezione layout widget comanda e aggiunta subwidget
  layoutWrapper->addLayout(comandaInfo, 0, 0, 5, 5,Qt::AlignCenter);
  layoutWrapper->addWidget(comandaContenuto, 6, 0, 5, 5, Qt::AlignCenter);
  wrapperComanda->setLayout(layoutWrapper);
  layoutComanda->addWidget(wrapperComanda);
  setLayout(layoutComanda);
}
