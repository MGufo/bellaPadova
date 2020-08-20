#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(Controller* c, QWidget* parent): QWidget(parent), controller(c){
  mainLayout = new QVBoxLayout(this);
  Header* header = new Header(this);
  QTabWidget* content = new QTabWidget(this);
  Menu* menu = new Menu(content);
  Comande* comande = new Comande(content);
  Inventario* inventario = new Inventario(content);
  Contabilizzazione* contabilizzazione = new Contabilizzazione(content);


  mainLayout->setMenuBar(drawMenubar());
  mainLayout->addWidget(header);
  content->addTab(menu, "Menu");
  content->addTab(comande, "Comande");
  content->addTab(inventario, "Inventario");
  content->addTab(contabilizzazione, "Contabilizzazione");
  connect(contabilizzazione, SIGNAL(con_calcoloFatturato(const QDate&, const QDate&)), this, SLOT(calcoloFatturato(const QDate&, const QDate&)));

  connect(this, SIGNAL(saveAndExit()), controller, SLOT(saveAndExit()));
  mainLayout->addWidget(content);
  setStylePizzeria();
  setLayout(mainLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::setStylePizzeria() {
  mainLayout->setSpacing(0);
  mainLayout->setMargin(0);
  mainLayout->setContentsMargins(0,-1,0,-1);
  setMinimumSize(QSize(1025,800));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setObjectName("Pizzeria");

  QFile file(":/resources/style.css");
  file.open(QFile::ReadOnly);
  QString stylePizzeria = QLatin1String(file.readAll());

  setStyleSheet(stylePizzeria);
}

QMenuBar* MainWindow::drawMenubar() const{
  QMenuBar* menuBar = new QMenuBar();
  QMenu* category_File = new QMenu("File", menuBar);
  QMenu* category_Save = new QMenu("Salva", menuBar);
  QAction* file_Exit = new QAction("Esci", category_File);
  QAction* salvaComande = new QAction("Comande", category_Save);
  QAction* salvaRisorse = new QAction("Inventario e Menu", category_Save);

  connect(salvaComande, SIGNAL(triggered()), controller, SLOT(salvaComande()));
  connect(salvaRisorse, SIGNAL(triggered()), controller, SLOT(salvaRisorse()));

  connect(file_Exit, SIGNAL(triggered()), this, SLOT(close()));

  category_File->addAction(file_Exit);
  category_Save->addAction(salvaComande);
  category_Save->addAction(salvaRisorse);

  menuBar->addMenu(category_File);
  menuBar->addMenu(category_Save);

  return menuBar;
}

void MainWindow::calcoloFatturato(const QDate& inizio, const QDate& fine){
  controller->calcoloFatturato(inizio, fine);
}

void MainWindow::creaNuovoArticolo(pacchettoArticolo* p){
  controller->creaNuovoArticolo(p);
}

void MainWindow::creaNuovoConsumabile(pacchettoConsumabile* pC){
  controller->creaNuovoConsumabile(pC);
}

void MainWindow::modificaArticolo(pacchettoArticolo* p){
  controller->modificaArticolo(p);
}

void MainWindow::modificaConsumabile(pacchettoConsumabile* p){
    controller->modificaConsumabile(p);
}

void MainWindow::creaNuovaComanda(pacchettoComanda* pC){
  controller->creaNuovaComanda(pC);
}

void MainWindow::modificaComanda(pacchettoComanda* pC){
  controller->modificaComanda(pC);
}

void MainWindow::eliminaComanda(uint ID){
  controller->eliminaComanda(ID);
}

void MainWindow::richiediDettagliComanda(uint ID){
  const pacchettoComanda* comanda = controller->recuperaInfoComanda(ID);
  if(comanda != nullptr){
    Comande* widgetComande = findChild<Comande*>("widgetComande");
    QList<ComandaGUI*> comandeGUI = widgetComande->findChildren<ComandaGUI*>();
    const QList<pacchetto*>* contenutoComanda =
        controller->recuperaContenutoComanda(ID);
    auto it = comandeGUI.begin();
    bool trovato = false;
    while(!trovato && it != comandeGUI.end()){
      if((*it)->getID() == ID){
        trovato = true;
        ((*it)->findChild<PaginaComanda*>())->setInfoComanda(comanda,
                                                             contenutoComanda);
      ++it;
      }
    }
  }
}

void MainWindow::aumentaCurrent(){
  controller->eseguiComanda();
}

void MainWindow::eliminaArticolo(uint id){
  controller->eliminaArticolo(id);
}

void MainWindow::eliminaConsumabile(uint id){
  controller->eliminaConsumabile(id);
}

void MainWindow::visualizzaElementiInWizardArticolo(bool option_pizza) const{
  QList<pacchetto*>* inventario = controller->recuperaInventario();
  if(option_pizza){

      QTableWidget* wrapperFarine = findChild<QTableWidget*>("farineWrapper");
      for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
        if(dynamic_cast<pacchettoFarina*>(*it)){
          pacchettoFarina* pF = dynamic_cast<pacchettoFarina*>(*it);
          wrapperFarine->insertRow(wrapperFarine->rowCount());
          QTableWidgetItem* item = nullptr;

          item = new QTableWidgetItem(QString::fromStdString(std::to_string(pF->ID)));
          wrapperFarine->setItem(wrapperFarine->rowCount()-1, 0, item);
          QRadioButton* r = new QRadioButton(wrapperFarine);
          wrapperFarine->setCellWidget(wrapperFarine->rowCount()-1, 1, r);
          item = new QTableWidgetItem(QString::fromStdString(pF->nome));
          wrapperFarine->setItem(wrapperFarine->rowCount()-1, 2, item);
          item = new QTableWidgetItem((pF->locale ? "Si" : "No"));
          wrapperFarine->setItem(wrapperFarine->rowCount()-1, 3, item);
          item = new QTableWidgetItem(QString::fromStdString(pF->tipologia));
          wrapperFarine->setItem(wrapperFarine->rowCount()-1, 4, item);
        }
      }
      dynamic_cast<QRadioButton*>(wrapperFarine->cellWidget(0,1))->setChecked(true);

    QTableWidget* wrapperIngredienti = findChild<QTableWidget*>("ingredientiWrapper");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
      if(dynamic_cast<pacchettoIngrediente*>(*it) &&
         !dynamic_cast<pacchettoFarina*>(*it)){
        pacchettoIngrediente* pI = dynamic_cast<pacchettoIngrediente*>(*it);
        wrapperIngredienti->insertRow(wrapperIngredienti->rowCount());
        QTableWidgetItem* item = nullptr;

        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pI->ID)));
        wrapperIngredienti->setItem(wrapperIngredienti->rowCount()-1, 0, item);
        QCheckBox* c = new QCheckBox(wrapperIngredienti);
        wrapperIngredienti->setCellWidget(wrapperIngredienti->rowCount()-1, 1, c);
        item = new QTableWidgetItem(QString::fromStdString(pI->nome));
        wrapperIngredienti->setItem(wrapperIngredienti->rowCount()-1, 2, item);
        item = new QTableWidgetItem((pI->locale ? "Si" : "No"));
        wrapperIngredienti->setItem(wrapperIngredienti->rowCount()-1, 3, item);
      }
    }
    wrapperIngredienti->setEditTriggers(QAbstractItemView::NoEditTriggers);
  }
  else{
    QTableWidget* wrapperBevande = findChild<QTableWidget*>("bevandeWrapper_articoli");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
      pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(*it);
      if(pB){
        wrapperBevande->insertRow(wrapperBevande->rowCount());
        QTableWidgetItem* item = nullptr;

        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->ID)));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 0, item);
        QRadioButton* r = new QRadioButton(wrapperBevande);
        wrapperBevande->setCellWidget(wrapperBevande->rowCount()-1, 1, r);
        item = new QTableWidgetItem(QString::fromStdString(pB->nome));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 2, item);
        item = new QTableWidgetItem(QString::fromStdString(to_string_with_precision(pB->prezzo)));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 3, item);
        item = new QTableWidgetItem(QString::fromStdString(to_string_with_precision(pB->capacita)));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 4, item);
        item = new QTableWidgetItem((pB->tipo ? "Lattina" : "Bottiglia"));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 5, item);
      }
    }
    dynamic_cast<QRadioButton*>(wrapperBevande->cellWidget(0,1))->setChecked(true);
    wrapperBevande->setEditTriggers(QAbstractItemView::NoEditTriggers);
  }
  delete inventario;
}

