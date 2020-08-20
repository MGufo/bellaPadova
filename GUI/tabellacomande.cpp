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

void TabellaComande::inserisciElemento(const pacchetto* p){

}

void TabellaComande::rendiEditabile(bool b){

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
