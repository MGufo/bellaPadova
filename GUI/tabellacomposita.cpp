#include "tabellacomposita.h"
#include <iostream>

TabellaComposita::TabellaComposita(QWidget *parent, const QString& etichetta, const QStringList* labels) : QWidget(parent), editabile(false){
  // Creazione label per la tabella
  QLabel* label = new QLabel(etichetta, this);
  label->setObjectName("labelsMenu");
  // Creazione tabella
  tabella = new QTableWidget(0, (labels != nullptr ? labels->count() : 0), this);
  tabella->setMinimumWidth(850);
  tabella->setMaximumWidth(2100);
  //tabella->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(tabella->sizePolicy().hasHeightForWidth());
  tabella->setSizePolicy(sizePolicy);
  // Crezione e riempimento header tabella
  header = new QHeaderView(Qt::Horizontal,tabella);
  header->setSectionResizeMode(header->ResizeToContents);
  // Aggiunta header alla tabella
  if(labels)  tabella->setHorizontalHeaderLabels(*labels);
  tabella->setHorizontalHeader(header);
  tabella->verticalHeader()->setVisible(false);
  // Crezione layout widget
  layoutTabellaComposita = new QVBoxLayout(this);
  // Aggiunta widget figli al layout
  layoutTabellaComposita->addWidget(label);
  layoutTabellaComposita->addWidget(tabella);
  //tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);

  connect(tabella,SIGNAL(cellChanged(int,int)),this,SLOT(emitDataOnCellChanged(int,int)));
  connect(this,SIGNAL(sendPacketToModel(pacchetto*)),parentWidget()->parentWidget()->parentWidget(),SLOT(modificaConsumabile(pacchetto*)));
  connect(this,SIGNAL(sendIdToModel(int)),parentWidget()->parentWidget()->parentWidget(),SLOT(eliminaConsumabile(int)));

  // Applicazione stile widget
  setStyleTabella();
  // Impostazione del layout
  setLayout(layoutTabellaComposita);
}

void TabellaComposita::inserisciElemento(pacchetto* p){
  //scorro righe e colonne della tabella e rendo ogni item non editabile
  //item->setFlags(item->flags() ^ Qt::ItemIsEditable);
  //setEditTriggers(QAbstractItemView::NoEditTriggers);

  if(objectName()=="tabBevandeInventario"){
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
    item = new QTableWidgetItem(QString::fromStdString(
                                  std::to_string(pB->quantita)));
    tabella->setItem(tabella->rowCount()-1, 3, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->costo)));
    tabella->setItem(tabella->rowCount()-1, 4, item);
    item = new QTableWidgetItem(pB->dataAcquisto.toString("dd/MM/yyyy"));
    tabella->setItem(tabella->rowCount()-1, 5, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->capacita)));
    tabella->setItem(tabella->rowCount()-1, 6, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->prezzo)));
    tabella->setItem(tabella->rowCount()-1, 7, item);
    item = new QTableWidgetItem((pB->tipo ? "Lattina" : "Bottiglia"));
    tabella->setItem(tabella->rowCount()-1, 8, item);

    int i = tabella->rowCount()-1;
    for(int j=0 ; j<9 ; j++){
      QTableWidgetItem* item = tabella->item(i,j);
      item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    }
  }
  else if(objectName()=="tabIngredientiInventario"){
    pacchettoFarina* pF = dynamic_cast<pacchettoFarina*>(p);
    if(pF){
      //creazione di una nuova riga e riempimento con i dati nel pacchetto
      tabella->insertRow(tabella->rowCount());
      QTableWidgetItem* item = nullptr;

      item = new QTableWidgetItem(QString::fromStdString(std::to_string(pF->ID)));
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pF->nome));
      tabella->setItem(tabella->rowCount()-1, 1, item);
      item = new QTableWidgetItem((pF->disponibilita? "Si" : "No"));
      tabella->setItem(tabella->rowCount()-1, 2, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pF->quantita)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pF->costo)));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pF->dataAcquisto.toString("dd/MM/yyyy"));
      tabella->setItem(tabella->rowCount()-1, 5, item);
      item = new QTableWidgetItem((pF->locale ? "Si" : "No"));
      tabella->setItem(tabella->rowCount()-1, 6, item);
      item = new QTableWidgetItem(QString::fromStdString(pF->tipologia));
      tabella->setItem(tabella->rowCount()-1, 7, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<8 ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
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
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pI->quantita)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pI->costo)));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pI->dataAcquisto.toString("dd/MM/yyyy"));
      tabella->setItem(tabella->rowCount()-1, 5, item);
      item = new QTableWidgetItem((pI->locale ? "Si" : "No"));
      tabella->setItem(tabella->rowCount()-1, 6, item);
      item = new QTableWidgetItem(QString(""));
      tabella->setItem(tabella->rowCount()-1, 7, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<8 ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
      }
    }
  }
  else if(objectName()=="tabPizzeMenu"){
    pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(p);
    if(pP){
      //creazione di una nuova riga e riempimento con i dati nel pacchetto
      tabella->insertRow(tabella->rowCount());
      QTableWidgetItem* item = nullptr;

      item = new QTableWidgetItem(QString::fromStdString(std::to_string(pP->ID)));
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pP->nome));
      tabella->setItem(tabella->rowCount()-1, 1, item);
      item = new QTableWidgetItem((pP->disponibilita? "Si" : "No"));
      tabella->setItem(tabella->rowCount()-1, 2, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pP->prezzo)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      std::stringstream ingr;
      auto pIngr = pP->ingredienti;
      auto it2 = pIngr.cbegin();
      for(auto it = pIngr.cbegin(); it != pIngr.cend(); ++it){
        ingr << (*it).second;
        it2 = it;
        if(++it2 != pIngr.cend()){
          ingr << ", ";
        }
      }
      item = new QTableWidgetItem(QString::fromStdString(ingr.str()));
      tabella->setItem(tabella->rowCount()-1, 4, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<5 ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
      }
    }
  }
  else if(objectName() == "tabBevandeMenu"){
    pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(p);
    if(pB){
      //creazione di una nuova riga e riempimento con i dati nel pacchetto
      tabella->insertRow(tabella->rowCount());
      QTableWidgetItem* item = nullptr;

      item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->ID)));
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pB->nome));
      tabella->setItem(tabella->rowCount()-1, 1, item);
      item = new QTableWidgetItem((pB->disponibilita? "Si" : "No"));
      tabella->setItem(tabella->rowCount()-1, 2, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pB->prezzo)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem((pB->capacita));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem((pB->tipo? "Lattina" : "Bottiglia"));
      tabella->setItem(tabella->rowCount()-1, 5, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<6 ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
      }
    }
  }
}

