#include "paginaComanda.h"

PaginaComanda::PaginaComanda(QWidget* parent, uint ID) : QWidget(parent) {
  comandaID = ID;
  paginaEditabile = false;
  contenutoModificato = false;
  oldOrario = new QTime();
  // Creazione subwidget infoComanda e tabelle
  inizializzaPizze(this);
  inizializzaBevande(this);
  inizializzaInfoComanda(this);
  // Creazione pulsanti
  inizializzaPulsante(this);
  // Creazione layout paginaComanda e aggiunta dei subwidget
  layoutPaginaComanda = new QGridLayout(this);
  layoutPaginaComanda->addWidget(infoComanda, 1, 0, 5, 5, Qt::AlignLeft);
  layoutPaginaComanda->addWidget(Pizze, 0, 6, 5, 10);
  layoutPaginaComanda->addWidget(Bevande, 6, 6, 5, 10);
  layoutPaginaComanda->addWidget(modificaDati, 7, 0, 3, 5, Qt::AlignHCenter);
  setStylePaginaComanda();
  setLayout(layoutPaginaComanda);
  connect(this, SIGNAL(enableButton()), parentWidget(), SLOT(enableButton()));
  connect(modificaDati, SIGNAL(clicked()), this, SLOT(toggleModifica()));
  connect(this, SIGNAL(mostraErrore(QString)),
          parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget(),
          SLOT(mostraErrore(QString)));
  connect(this, SIGNAL(riempiTabelleConMenu(uint)),
          parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget(),
          SLOT(visualizzaMenuInComanda(uint)));
  connect(this, SIGNAL(inviaComanda(pacchettoComanda*)),
          parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget()
              ->parentWidget(),
          SLOT(modificaComanda(pacchettoComanda*)));
}

void PaginaComanda::setInfoComanda(const pacchettoComanda* pC,
                                   QList<pacchetto*>* ord) {
  // Info comanda
  orario->setTime(pC->oraConsegna);
  oldOrario = &pC->oraConsegna;
  nome->setText(QString::fromStdString(pC->nome));
  nome->setPlaceholderText(QString::fromStdString(pC->nome));
  indirizzo->setText(QString::fromStdString(pC->indirizzo));
  indirizzo->setPlaceholderText(QString::fromStdString(pC->indirizzo));
  telefono->setText(QString::fromStdString(pC->telefono));
  telefono->setPlaceholderText(QString::fromStdString(pC->telefono));
  totale->setText(QString::fromStdString(to_string_with_precision(pC->totale)));
  // Contenuto Ordine
  for (auto it = ord->begin(); it != ord->end(); ++it) {
    if (dynamic_cast<pacchettoPizza*>(*it))
      Pizze->inserisciElemento(*it, pC->ordinazione.at((*it)->ID));
    else
      Bevande->inserisciElemento(*it, pC->ordinazione.at((*it)->ID));
  }
  QList<QLineEdit*> QLEinfo = infoComanda->findChildren<QLineEdit*>();
  for (QLineEdit* x : QLEinfo)
    connect(x, SIGNAL(textEdited(QString)), this, SLOT(infoModificate()));
  connect(orario, SIGNAL(timeChanged(QTime)), this,
          SLOT(orarioModificato(QTime)));
}

void PaginaComanda::smistaPacchettoInTabella(pacchetto* p) {
  if (dynamic_cast<pacchettoPizza*>(p))
    Pizze->inserisciElemento(p);
  else
    Bevande->inserisciElemento(p);
}

void PaginaComanda::disableEdit() {
  layoutPaginaComanda->removeWidget(modificaDati);
  delete modificaDati;
}

void PaginaComanda::inizializzaPizze(QWidget* _parent) {
  headerLabelsPizze = new QStringList();
  headerLabelsPizze->push_back("Nome");
  headerLabelsPizze->push_back("Quantità");
  headerLabelsPizze->push_back("Prezzo");
  headerLabelsPizze->push_back("Ingredienti");

  Pizze = new TabellaComande(_parent, "Pizze", headerLabelsPizze);
  Pizze->setObjectName("tabPizzeComanda");
}

void PaginaComanda::inizializzaBevande(QWidget* _parent) {
  headerLabelsBevande = new QStringList();
  headerLabelsBevande->push_back("Nome");
  headerLabelsBevande->push_back("Quantità");
  headerLabelsBevande->push_back("Prezzo");
  headerLabelsBevande->push_back("Capacità");

  Bevande = new TabellaComande(_parent, "Bevande", headerLabelsBevande);
  Bevande->setObjectName("tabBevandeComanda");
}

void PaginaComanda::inizializzaPulsante(QWidget* _parent) {
  modificaDati = new QPushButton(_parent);
  modificaDati->setText("Modifica");
  modificaDati->setObjectName("modificaDati");
}

void PaginaComanda::inizializzaInfoComanda(QWidget* _parent) {
  infoComanda = new QWidget(_parent);
  orario = new QTimeEdit(infoComanda);
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

void PaginaComanda::creaPacchettoComanda() {
  pacchettoComanda* pC = new pacchettoComanda(
      comandaID, nome->text().toStdString(), indirizzo->text().toStdString(),
      telefono->text().toStdString(), orario->time(), 0, false);
  std::unordered_map<uint, uint>& contenutoOrdine = pC->ordinazione;
  Pizze->riempiContenutoPacchetto(contenutoOrdine);
  Bevande->riempiContenutoPacchetto(contenutoOrdine);

  emit inviaComanda(pC);
}

void PaginaComanda::setStylePaginaComanda() {
  setMinimumSize(1500, 600);
  setMaximumSize(1500, 600);
  setObjectName("paginaComanda");
}

void PaginaComanda::closeEvent(QCloseEvent* event) {
  emit enableButton();
  event->accept();
}

void PaginaComanda::toggleModifica() {
  if (paginaEditabile) {
    paginaEditabile = false;
    modificaDati->setText("Modifica");
    modificaDati->setObjectName("modificaDati");
  } else {
    paginaEditabile = true;
    modificaDati->setText("Finisci di Modificare");
    modificaDati->setObjectName("modificaDati");
    emit riempiTabelleConMenu(comandaID);
  }
  modificaInfo(paginaEditabile);
  modificaTabelle(paginaEditabile);

  if (contenutoModificato) {
    contenutoModificato = false;
    creaPacchettoComanda();
  }
}

void PaginaComanda::modificaInfo(bool b) {
  orario->setEnabled(b);
  QList<QLineEdit*> info = infoComanda->findChildren<QLineEdit*>();
  for (QLineEdit* x : info) x->setEnabled(b);
}

void PaginaComanda::modificaTabelle(bool b) {
  Pizze->rendiEditabile(b);
  Bevande->rendiEditabile(b);
  Pizze->cambiaColoreBordoCella(b);
  Bevande->cambiaColoreBordoCella(b);
}

void PaginaComanda::infoModificate() {
  bool b = false;
  QList<QLineEdit*> info = infoComanda->findChildren<QLineEdit*>();
  for (QLineEdit* x : info) {
    if (x->isModified()) {
      if (x->text() == "") {
        emit mostraErrore(
            QString("Errore: Il campo non può essere"
                    " vuoto."));
        x->setText(x->placeholderText());
      } else
        b = true;
    }
  }
  if (b) contenutoModificato = true;
}

void PaginaComanda::orarioModificato(const QTime& newOrario) {
  if (*oldOrario != newOrario) contenutoModificato = true;
}

void PaginaComanda::tabellaModificata() { contenutoModificato = true; }
