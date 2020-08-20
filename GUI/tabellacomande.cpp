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
}

// if qta == 0 (default) viene inserito QSpinBox non editabile e con qta == 0
// Altrimenti viene inserito QSpinBox non editabile e con valore == qta
void TabellaComande::inserisciElemento(pacchetto* p, uint qta){
  tabella->insertRow(tabella->rowCount());
  if(objectName()=="tabPizzeComanda"){
    pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(p);
    QTableWidgetItem* item = nullptr;
    item = new QTableWidgetItem(QString::fromStdString(pP->nome));
    item->setData(Qt::UserRole, pP->ID);
    tabella->setItem(tabella->rowCount()-1, 0, item);
    QSpinBox* s = new QSpinBox(tabella);
    s->setValue(qta);
    tabella->setCellWidget(tabella->rowCount()-1, 1, s);
    item = new QTableWidgetItem(
          QString::fromStdString(to_string_with_precision(pP->prezzo)));
    tabella->setItem(tabella->rowCount()-1, 2, item);
  }
  else{
    pacchettoBevanda* pP = dynamic_cast<pacchettoBevanda*>(p);
    QTableWidgetItem* item = nullptr;
    item = new QTableWidgetItem(QString::fromStdString(pP->nome));
    item->setData(Qt::UserRole, pP->ID);
    tabella->setItem(tabella->rowCount()-1, 0, item);
    QSpinBox* s = new QSpinBox(tabella);
    s->setValue(qta);
    tabella->setCellWidget(tabella->rowCount()-1, 1, s);
    item = new QTableWidgetItem(
          QString::fromStdString(to_string_with_precision(pP->prezzo)));
    tabella->setItem(tabella->rowCount()-1, 2, item);
  }
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
