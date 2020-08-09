#include "nuovoArticolo_bevanda.h"

NuovoArticolo_bevanda::NuovoArticolo_bevanda(QWidget* parent) : QWidget(parent){

    //Elenco di bevande tra cui scegliere da inserire nel menù
    QStringList* labelsBevande = new QStringList();
    labelsBevande->push_back("ID");
    labelsBevande->push_back("");
    labelsBevande->push_back("Nome");
    labelsBevande->push_back("Prezzo");
    labelsBevande->push_back("Capacità");
    labelsBevande->push_back("Tipologia");
    bevandeWrapper = new QTableWidget(0,6,this);
    bevandeWrapper->setObjectName("bevandeWrapper");
    bevandeWrapper->verticalHeader()->setVisible(false);
    bevandeWrapper->setMinimumWidth(500);
    // bevandeWrapper->setMaximumWidth(2100);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(bevandeWrapper->sizePolicy().hasHeightForWidth());
    bevandeWrapper->setSizePolicy(sizePolicy);
    QHeaderView* headerBevande = new QHeaderView(Qt::Horizontal,bevandeWrapper);
    bevandeWrapper->setHorizontalHeaderLabels(*labelsBevande);
    bevandeWrapper->setHorizontalHeader(headerBevande);
    headerBevande->setSectionResizeMode(headerBevande->ResizeToContents);
    headerBevande->setSectionResizeMode(2, headerBevande->Stretch);

    layoutBevanda = new QVBoxLayout(this);
    layoutBevanda->addWidget(bevandeWrapper);
    setLayout(layoutBevanda);
}
