#include "tabellacomposita.h"

TabellaComposita::TabellaComposita(QWidget *parent, const QString& etichetta) : QWidget(parent){
  // Creazione label per la tabella
  QLabel* label = new QLabel(etichetta, this);
  // Creazione tabella
  QTableWidget* tabella = new QTableWidget(0, 5, this);
  // Crezione e riempimento header tabella
  QHeaderView* header = new QHeaderView(Qt::Horizontal,tabella);
  QStringList* headerLabels = new QStringList();
  headerLabels->push_back(QString("Nome"));
  headerLabels->push_back(QString("Confezioni"));
  headerLabels->push_back(QString("Costo"));
  headerLabels->push_back(QString("Data Acquisto"));
  headerLabels->push_back(QString("Locale"));
  // Aggiunta header alla tabella
  tabella->setHorizontalHeaderLabels(*headerLabels);
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
