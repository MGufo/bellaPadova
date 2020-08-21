#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget *parent, uint ID) : QWidget(parent) {
  comandaID = ID;
  paginaEditabile = false;
  contenutoModificato = false;
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
  connect(this, SIGNAL(riempiTabelleConMenu(uint)),
          parentWidget()->parentWidget()->parentWidget()->parentWidget()->
          parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(visualizzaMenuInComanda(uint)));
  connect(this, SIGNAL(inviaComanda(pacchettoComanda*)),
          parentWidget()->parentWidget()->parentWidget()->parentWidget()->
          parentWidget()->parentWidget()->parentWidget()->parentWidget(),
          SLOT(modificaComanda(pacchettoComanda*)));
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

void PaginaComanda::smistaPacchettoInTabella(pacchetto* p){
  if(dynamic_cast<pacchettoPizza*>(p))
    Pizze->inserisciElemento(p);
  else
    Bevande->inserisciElemento(p);
}

void PaginaComanda::inizializzaPizze(QWidget* _parent){
  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Quantità");
  headerLabels->push_back("Prezzo");
  headerLabels->push_back("Ingredienti");

  Pizze = new TabellaComande(_parent, "Pizze", headerLabels);
  Pizze->setObjectName("tabPizzeComanda");
  Pizze->rendiEditabile(paginaEditabile);
}

void PaginaComanda::inizializzaBevande(QWidget* _parent){
  QStringList* headerLabels = new QStringList();
  headerLabels->push_back("Nome");
  headerLabels->push_back("Quantità");
  headerLabels->push_back("Prezzo");
  headerLabels->push_back("Capacità");

  Bevande = new TabellaComande(_parent, "Bevande", headerLabels);
  Bevande->setObjectName("tabBevandeComanda");
  Bevande->rendiEditabile(paginaEditabile);
}

void PaginaComanda::inizializzaPulsante(QWidget* _parent){
  modificaDati = new QPushButton(_parent);
  modificaDati->setText("Modifica");
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

  QList<QLineEdit*> QLEinfo = infoComanda->findChildren<QLineEdit*>();
  for (QLineEdit* x : QLEinfo)
    connect(x, SIGNAL(textEdited(QString)), this, SLOT(paginaModificata()));
}

void PaginaComanda::creaPacchettoComanda(){
  string ora = orario->text().toStdString();
  int hh = std::stoi(ora.substr(0,1));
  int mm = std::stoi(ora.substr(3,4));
  QTime QTora(hh,mm);
  pacchettoComanda* pC =
      new pacchettoComanda(comandaID, nome->text().toStdString(),
                           indirizzo->text().toStdString(),
                           telefono->text().toStdString(), QTora, 0, false);
  auto& contenutoOrdine = pC->ordinazione;
  Pizze->riempiContenutoPacchetto(contenutoOrdine);
  Bevande->riempiContenutoPacchetto(contenutoOrdine);

  emit inviaComanda(pC);
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
  if(paginaEditabile){
    paginaEditabile = false;
    modificaDati->setText("Modifica");
    modificaDati->setObjectName("Modifica");
    /*
    TODO:
    1. Aggiungere un bool "TabellaModificata" che indichi se le tabelle (pizze o bevande) siano state modificate dall'utente dopo averle riempite con il menù
    2. Controllare tramite una funzione lo stato del booleano dentro questo if
    3. Se almeno un elemento tra tabelle e QLineEdit è stato modificato si crea il pacchettoComanda e lo si invia allo slot modificaComanda di mainwindow
    */
  }
  else{
    paginaEditabile = true;
    modificaDati->setText("Finisci di Modificare");
    modificaDati->setObjectName("FineModifica");
    emit riempiTabelleConMenu(comandaID);
  }
  modificaInfo(paginaEditabile);
  modificaTabelle(paginaEditabile);

  if(contenutoModificato) {
    creaPacchettoComanda();
    contenutoModificato = false;
  }
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

void PaginaComanda::paginaModificata(){ contenutoModificato = true; }
