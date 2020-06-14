#include "tabellacomposita.h"

TabellaComposita::TabellaComposita(QWidget *parent, const QString& etichetta, const QStringList* labels) : QWidget(parent){
  // Creazione label per la tabella
  QLabel* label = new QLabel(etichetta, this);
  label->setObjectName("labelsMenu");
  // Creazione tabella
  QTableWidget* tabella = new QTableWidget(0, (labels != nullptr ? labels->count() : 0), this);
  // Crezione e riempimento header tabella
  QHeaderView* header = new QHeaderView(Qt::Horizontal,tabella);
//  QStringList* headerLabels = new QStringList();
//  headerLabels->push_back(QString("Nome"));
//  headerLabels->push_back(QString("Confezioni"));
//  headerLabels->push_back(QString("Costo"));
//  headerLabels->push_back(QString("Data Acquisto"));
//  headerLabels->push_back(QString("Locale"));
  // Aggiunta header alla tabella
  if(labels)    tabella->setHorizontalHeaderLabels(*labels);
  tabella->setHorizontalHeader(header);
  // Crezione layout widget
  layoutTabellaComposita = new QVBoxLayout(this);
  // Aggiunta widget figli al layout
  layoutTabellaComposita->addWidget(label);
  layoutTabellaComposita->addWidget(tabella);
  // Applicazione stile widget
  setStyleTabella();
  // Impostazione del layout
  setLayout(layoutTabellaComposita);
}

void TabellaComposita::setStyleTabella(){
  layoutTabellaComposita->setSpacing(0);
  layoutTabellaComposita->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
