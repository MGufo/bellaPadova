#include "tabellarisorse.h"

TabellaRisorse::TabellaRisorse(QWidget *parent, const QString& etichetta, const QStringList* labels) : TabellaComposita(parent, etichetta, labels){
  connect(tabella,SIGNAL(cellChanged(int,int)),
            this,SLOT(emitDataOnCellChanged(int,int)));
  connect(this,SIGNAL(sendArticoloPacketToModel(pacchettoArticolo*)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(modificaArticolo(pacchettoArticolo*)));
  connect(this,SIGNAL(sendConsumabilePacketToModel(pacchettoConsumabile*)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(modificaConsumabile(pacchettoConsumabile*)));
  connect(this,SIGNAL(sendConsumabilePacketToModel(pacchettoConsumabile*)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(aggiornaMenuSuModificaConsumabile(pacchettoConsumabile*)));
  connect(this,SIGNAL(sendArticoloIdToModel(uint)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(eliminaArticolo(uint)));
  connect(this,SIGNAL(sendConsumabileIdToModel(uint)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(eliminaConsumabile(uint)));
  connect(this,SIGNAL(sendArticoloIdToModel(uint)),
          this,SLOT(eliminaElemento(uint)));
  connect(this,SIGNAL(sendConsumabileIdToModel(uint)),
          this,SLOT(eliminaElemento(uint)));
}

void TabellaRisorse::inserisciElemento(pacchetto* p){
  //scorro righe e colonne della tabella e rendo ogni item non editabile
  //item->setFlags(item->flags() ^ Qt::ItemIsEditable);
  //setEditTriggers(QAbstractItemView::NoEditTriggers);
  bool statoPrecedenteEditabile = editabile;
  editabile = false;
  if(objectName()=="tabBevandeInventario"){
    pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(p);
    //creazione di una nuova riga e riempimento con i dati nel pacchetto
    tabella->insertRow(tabella->rowCount());
    QTableWidgetItem* item = nullptr;

    item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->ID)));
    tabella->setItem(tabella->rowCount()-1, 0, item);
    item = new QTableWidgetItem(QString::fromStdString(pB->nome));
    tabella->setItem(tabella->rowCount()-1, 1, item);

    QCheckBox* toggle = new QCheckBox(tabella);
    //assegno alla checkbox le proprietà di riga e colonna rispetto alla tabella
    //in cui è inserita (necessarie per emettere il segnale cellChanged)
    toggle->setProperty("row",tabella->rowCount()-1);
    toggle->setProperty("column",2);
    connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
    toggle->setChecked(pB->disponibilita);

    tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);

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
        if(j==2)
            dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
        else{
            QTableWidgetItem* item = tabella->item(i,j);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        }
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

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pF->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pF->quantita)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pF->costo)));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pF->dataAcquisto.toString("dd/MM/yyyy"));
      tabella->setItem(tabella->rowCount()-1, 5, item);

      toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",6);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pF->locale);
      tabella->setCellWidget(tabella->rowCount()-1, 6, toggle);
      item = new QTableWidgetItem(QString::fromStdString(pF->tipologia));
      //info aggiuntiva dell'item per capire se è una farina o un ingrediente
      item->setData(Qt::UserRole, QString("farina"));
      tabella->setItem(tabella->rowCount()-1, 7, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<8 ; j++){
          if(j==2 || j==6)
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          else{
              QTableWidgetItem* item = tabella->item(i,j);
              item->setFlags(item->flags() ^ Qt::ItemIsEditable);
          }
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

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pI->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pI->quantita)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pI->costo)));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pI->dataAcquisto.toString("dd/MM/yyyy"));
      tabella->setItem(tabella->rowCount()-1, 5, item);

      toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",6);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pI->locale);
      tabella->setCellWidget(tabella->rowCount()-1, 6, toggle);
      item = new QTableWidgetItem(QString(""));
      //info aggiuntiva dell'item per capire se è una farina o un ingrediente
      item->setData(Qt::UserRole, QString("ingrediente"));
      tabella->setItem(tabella->rowCount()-1, 7, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<8 ; j++){
          if(j==2 || j==6)
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          else{
              QTableWidgetItem* item = tabella->item(i,j);
              item->setFlags(item->flags() ^ Qt::ItemIsEditable);
          }
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

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pP->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pP->prezzo)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      //non è possibile modificare la lista di ingredienti
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
      int size = pIngr.size();
      item->setData(1001,size);
      uint var = 1;
      for(auto it = pIngr.cbegin(); it != pIngr.cend(); ++it){
        item->setData(1001+var,(*it).first);
        var++;
      }
      tabella->setItem(tabella->rowCount()-1, 4, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<5 ; j++){
          if(j==2)
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          else{
              QTableWidgetItem* item = tabella->item(i,j);
              item->setFlags(item->flags() ^ Qt::ItemIsEditable);
          }
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

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pB->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pB->prezzo)));
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(to_string_with_precision(pB->capacita)));
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem((pB->tipo? "Lattina" : "Bottiglia"));
      tabella->setItem(tabella->rowCount()-1, 5, item);

      int i = tabella->rowCount()-1;
      for(int j=0 ; j<6 ; j++){
          if(j==2)
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          else{
              QTableWidgetItem* item = tabella->item(i,j);
              item->setFlags(item->flags() ^ Qt::ItemIsEditable);
          }
      }
    }
  }
  editabile = statoPrecedenteEditabile;
}

