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
  //connect(.., SIGNAL(stateChanfed(int), this, SLOT(selezionaQuantitaHandler(int)));
  // connessione segnale emesso da pulsante elimina
  //connect(.., SIGNAL(clicked()), this, SLOT(eliminaElementoHandler()));
}

void TabellaComande::rendiEditabile(bool b){
  int k = tabella->rowCount()-1;
  int l = tabella->columnCount()-1;
  for(int i = 0; i < tabella->rowCount()-1; ++i)
    for(int j = 0; j < tabella->columnCount()-1; ++j)
      if(dynamic_cast<QWidget*>(tabella->cellWidget(i,j)))
        dynamic_cast<QWidget*>(tabella->cellWidget(i,j))->setEnabled(b);
      else{
        QTableWidgetItem* item = tabella->item(i,j);
        if(b) item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        else item->setFlags(item->flags() | Qt::ItemIsEditable);
      }
}

void TabellaComande::riempiContenutoPacchetto(std::unordered_map
                                              <uint, uint>& ordine){
  for(int i=0; i < tabella->rowCount()-1; ++i)
    ordine.insert({tabella->item(i,0)->data(Qt::UserRole).toInt(),
                   dynamic_cast<QSpinBox*>(tabella->cellWidget(i,1))
                   ->text().toInt()});
}


void TabellaComande::emitDataOnCellChanged(int, int){

}

void TabellaComande::checkBoxToggled(bool){
    QObject *cb = sender();
    int row = cb->property("row").toInt();
    int column = cb->property("column").toInt();

    emit tabella->cellChanged(row,column);
}

void TabellaComande::forwardIdToModel(uint id){
    /*
    if(tabella->objectName()=="tabIngredientiInventario" ||
            tabella->objectName()=="tabBevandeInventario")
        emit sendIdToModel(id,true);
    else
        emit sendIdToModel(id,false);
        */
}

void TabellaComande::eliminaElementoHandler(){ emit datiModificati(); }

void TabellaComande::selezionaQuantitaHandler(int) { emit datiModificati(); }
