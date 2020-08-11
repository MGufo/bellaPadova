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

  connect(tabella,SIGNAL(cellChanged(int,int)),
          this,SLOT(emitDataOnCellChanged(int,int)));
  connect(this,SIGNAL(validationError(const QString)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(mostraErrore(const QString)));
  //todo: aggiungere un bool a sendPacketToModel() per indicare il tipo di pacchetto (consumabile/articolo).
  // aggiungere un "ricevitore universale" al posto di modificaConsumabile() che ricea un pacchetto e in base al valore del bool lo inoltri alla funzione corretta del controller
  connect(this,SIGNAL(sendPacketToModel(pacchetto*, bool)),parentWidget()->parentWidget()->parentWidget(),SLOT(modificaRisorsa(pacchetto*, bool)));
  connect(this,SIGNAL(sendIdToModel(uint)),parentWidget()->parentWidget()->parentWidget(),SLOT(eliminaConsumabile(uint)));
  connect(this,SIGNAL(sendIdToModel(uint)),this,SLOT(eliminaElemento(uint)));

  // Applicazione stile widget
  setStyleTabella();
  // Impostazione del layout
  setLayout(layoutTabellaComposita);
}

void TabellaComposita::pulisciTabella(){
    bool statoPrecedenteEditabile = editabile;
    editabile = false;
    tabella->clearContents();
    tabella->setRowCount(0);
    editabile = statoPrecedenteEditabile;
}