void MainWindow::visualizzaElementiCheckatiInWizardArticolo(bool option_pizza) const{

  if(option_pizza){
    //inserisco la farina selezionata nella pagina finale del wizard
    QTableWidget* farineTabellaWrapper = findChild<QTableWidget*>("farineWrapper");
    for(int i=0; i<farineTabellaWrapper->rowCount() ; i++){
        QRadioButton* radioFarina = dynamic_cast<QRadioButton*>(farineTabellaWrapper->cellWidget(i,1));
        if(radioFarina->isChecked()){
            QWidget* farineVisualWrapper = findChild<QWidget*>("farinaVisualizationWrapper");
            QLabel* label = new QLabel((farineTabellaWrapper->item(i,2))->text());
            dynamic_cast<QVBoxLayout*>(farineVisualWrapper->layout())->addWidget(label);
        }
    }

    //inserisco gli ingredienti selezionati nella pagina finale del wizard
    QTableWidget* ingredientiTabellaWrapper = findChild<QTableWidget*>("ingredientiWrapper");
    for(int i=0; i<ingredientiTabellaWrapper->rowCount() ; i++){
        QCheckBox* checkIngrediente = dynamic_cast<QCheckBox*>(ingredientiTabellaWrapper->cellWidget(i,1));
        if(checkIngrediente->isChecked()){
            QWidget* ingredientiVisualWrapper = findChild<QWidget*>("ingredientiVisualizationWrapper");
            QLabel* label = new QLabel(ingredientiTabellaWrapper->item(i,2)->text());
            dynamic_cast<QVBoxLayout*>(ingredientiVisualWrapper->layout())->addWidget(label);
        }
    }
  }
  else{
    //inserisco le bevande selezionate nella pagina finale del wizard
      QTableWidget* bevandeTabellaWrapper = findChild<QTableWidget*>("bevandeWrapper_articoli");
      for(int i=0; i<bevandeTabellaWrapper->rowCount() ; i++){
          QRadioButton* radioBevanda = dynamic_cast<QRadioButton*>(bevandeTabellaWrapper->cellWidget(i,1));
          if(radioBevanda->isChecked()){
              QWidget* bevandeVisualWrapper = findChild<QWidget*>("bevandeVisualizationWrapper_articoli");
              QLabel* label = new QLabel(bevandeTabellaWrapper->item(i,2)->text());
              dynamic_cast<QVBoxLayout*>(bevandeVisualWrapper->layout())->addWidget(label);
          }
      }
  }
}