void TabellaComposita::rendiEditabile(bool b){
  if(b){
    //rendo editabile ogni riga
    //tabella->setEditTriggers(QAbstractItemView::AllEditTriggers);
    for(int i=0; i < tabella->rowCount(); i++){
      for(int j=1 ; j<tabella->columnCount() ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
        //se item appartiene all'ultima riga di un elemento nel tabIngredienti
        //e l'elemento non è una Farina lo salta
        if(j==7 && objectName()=="tabIngredientiInventario" && item->text()=="")
          continue;
        item->setFlags(item->flags() | Qt::ItemIsEditable);
      }
    }
    //aggiungo colonna con pulsanti per eliminare un elemento
    tabella->insertColumn(tabella->columnCount());
    for(int i=0; i < tabella->rowCount(); i++){
        QPushButton* elimina = new QPushButton(tabella);
        tabella->setCellWidget(i, tabella->columnCount()-1, elimina);
        int id = std::stoi(tabella->item(i,0)->text().toStdString());
        //mantengo questa info nel pushbutton in qualche modo
    }

    editabile = true;
  }
  else{
    editabile = false;
    //tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i=0; i < tabella->rowCount(); i++){
      for(int j=1 ; j<tabella->columnCount() ; j++){
        QTableWidgetItem* item = tabella->item(i,j);
        //se item appartiene all'ultima riga di un elemento nel tabIngredienti
        //e l'elemento non è una Farina lo salta
        if(j==7 && objectName()=="tabIngredientiInventario" && item->text()=="")
          continue;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
      }
    }
  }
}

void TabellaComposita::cambiaColoreBordoCella(bool b){
  if(b)
    tabella->setStyleSheet("gridline-color: red");
  else
    tabella->setStyleSheet("gridline-color: #E5E5E5");
}

void TabellaComposita::setHeaderDimension(tipoTabella t){
  if(t == tipoTabella::pizze)
    header->setSectionResizeMode((header->count())-1, QHeaderView::Stretch);
  else if(t == tipoTabella::bevandeM)
    header->setSectionResizeMode(header->Stretch);
  else if(t == tipoTabella::inventario){
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(7, QHeaderView::Stretch);
  }
  else if(t == tipoTabella::bevandeI)
    header->setSectionResizeMode(1, QHeaderView::Stretch);
}

void TabellaComposita::emitDataOnCellChanged(int x, int y){
  if(editabile){
    //TODO: inputcheck
    pacchetto* p = nullptr;
    if(QObject::sender()->objectName()=="tabBevandeInventario"){
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (tabella->item(x,2)->text() == "Si" ? true : false);
      uint _q = tabella->item(x,3)->text().toInt();
      double _c = tabella->item(x,4)->text().toDouble();
      //dataAcquisto
      //recupero giorno, mese e anno tra i separatori
      string da = tabella->item(x,5)->text().toStdString();
      int d = std::stoi(da.substr(0,1));
      int m = std::stoi(da.substr(3,4));
      int y = std::stoi(da.substr(6,9));
      QDate _da(y,m,d);
      float _cap = tabella->item(x,6)->text().toFloat();
      double _p = tabella->item(x,7)->text().toDouble();
      bool _t = (tabella->item(x,8)->text() == "Lattina" ? true : false);

      p = new pacchettoBevanda(_ID,_n,_d,_p,_q,_c,_da,_cap,_t);
    }
    else{
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (tabella->item(x,2)->text() == "Si" ? true : false);
      uint _q = tabella->item(x,3)->text().toInt();
      double _c = tabella->item(x,4)->text().toDouble();
      //dataAcquisto
      //recupero giorno, mese e anno tra i separatori
      string da = tabella->item(x,5)->text().toStdString();
      int d = std::stoi(da.substr(0,1));
      int m = std::stoi(da.substr(3,4));
      int y = std::stoi(da.substr(6,9));
      QDate _da(y,m,d);
      bool _l = (tabella->item(x,6)->text() == "Si" ? true : false);

      p = new pacchettoIngrediente(_ID,_n,_d,_q,_c,_da,_l);
    }
    emit sendPacketToModel(p);
  }
}

void TabellaComposita::emitIdOnButtonClicked(int){
    //pescare l'id dell'elemento da eliminare nella tabella
    //trovo un modo di mantenere l'info di un id dentro al pushbutton
    //emit sendIdToModel(id);
}

void TabellaComposita::setStyleTabella(){
  layoutTabellaComposita->setSpacing(0);
  layoutTabellaComposita->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
