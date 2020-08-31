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