void TabellaComposita::inserisciElemento(pacchetto* p){
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
    item->setData(Qt::UserRole, _int);
    tabella->setItem(tabella->rowCount()-1, 0, item);
    item = new QTableWidgetItem(QString::fromStdString(pB->nome));
    item->setData(Qt::UserRole, _string);
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
    item->setData(Qt::UserRole, _double);
    tabella->setItem(tabella->rowCount()-1, 3, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->costo)));
    item->setData(Qt::UserRole, _double);
    tabella->setItem(tabella->rowCount()-1, 4, item);
    item = new QTableWidgetItem(pB->dataAcquisto.toString("dd/MM/yyyy"));
    item->setData(Qt::UserRole, _data);
    tabella->setItem(tabella->rowCount()-1, 5, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->capacita)));
    item->setData(Qt::UserRole, _double);
    tabella->setItem(tabella->rowCount()-1, 6, item);
    item = new QTableWidgetItem(QString::fromStdString(
                                  to_string_with_precision(pB->prezzo)));
    item->setData(Qt::UserRole, _double);
    tabella->setItem(tabella->rowCount()-1, 7, item);
    item = new QTableWidgetItem((pB->tipo ? "Lattina" : "Bottiglia"));
    item->setData(Qt::UserRole, _string);
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
      item->setData(Qt::UserRole, _int);
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pF->nome));
      item->setData(Qt::UserRole, _string);
      tabella->setItem(tabella->rowCount()-1, 1, item);

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pF->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pF->quantita)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pF->costo)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pF->dataAcquisto.toString("dd/MM/yyyy"));
      item->setData(Qt::UserRole, _data);
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
      item->setData(Qt::UserRole, _int);
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pI->nome));
      item->setData(Qt::UserRole, _string);
      tabella->setItem(tabella->rowCount()-1, 1, item);

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pI->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    std::to_string(pI->quantita)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pI->costo)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem(pI->dataAcquisto.toString("dd/MM/yyyy"));
      item->setData(Qt::UserRole, _data);
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
      item->setData(Qt::UserRole, _int);
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pP->nome));
      item->setData(Qt::UserRole, _string);
      tabella->setItem(tabella->rowCount()-1, 1, item);

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pP->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pP->prezzo)));
      item->setData(Qt::UserRole, _double);
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
      item->setData(1001,pIngr.size());
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
      item->setData(Qt::UserRole, _int);
      tabella->setItem(tabella->rowCount()-1, 0, item);
      item = new QTableWidgetItem(QString::fromStdString(pB->nome));
      item->setData(Qt::UserRole, _string);
      tabella->setItem(tabella->rowCount()-1, 1, item);

      QCheckBox* toggle = new QCheckBox(tabella);
      toggle->setProperty("row",tabella->rowCount()-1);
      toggle->setProperty("column",2);
      connect(toggle, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
      toggle->setChecked(pB->disponibilita);
      tabella->setCellWidget(tabella->rowCount()-1, 2, toggle);
      item = new QTableWidgetItem(QString::fromStdString(
                                    to_string_with_precision(pB->prezzo)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 3, item);
      item = new QTableWidgetItem(QString::fromStdString(to_string_with_precision(pB->capacita)));
      item->setData(Qt::UserRole, _double);
      tabella->setItem(tabella->rowCount()-1, 4, item);
      item = new QTableWidgetItem((pB->tipo? "Lattina" : "Bottiglia"));
      item->setData(Qt::UserRole, _string);
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

void TabellaComposita::rendiEditabile(bool b){
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
        else if((objectName() == "tabBevandeMenu") && (j == 2)){
            dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(true);
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
        connect(elimina,SIGNAL(sendId(uint)),this,SIGNAL(sendIdToModel(uint)));
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
          else if((objectName() == "tabBevandeMenu") && (j == 2)){
              dynamic_cast<QCheckBox*>(tabella->cellWidget(i,j))->setEnabled(false);
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
  bool type = false;
  if(editabile){
    try{
      validateInput(x, y);
    }
    catch (std::exception* e){
      emit validationError(QString::fromStdString(e->what()));
      setDefaultValue(x, y); // valore default
      return;
    }
    pacchetto* p = nullptr;
    if(objectName()=="tabBevandeInventario"){
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
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
      type = true;
    }
    else if(objectName()=="tabIngredientiInventario"){
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
        int d = std::stoi(da.substr(0,1));
        int m = std::stoi(da.substr(3,4));
        int y = std::stoi(da.substr(6,9));
        QDate _da(y,m,d);
        bool _l = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,6))->isChecked() ? true : false);

        p = new pacchettoIngrediente(_ID,_n,_d,_q,_c,_da,_l);
        type = true;
      }
      else{
        uint _ID = tabella->item(x,0)->text().toInt();
        string _n = tabella->item(x,1)->text().toStdString();
        bool _d = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,2))->isChecked() ? true : false);
        uint _q = tabella->item(x,3)->text().toInt();
        double _c = tabella->item(x,4)->text().toDouble();
        //dataAcquisto
        //recupero giorno, mese e anno tra i separatori
        string da = tabella->item(x,5)->text().toStdString();
        int d = std::stoi(da.substr(0,1));
        int m = std::stoi(da.substr(3,4));
        int y = std::stoi(da.substr(6,9));
        QDate _da(y,m,d);
        bool _l = (dynamic_cast<QCheckBox*>(tabella->cellWidget(x,6))->isChecked() ? true : false);
        string _t = tabella->item(x,7)->text().toStdString();
        p = new pacchettoFarina(_ID,_n,_d,_q,_c,_da,_l,_t);
      }
    }
    else if(objectName() == "tabPizzeMenu"){
      uint _ID = 0;
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (tabella->item(x,2)->text() == "Si" ? true : false);
      double _p = tabella->item(x,3)->text().toDouble();
      p = new pacchettoPizza(_ID,_n,_d,_p);
      QTableWidgetItem* tmp = tabella->item(x,y);
      for(int i = 1; i<=tmp->data(1001).toInt(); ++i){
        (dynamic_cast<pacchettoPizza*>(p))->
            ingredienti[tmp->data(1001+i).toInt()]="";
      }
    }
    else if(objectName() == "tabBevandeMenu"){
      uint _ID = tabella->item(x,0)->text().toInt();
      string _n = tabella->item(x,1)->text().toStdString();
      bool _d = (tabella->item(x,2)->text() == "Si" ? true : false);
      double _p = tabella->item(x,3)->text().toDouble();
      float _cap = tabella->item(x,4)->text().toFloat();
      bool _t = (tabella->item(x,5)->text() == "Lattina" ? true : false);

      p = new pacchettoBevanda(_ID,_n,_d,_p,0,0,QDate(),_cap,_t);
    }
    emit sendPacketToModel(p, type);
  }
}
void TabellaComposita::eliminaElemento(uint id){
    editabile = false;
    for(int i=0 ; i<tabella->rowCount() ; i++){
        uint currentId = static_cast<uint>(std::stoi(tabella->item(i,0)->text().toStdString()));
        if(currentId == id) tabella->removeRow(i);
    }
    editabile = true;
}

void TabellaComposita::checkBoxToggled(bool){
    QObject *cb = sender();
    int row = cb->property("row").toInt();
    int column = cb->property("column").toInt();

    emit tabella->cellChanged(row,column);
}

void TabellaComposita::setStyleTabella(){
  layoutTabellaComposita->setSpacing(0);
  layoutTabellaComposita->setMargin(0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void TabellaComposita::validateInput(int row, int col){
  auto value = dynamic_cast<QTableWidgetItem*>(tabella->item(row, col));
  if(value){
    InputValidator* validator = new InputValidator();
    validator->validate(value->text(),value->data(Qt::UserRole));
  }
}

void TabellaComposita::setDefaultValue(int row, int col){
  editabile = false;
  tabella->item(row, col)->setText("");
  editabile = true;
}
