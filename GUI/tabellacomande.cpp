#include "tabellacomande.h"

TabellaComande::TabellaComande(QWidget *parent, const QString& etichetta,
                               const QStringList* labels) : TabellaComposita(parent, etichetta, labels){
  connect(this,SIGNAL(validationError(const QString)),
          parentWidget()->parentWidget()->parentWidget()->
          parentWidget()->parentWidget()->parentWidget()->
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(mostraErrore(const QString)));
  //  connect(this,SIGNAL(sendComandaPacketToModel(pacchettoComanda*)),
  //          parentWidget()->parentWidget()->parentWidget()->
  //          parentWidget()->parentWidget()->parentWidget()->
  //          parentWidget()->parentWidget()->parentWidget(),
  //          SLOT(modificaComanda(pacchetto*)));
  //  connect(this,SIGNAL(sendComandaIdToModel(uint)),
  //          parentWidget()->parentWidget()->parentWidget()->
  //          parentWidget()->parentWidget()->parentWidget()->
  //          parentWidget()->parentWidget()->parentWidget(),
  //          SLOT(eliminaComanda(uint)));
  connect(this,SIGNAL(sendComandaIdToModel(uint)),
          this,SLOT(eliminaElemento(uint)));
  connect(this, SIGNAL(datiModificati()),
          parentWidget(), SLOT(tabellaModificata()));
}

// if qta == 0 (default) viene inserito QSpinBox non editabile e con qta == 0
// Altrimenti viene inserito QSpinBox non editabile e con valore == qta
void TabellaComande::inserisciElemento(pacchetto* p, uint qta){
  tabella->insertRow(tabella->rowCount());
  QSpinBox* s = nullptr;
  if(objectName()=="tabPizzeComanda"){
    pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(p);
    QTableWidgetItem* item = nullptr;
    item = new QTableWidgetItem(QString::fromStdString(pP->nome));
    item->setData(Qt::UserRole, pP->ID);
    tabella->setItem(tabella->rowCount()-1, 0, item);
    s = new QSpinBox(tabella);
    s->setValue(qta);
    tabella->setCellWidget(tabella->rowCount()-1, 1, s);
    item = new QTableWidgetItem(
          QString::fromStdString(to_string_with_precision(pP->prezzo)));
    tabella->setItem(tabella->rowCount()-1, 2, item);
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
    tabella->setItem(tabella->rowCount()-1, 3, item);

  }
  else{
    pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(p);
    QTableWidgetItem* item = nullptr;
    item = new QTableWidgetItem(QString::fromStdString(pB->nome));
    item->setData(Qt::UserRole, pB->ID);
    tabella->setItem(tabella->rowCount()-1, 0, item);
    s = new QSpinBox(tabella);
    s->setValue(qta);
    tabella->setCellWidget(tabella->rowCount()-1, 1, s);
    item = new QTableWidgetItem(
          QString::fromStdString(to_string_with_precision(pB->prezzo)));
    tabella->setItem(tabella->rowCount()-1, 2, item);
    item = new QTableWidgetItem(
          QString::fromStdString(to_string_with_precision(pB->capacita)));
    tabella->setItem(tabella->rowCount()-1, 3, item);
  }
  // connessione segnale emesso da SpinBox
  connect(s, SIGNAL(valueChanged(int)), this, SLOT(selezionaQuantitaHandler(int)));
  // connessione segnale emesso da CheckBox
  //connect(.., SIGNAL(stateChanged(int), this, SLOT(selezionaQuantitaHandler(int)));

  int i = tabella->rowCount()-1;
  for(int j=0 ; j<4 ; j++){
    if(j==1)
      dynamic_cast<QSpinBox*>(tabella->cellWidget(i,j))->setEnabled(false);
    else{
      QTableWidgetItem* item = tabella->item(i,j);
      item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    }
  }
}

void TabellaComande::rendiEditabile(bool b){
  if(b){
    for(int i = 0; i < tabella->rowCount(); ++i)
      dynamic_cast<QSpinBox*>(tabella->cellWidget(i,1))->setEnabled(b);

    //inserimento checkbox su ogni elemento della tabella
    tabella->insertColumn(tabella->columnCount());
    QTableWidgetItem* headerLabel = new QTableWidgetItem();
    headerLabel->setText("");
    tabella->setHorizontalHeaderItem(tabella->columnCount()-1,headerLabel);
    for(int i = 0; i < tabella->rowCount(); ++i){
      QCheckBox* c = new QCheckBox(tabella);
      c->setProperty("row",i);
      if(dynamic_cast<QSpinBox*>(tabella->cellWidget(i,1))->value()>0)
        c->setChecked(true);
      tabella->setCellWidget(i, tabella->columnCount()-1, c);
      connect(c,SIGNAL(clicked()),this,SIGNAL(datiModificati()));
      connect(c, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool)));
    }
  }
  else{
    for(int i = 0; i < tabella->rowCount(); ++i)
      dynamic_cast<QSpinBox*>(tabella->cellWidget(i,1))->setEnabled(b);

    //rimozione di ogni riga non checkata
    for(int i = 0; i < tabella->rowCount(); ++i){
      if(!dynamic_cast<QCheckBox*>(tabella->cellWidget(i,tabella->columnCount()-1))->isChecked()){
        tabella->removeRow(i);
        i--;
      }
    }
    tabella->removeColumn(tabella->columnCount()-1);
  }
}

void TabellaComande::riempiContenutoPacchetto(std::unordered_map
                                              <uint, uint>& ordine){
  for(int i=0; i < tabella->rowCount(); ++i)
    ordine.insert({tabella->item(i,0)->data(Qt::UserRole).toInt(),
                   dynamic_cast<QSpinBox*>(tabella->cellWidget(i,1))
                   ->value()});
}

void TabellaComande::checkBoxToggled(bool stato){
  QObject *cb = sender();
  int row = cb->property("row").toInt();
  if(stato)
    dynamic_cast<QSpinBox*>(tabella->cellWidget(row,1))->setValue(1);
  else
    dynamic_cast<QSpinBox*>(tabella->cellWidget(row,1))->setValue(0);
}

void TabellaComande::selezionaQuantitaHandler(int) { emit datiModificati(); }
