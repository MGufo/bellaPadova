#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget *parent, uint ID) : QWidget(parent) {
  comandaID = ID;
  // Creazione subwidget infoComanda e tabelle
  inizializzaPizze(this);
  inizializzaBevande(this);
  inizializzaInfoComanda(this);
  // Creazione pulsanti
  inizializzaPulsante(this);
  // Creazione layout paginaComanda e aggiunta dei subwidget
  layoutPaginaComanda = new QGridLayout(this);
  layoutPaginaComanda->addWidget(infoComanda, 1, 0, 5, 5, Qt::AlignLeft);
  layoutPaginaComanda->addWidget(Pizze, 0, 6, 5, 5);
  layoutPaginaComanda->addWidget(Bevande, 6, 6, 5, 5);
  layoutPaginaComanda->addWidget(modificaDati, 7, 0, 3, 5, Qt::AlignHCenter);
  setStylePaginaComanda();
  setLayout(layoutPaginaComanda);
  connect(this, SIGNAL(enableButton()), parentWidget(), SLOT(enableButton()));
  connect(modificaDati, SIGNAL(clicked()), this, SLOT(toggleModifica()));
}

PaginaComanda::~PaginaComanda() {}

void PaginaComanda::setInfoComanda(const pacchettoComanda* pC,
                                   const QList<pacchetto*>* ord){
  // Info comanda
  orario->setText(pC->oraConsegna.toString());
  nome->setText(QString::fromStdString(pC->nome));
  indirizzo->setText(QString::fromStdString(pC->indirizzo));
  telefono->setText(QString::fromStdString(pC->telefono));
  totale->setText(QString::fromStdString(to_string_with_precision(pC->totale)));
  // Contenuto Ordine
  for(auto it = ord->cbegin(); it != ord->cend(); ++it){
    if(dynamic_cast<pacchettoPizza*>(*it))
      Pizze->inserisciElemento(*it, pC->ordinazione.at((*it)->ID));
    else
      Bevande->inserisciElemento(*it, pC->ordinazione.at((*it)->ID));
  }
}

void PaginaComanda::inizializzaPizze(QWidget* _parent){
  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Quantità");
  headerLabels->push_back("Prezzo");

  Pizze = new TabellaComande(_parent, "Pizze", headerLabels);
  Pizze->setObjectName("tabPizzeComanda");
}

void PaginaComanda::inizializzaBevande(QWidget* _parent){
  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Quantità");
  headerLabels->push_back("Prezzo");

  Bevande = new TabellaComande(_parent, "Bevande", headerLabels);
  Bevande->setObjectName("tabBevandeComanda");
}

void PaginaComanda::inizializzaPulsante(QWidget* _parent){
  modificaDati = new QPushButton(_parent);
  modificaDati->setText("Modifica");
  editabile = false;
}

void PaginaComanda::inizializzaInfoComanda(QWidget* _parent){
  infoComanda = new QWidget(_parent);
  orario = new QLineEdit(infoComanda);
  orario->setEnabled(false);
  nome = new QLineEdit(infoComanda);
  nome->setEnabled(false);
  indirizzo = new QLineEdit(infoComanda);
  indirizzo->setEnabled(false);
  telefono = new QLineEdit(infoComanda);
  telefono->setEnabled(false);
  QFormLayout* info = new QFormLayout(infoComanda);
  info->addRow("Orario: ", orario);
  info->addRow("Nome: ", nome);
  info->addRow("Indirizzo: ", indirizzo);
  info->addRow("Telefono: ", telefono);
  totale = new QLabel(infoComanda);
  info->addRow("Totale: ", totale);
  infoComanda->setLayout(info);
}

void PaginaComanda::setStylePaginaComanda(){
  setMinimumSize(1200, 600);
  setMaximumSize(1200, 600);
  setObjectName("paginaComanda");
  modificaDati->setObjectName("modificaDati");
}

void PaginaComanda::closeEvent(QCloseEvent* event){
  emit enableButton();
  event->accept();
}

void PaginaComanda::toggleModifica(){
  if(editabile){
    editabile = false;
    modificaDati->setText("Modifica");
    modificaDati->setObjectName("Modifica");
  }
  else{
    editabile = true;
    modificaDati->setText("Finisci di Modificare");
    modificaDati->setObjectName("FineModifica");
  }
  modificaInfo(editabile);
  modificaTabelle(editabile);
}

void PaginaComanda::modificaInfo(bool b){
  QList<QLineEdit*> info = infoComanda->findChildren<QLineEdit*>();
  for (QLineEdit* x : info)
    x->setEnabled(b);
}

void PaginaComanda::modificaTabelle(bool b){
    Pizze->rendiEditabile(b);
    Bevande->rendiEditabile(b);
    Pizze->cambiaColoreBordoCella(b);
}