void TabellaRisorse::sostituisciElemento(pacchetto* p){
    bool statoPrecedenteEditabile = editabile;
    editabile = false;

    for(int i=0 ; i<tabella->rowCount() ; i++){
        //controllo l'ID, presente nella prima colonna
        if(tabella->item(i,0)->text().toInt() == static_cast<int>(p->ID)){
            tabella->removeRow(i);
            inserisciElemento(p);
        }
    }
    editabile = statoPrecedenteEditabile;
}

void TabellaRisorse::rendiEditabile(bool b){
  if(b){
    //rendo editabile ogni riga tranne la colonna contenente gli ID
    for(int i=0; i < tabella->rowCount(); i++){
      for(int j=1 ; j<tabella->columnCount() ; j++){
        //casi in cui ci sono dei widget nelle celle
        if((objectName() == "tabBevandeInventario") && (j == 2)){
            dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(true);
        }
        else if((objectName() == "tabIngredientiInventario") && ((j == 2)||(j == 6))){
            dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(true);
        }
        else if((objectName() == "tabPizzeMenu") && (j == 2)){
            dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(true);
        }
        else if(objectName() == "tabBevandeMenu"){
            //diamo solo la possibilità di eliminare le bevande dal menu, la modifica delle caratteristiche della bevanda
            //avviene nell'inventario
            continue;
        }
        else{
            //casi in cui ci sono item nelle celle
            QTableWidgetItem* item = tabella->item(i,j);
            //se item appartiene all'ultima riga di un elemento nel tabIngredienti
            //e l'elemento non è una Farina lo salta
            if((j==7 && objectName()=="tabIngredientiInventario" && item->text()=="") || (j == 4 && objectName()=="tabPizzeMenu"))
              continue;
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
      }
    }
    //aggiungo colonna con pulsanti per eliminare un elemento
    tabella->insertColumn(tabella->columnCount());
    QTableWidgetItem* headerLabel = new QTableWidgetItem();
    headerLabel->setText("");
    tabella->setHorizontalHeaderItem(tabella->columnCount()-1,headerLabel);
    for(int i=0; i < tabella->rowCount(); i++){
        uint id = static_cast<uint>(std::stoi(tabella->item(i,0)->text().toStdString()));
        PushButtonWithId* elimina = new PushButtonWithId(id,tabella);
        connect(elimina,SIGNAL(sendId(uint)),this,SLOT(forwardIdToModel(uint)));
        elimina->setText("Elimina");
        tabella->setCellWidget(i, tabella->columnCount()-1, elimina);
    }

    editabile = true;
  }
  else{
    editabile = false;
    //rendo non editabile ogni riga
    for(int i=0; i < tabella->rowCount(); i++){
      for(int j=1 ; j<tabella->columnCount()-1 ; j++){
          //casi in cui ci sono dei widget nelle celle
          if((objectName() == "tabBevandeInventario") && (j == 2)){
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          }
          else if((objectName() == "tabIngredientiInventario") && ((j == 2)||(j == 6))){
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          }
          else if((objectName() == "tabPizzeMenu") && (j == 2)){
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
          }
          else if((objectName() == "tabBevandeMenu") /*&& (j == 2)*/){
              //dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
              continue;
          }
          else{
              //casi in cui ci sono item nelle celle
              QTableWidgetItem* item = tabella->item(i,j);
              //se item appartiene all'ultima riga di un elemento nel tabIngredienti
              //e l'elemento non è una Farina lo salta
              if((j==7 && objectName()=="tabIngredientiInventario" && item->text()=="") || (j == 4 && objectName()=="tabPizzeMenu"))
                continue;
              item->setFlags(item->flags() ^ Qt::ItemIsEditable);
          }
      }
    }
    //rimuovo colonna con pulsanti per eliminare un elemento
    tabella->removeColumn(tabella->columnCount()-1);
  }
}

void TabellaRisorse::emitDataOnCellChanged(int x, int){
  if(editabile){
    if(objectName()=="tabBevandeInventario"){
      pacchettoConsumabile* p = nullptr;
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
      uint _q = tabella->item(x,3)->text().toInt();
      double _c = tabella->item(x,4)->text().toDouble();
      //dataAcquisto
      //recupero giorno, mese e anno tra i separatori
      string da = tabella->item(x,5)->text().toStdString();
      int d = std::stoi(da.substr(0,2));
      int m = std::stoi(da.substr(3,5));
      int y = std::stoi(da.substr(6,9));
      QDate _da(y,m,d);
      float _cap = tabella->item(x,6)->text().toFloat();
      double _p = tabella->item(x,7)->text().toDouble();
      bool _t = (tabella->item(x,8)->text() == "Lattina" ? true : false);

      p = new pacchettoBevanda(_ID,_n,_d,_p,_q,_c,_da,_cap,_t);
      emit sendConsumabilePacketToModel(p);
    }
    else if(objectName()=="tabIngredientiInventario"){
      pacchettoConsumabile* p = nullptr;
      string tipologiaElemento =
          tabella->item(x,7)->data(Qt::UserRole).toString().toStdString();
      if(tipologiaElemento == "ingrediente"){
        uint _ID = tabella->item(x,0)->text().toInt();
        string _n = tabella->item(x,1)->text().toStdString();
        bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
        uint _q = tabella->item(x,3)->text().toInt();
        double _c = tabella->item(x,4)->text().toDouble();
        //dataAcquisto
        //recupero giorno, mese e anno tra i separatori
        string da = tabella->item(x,5)->text().toStdString();
        int d = std::stoi(da.substr(0,2));
        int m = std::stoi(da.substr(3,5));
        int y = std::stoi(da.substr(6,9));
        QDate _da(y,m,d);
        bool _l = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,6))->isChecked() ? true : false);

        p = new pacchettoIngrediente(_ID,_n,_d,_q,_c,_da,_l);
        emit sendConsumabilePacketToModel(p);
      }
      else{
        pacchettoConsumabile* p = nullptr;
        uint _ID = tabella->item(x,0)->text().toInt();
        string _n = tabella->item(x,1)->text().toStdString();
        bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
        uint _q = tabella->item(x,3)->text().toInt();
        double _c = tabella->item(x,4)->text().toDouble();
        //dataAcquisto
        //recupero giorno, mese e anno tra i separatori
        string da = tabella->item(x,5)->text().toStdString();
        int d = std::stoi(da.substr(0,2));
        int m = std::stoi(da.substr(3,5));
        int y = std::stoi(da.substr(6,9));
        QDate _da(y,m,d);
        bool _l = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,6))->isChecked() ? true : false);
        string _t = tabella->item(x,7)->text().toStdString();

        p = new pacchettoFarina(_ID,_n,_d,_q,_c,_da,_l,_t);
        emit sendConsumabilePacketToModel(p);
      }
    }
    else if(objectName() == "tabPizzeMenu"){
      pacchettoArticolo* p = nullptr;
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
      double _p = tabella->item(x,3)->text().toDouble();

      p = new pacchettoPizza(_ID,_n,_d,_p);
      QTableWidgetItem* tmp = tabella->item(x,4);
      for(int i = 1; i<=tmp->data(1001).toInt(); ++i){
        (dynamic_cast<pacchettoPizza*>(p))->
            ingredienti[tmp->data(1001+i).toInt()]="";
      }
      emit sendArticoloPacketToModel(p);
    }
    else if(objectName() == "tabBevandeMenu"){
      pacchettoArticolo* p = nullptr;
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (tabella->item(x,2)->text() == "Si" ? true : false);
      double _p = tabella->item(x,3)->text().toDouble();
      float _cap = tabella->item(x,4)->text().toFloat();
      bool _t = (tabella->item(x,5)->text() == "Lattina" ? true : false);

      p = new pacchettoBevanda(_ID,_n,_d,_p,0,0,QDate(),_cap,_t);
      emit sendArticoloPacketToModel(p);
    }
  }
}

void TabellaRisorse::forwardIdToModel(uint id){
    if((objectName()=="tabIngredientiInventario") || (objectName()=="tabBevandeInventario"))
        emit sendConsumabileIdToModel(id);
    else
        emit sendArticoloIdToModel(id);
}