void MainWindow::visualizzaElementiInWizardComanda() const{
    QList<pacchetto*>* menu = controller->recuperaMenu();

    QTableWidget* wrapperPizze = findChild<QTableWidget*>("pizzeWrapper");
    QTableWidget* wrapperBevande = findChild<QTableWidget*>("bevandeWrapper_comande");
    for(auto it = menu->constBegin(); it != menu->constEnd(); ++it){
        if(dynamic_cast<pacchettoPizza*>(*it)){
            pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(*it);
            wrapperPizze->insertRow(wrapperPizze->rowCount());
            QTableWidgetItem* item = nullptr;

            QCheckBox* c = new QCheckBox(wrapperPizze);
            wrapperPizze->setCellWidget(wrapperPizze->rowCount()-1, 0, c);
            item = new QTableWidgetItem(QString::fromStdString(pP->nome));
            item->setData(Qt::UserRole,pP->ID);
            wrapperPizze->setItem(wrapperPizze->rowCount()-1, 1, item);
            QSpinBox* s = new QSpinBox(wrapperPizze);
            s->setValue(1);
            wrapperPizze->setCellWidget(wrapperPizze->rowCount()-1, 2, s);
        }

        else if(dynamic_cast<pacchettoBevanda*>(*it)){
            pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(*it);
            wrapperBevande->insertRow(wrapperBevande->rowCount());
            QTableWidgetItem* item = nullptr;

            QCheckBox* c = new QCheckBox(wrapperBevande);
            wrapperBevande->setCellWidget(wrapperBevande->rowCount()-1, 0, c);
            item = new QTableWidgetItem(QString::fromStdString(pB->nome));
            item->setData(Qt::UserRole,pB->ID);
            wrapperBevande->setItem(wrapperBevande->rowCount()-1, 1, item);
            QSpinBox* s = new QSpinBox(wrapperBevande);
            s->setValue(1);
            wrapperBevande->setCellWidget(wrapperBevande->rowCount()-1, 2, s);
        }
    }
    wrapperPizze->setEditTriggers(QAbstractItemView::NoEditTriggers);
    wrapperBevande->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::visualizzaElementiCheckatiInWizardComanda() const{
    //inserisco le pizze selezionate nella pagina finale del wizard
    QTableWidget* pizzeTabellaWrapper = findChild<QTableWidget*>("pizzeWrapper");
    for(int i=0; i<pizzeTabellaWrapper->rowCount() ; i++){
        QCheckBox* checkPizza = dynamic_cast<QCheckBox*>(pizzeTabellaWrapper->cellWidget(i,0));
        if(checkPizza->isChecked()){
            QWidget* pizzeVisualWrapper = findChild<QWidget*>("pizzeVisualizationWrapper");
            QString testo("[");
            int qta = dynamic_cast<QSpinBox*>(pizzeTabellaWrapper->cellWidget(i,2))->value();
            testo.append(QString::fromStdString(std::to_string(qta)));
            testo.append("] ");
            testo.append(pizzeTabellaWrapper->item(i,1)->text());
            QLabel* label = new QLabel(testo);
            dynamic_cast<QVBoxLayout*>(pizzeVisualWrapper->layout())->addWidget(label);
        }
    }
    //inserisco le bevande selezionate nella pagina finale del wizard
    QTableWidget* bevandeTabellaWrapper = findChild<QTableWidget*>("bevandeWrapper_comande");
    for(int i=0; i<bevandeTabellaWrapper->rowCount() ; i++){
        QCheckBox* checkBevanda = dynamic_cast<QCheckBox*>(bevandeTabellaWrapper->cellWidget(i,0));
        if(checkBevanda->isChecked()){
            QWidget* bevandeVisualWrapper = findChild<QWidget*>("bevandeVisualizationWrapper_comande");
            QString testo("[");
            int qta = dynamic_cast<QSpinBox*>(bevandeTabellaWrapper->cellWidget(i,2))->value();
            testo.append(QString::fromStdString(std::to_string(qta)));
            testo.append("] ");
            testo.append(bevandeTabellaWrapper->item(i,1)->text());
            QLabel* label = new QLabel(testo);
            dynamic_cast<QVBoxLayout*>(bevandeVisualWrapper->layout())->addWidget(label);
        }
    }
}
	
void MainWindow::closeEvent(QCloseEvent *event){
  if(!controller->canQuit()){
    QMessageBox* savePrompt = new QMessageBox(this);
    savePrompt->setText("Sono presenti modifiche non salvate.");
    savePrompt->setInformativeText("Vuoi salvare le modifiche?");
    savePrompt->setStandardButtons(
          QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    savePrompt->setDefaultButton(QMessageBox::Save);
    int res = savePrompt->exec();
    switch (res){
      case QMessageBox::Save: {
        emit saveAndExit();
        event->accept();
        break;
      }
      case QMessageBox::Discard: {
        event->accept();
        break;
      }
      case QMessageBox::Cancel:{
        event->ignore();
        break;
      }
    }
  }
}

void MainWindow::aggiornaContabilizzazione(double guadagno){
  if(guadagno > 0)
    findChild<QLineEdit*>("mGuadagno")->setStyleSheet("color: darkgreen;");
  else
    findChild<QLineEdit*>("mGuadagno")->setStyleSheet("color: darkred;");
    findChild<QLineEdit*>("mGuadagno")->clear();
    findChild<QLineEdit*>("mGuadagno")->insert(QString::number(guadagno));
}

void MainWindow::pulisciInventario(){
    TabellaRisorse* tabBevande =
      findChild<TabellaRisorse*>("tabBevandeInventario");
    tabBevande->pulisciTabella();
    TabellaRisorse* tabIngredienti =
      findChild<TabellaRisorse*>("tabIngredientiInventario");
    tabIngredienti->pulisciTabella();
}

void MainWindow::aggiornaInventario(pacchetto * p){
  if(dynamic_cast<pacchettoBevanda*>(p)){
    TabellaRisorse* tabBevande =
        findChild<TabellaRisorse*>("tabBevandeInventario");
    tabBevande->inserisciElemento(p);
  }
  else{
    TabellaRisorse* tabIngredienti =
        findChild<TabellaRisorse*>("tabIngredientiInventario");
    tabIngredienti->inserisciElemento(p);
  }
}

void MainWindow::visualizzaInventario(){
    pulisciInventario();
    QList<pacchetto*>* inventario = controller->recuperaInventario();
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
        aggiornaInventario(*it);
    }
    delete inventario;
}

void MainWindow::aggiornaMenu(pacchetto* p){
  TabellaRisorse* tab;
  if(dynamic_cast<pacchettoPizza*>(p))
    tab = findChild<TabellaRisorse*>("tabPizzeMenu");
  else
    tab = findChild<TabellaRisorse*>("tabBevandeMenu");

  tab->inserisciElemento(p);
}

void MainWindow::visualizzaMenu(){
  QList<pacchetto*>* menu = controller->recuperaMenu();
  for(auto it = menu->constBegin(); it != menu->constEnd(); ++it){
      aggiornaMenu(*it);
  }
  delete menu;
}

void MainWindow::pulisciComande(){
  QWidget* wrapperInExec = findChild<QWidget*>("wrapperInEsecuzione");
  QList<ComandaGUI*> comandeInExec = wrapperInExec->findChildren<ComandaGUI*>();
  for(auto it = comandeInExec.begin(); it != comandeInExec.end(); ++it){
    wrapperInExec->layout()->removeWidget(*it);
    delete *it;
  }
  QWidget* wrapperExec = findChild<QWidget*>("wrapperEseguite");
  QList<ComandaGUI*> comandeExec = wrapperExec->findChildren<ComandaGUI*>();
  for(auto it = comandeExec.begin(); it != comandeExec.end(); ++it){
    wrapperExec->layout()->removeWidget(*it);
    delete *it;
  }
}

void MainWindow::visualizzaComande(){
  pulisciComande();
  QList<pacchettoComanda*>* comande = controller->recuperaComande();
  Comande* widgetComande = findChild<Comande*>("widgetComande");
  for(auto it = comande->constBegin(); it != comande->constEnd(); ++it){
    widgetComande->aggiungiComanda(*it);
  }
  widgetComande->setStyleNextOrderButton();
  delete comande;
}

void MainWindow::mostraErrore(const QString & messaggio){
  QErrorMessage* errorDialog = new QErrorMessage(this);
  errorDialog->showMessage(messaggio);
}
