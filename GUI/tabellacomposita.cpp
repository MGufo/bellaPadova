#include "tabellacomposita.h"

TabellaComposita::TabellaComposita(QWidget *parent, const QString& etichetta, const QStringList* labels) : QWidget(parent){
  // Creazione label per la tabella
  QLabel* label = new QLabel(etichetta, this);
  label->setObjectName("labelsMenu");
  // Creazione tabella
  tabella = new QTableWidget(0, (labels != nullptr ? labels->count() : 0), this);
  tabella->setMinimumWidth(1300);
  // Crezione e riempimento header tabella
  header = new QHeaderView(Qt::Horizontal,tabella);
  header->setSectionResizeMode(header->ResizeToContents);
  // Aggiunta header alla tabella
  if(labels)    tabella->setHorizontalHeaderLabels(*labels);
  tabella->setHorizontalHeader(header);
  // Crezione layout widget
  layoutTabellaComposita = new QVBoxLayout(this);
  // Aggiunta widget figli al layout
  layoutTabellaComposita->addWidget(label);
  layoutTabellaComposita->addWidget(tabella, 0, Qt::AlignCenter);
  // Applicazione stile widget
  setStyleTabella();
  // Impostazione del layout
  setLayout(layoutTabellaComposita);
}

void TabellaComposita::inserisciElemento(pacchetto * p){
    if(objectName()=="tabBevande"){
        std::cout << "dagh3" << std::endl;
        pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(p);
        //creazione di una nuova riga e riempimento con i dati nel pacchetto
        //guardo come inserire elementi in qtablewidget!
        tabella->setItem(tabella->rowCount(), 0, new QTableWidgetItem(QString::fromStdString(pB->nome)));
        tabella->setItem(tabella->rowCount(), 1, new QTableWidgetItem((pB->disponibilita? "Si" : "No")));
        tabella->setItem(tabella->rowCount(), 2, new QTableWidgetItem(QString::fromStdString(std::to_string(pB->quantita))));
        tabella->setItem(tabella->rowCount(), 3, new QTableWidgetItem(QString::fromStdString(std::to_string(pB->costo))));
        tabella->setItem(tabella->rowCount(), 4, new QTableWidgetItem(pB->dataAcquisto.toString()));
        tabella->setItem(tabella->rowCount(), 5, new QTableWidgetItem(QString::fromStdString(std::to_string(pB->capacita))));
        tabella->setItem(tabella->rowCount(), 6, new QTableWidgetItem(QString::fromStdString(std::to_string(pB->prezzo))));
        tabella->setItem(tabella->rowCount(), 7, new QTableWidgetItem((pB->tipo ? "Lattina" : "Bottiglia")));
    }
    else{

    }
}

void TabellaComposita::setStyleTabella(){
  layoutTabellaComposita->setSpacing(0);
  layoutTabellaComposita->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
