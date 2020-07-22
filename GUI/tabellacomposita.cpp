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

  //connect(tabella,SIGNAL(cellChanged(int,int)));
  connect(this,SIGNAL(sendPacketToModel(pacchetto*)),parentWidget()->parentWidget()->parentWidget(),SLOT(modificaConsumabile(pacchetto*)));

  // Applicazione stile widget
  setStyleTabella();
  // Impostazione del layout
  setLayout(layoutTabellaComposita);
}

void TabellaComposita::inserisciElemento(pacchetto * p){
    //scorro righe e colonne della tabella e rendo ogni item non editabile
    //item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    //setEditTriggers(QAbstractItemView::NoEditTriggers);

    if(objectName()=="tabBevande"){
        pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(p);
        //creazione di una nuova riga e riempimento con i dati nel pacchetto
        tabella->insertRow(tabella->rowCount());
        QTableWidgetItem* item = nullptr;

        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->ID)));
        tabella->setItem(tabella->rowCount()-1, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(pB->nome));
        tabella->setItem(tabella->rowCount()-1, 1, item);
        item = new QTableWidgetItem((pB->disponibilita? "Si" : "No"));
        tabella->setItem(tabella->rowCount()-1, 2, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->quantita)));
        tabella->setItem(tabella->rowCount()-1, 3, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->costo)));
        tabella->setItem(tabella->rowCount()-1, 4, item);
        item = new QTableWidgetItem(pB->dataAcquisto.toString("dd/MM/yyyy"));
        tabella->setItem(tabella->rowCount()-1, 5, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->capacita)));
        tabella->setItem(tabella->rowCount()-1, 6, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->prezzo)));
        tabella->setItem(tabella->rowCount()-1, 7, item);
        item = new QTableWidgetItem((pB->tipo ? "Lattina" : "Bottiglia"));
        tabella->setItem(tabella->rowCount()-1, 8, item);

        int i = tabella->rowCount()-1;
        for(int j=0 ; j<9 ; j++){
            QTableWidgetItem* item = tabella->itemAt(i,j);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        }
    }
    else{
        pacchettoIngrediente* pI = dynamic_cast<pacchettoIngrediente*>(p);
        //creazione di una nuova riga e riempimento con i dati nel pacchetto
        tabella->insertRow(tabella->rowCount());
        QTableWidgetItem* item = nullptr;

        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pI->ID)));
        tabella->setItem(tabella->rowCount()-1, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(pI->nome));
        tabella->setItem(tabella->rowCount()-1, 1, item);
        item = new QTableWidgetItem((pI->disponibilita? "Si" : "No"));
        tabella->setItem(tabella->rowCount()-1, 2, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pI->quantita)));
        tabella->setItem(tabella->rowCount()-1, 3, item);
        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pI->costo)));
        tabella->setItem(tabella->rowCount()-1, 4, item);
        item = new QTableWidgetItem(pI->dataAcquisto.toString("dd/MM/yyyy"));
        tabella->setItem(tabella->rowCount()-1, 5, item);
        item = new QTableWidgetItem((pI->locale ? "Si" : "No"));
        tabella->setItem(tabella->rowCount()-1, 6, item);

        int i = tabella->rowCount()-1;
        for(int j=0 ; j<7 ; j++){
            QTableWidgetItem* item = tabella->itemAt(i,j);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        }
    }
    tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TabellaComposita::emitDataOnCellChanged(int x, int y){
    //TODO: inputcheck
    pacchetto* p = nullptr;
    if(QObject::sender()->objectName()=="tabBevande"){
        uint _ID = tabella->itemAt(x,0)->text().toInt();
        string _n = tabella->itemAt(x,1)->text().toStdString();
        bool _d = (tabella->itemAt(x,2)->text() == "Si" ? true : false);
        uint _q = tabella->itemAt(x,3)->text().toInt();
        double _c = tabella->itemAt(x,4)->text().toDouble();
        //dataAcquisto
        //recupero giorno, mese e anno tra i separatori
        string da = tabella->itemAt(x,5)->text().toStdString();
        int d = std::stoi(da.substr(0,1));
        int m = std::stoi(da.substr(3,4));
        int y = std::stoi(da.substr(6,7));
        QDate _da(y,m,d);
        float _cap = tabella->itemAt(x,6)->text().toFloat();
        double _p = tabella->itemAt(x,7)->text().toDouble();
        bool _t = (tabella->itemAt(x,8)->text() == "Lattina" ? true : false);

        p = new pacchettoBevanda(_ID,_n,_d,_p,_q,_c,_da,_cap,_t);
    }
    else{
        uint _ID = tabella->itemAt(x,0)->text().toInt();
        string _n = tabella->itemAt(x,1)->text().toStdString();
        bool _d = (tabella->itemAt(x,2)->text() == "Si" ? true : false);
        uint _q = tabella->itemAt(x,3)->text().toInt();
        double _c = tabella->itemAt(x,4)->text().toDouble();
        //dataAcquisto
        //recupero giorno, mese e anno tra i separatori
        string da = tabella->itemAt(x,5)->text().toStdString();
        int d = std::stoi(da.substr(0,1));
        int m = std::stoi(da.substr(3,4));
        int y = std::stoi(da.substr(6,7));
        QDate _da(y,m,d);
        bool _l = (tabella->itemAt(x,6)->text() == "Si" ? true : false);

        p = new pacchettoIngrediente(_ID,_n,_d,_q,_c,_da,_l);
    }
    emit sendPacketToModel(p);
}

void TabellaComposita::setStyleTabella(){
  layoutTabellaComposita->setSpacing(0);
  layoutTabellaComposita->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
