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
  setMinimumSize(QSize(1025,700));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

void MainWindow::creaNuovoConsumabile(pacchetto* pC){
  controller->creaNuovoConsumabile(pC);
}

void MainWindow::modificaConsumabile(pacchetto* pC){
  controller->modificaConsumabile(pC);
}

void MainWindow::visualizzaElementiInWizard(bool option_pizza) const{
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
    QTableWidget* wrapperBevande = findChild<QTableWidget*>("bevandeWrapper");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
      pacchettoBevanda* pB = dynamic_cast<pacchettoBevanda*>(*it);
      if(pB){
          /*
        QWidget* completeRadio = new QWidget(wrapper);
        QHBoxLayout* completeRadioLayout = new QHBoxLayout(completeRadio);
        QWidget* bb = new BevandaRadioButton(
              b->ID,QString::fromStdString(b->nome),b->prezzo,b->capacita,
              (b->tipo? "Lattina" : "Bottiglia"),completeRadio);
        QLabel* id = new QLabel(QString::fromStdString(std::to_string(b->ID)));
        QLabel* prezzo = new QLabel(
              QString::fromStdString(to_string_with_precision(b->prezzo)));
        QLabel* capacita = new QLabel(
              QString::fromStdString(to_string_with_precision(b->capacita)));
        QLabel* tipologia = new QLabel((b->tipo? "Lattina" : "Bottiglia"));

        completeRadioLayout->addWidget(bb);
        completeRadioLayout->addWidget(id);
        completeRadioLayout->addWidget(prezzo);
        completeRadioLayout->addWidget(capacita);
        completeRadioLayout->addWidget(tipologia);

        dynamic_cast<QVBoxLayout*>(wrapper->layout())->addWidget(completeRadio);
        */
        wrapperBevande->insertRow(wrapperBevande->rowCount());
        QTableWidgetItem* item = nullptr;

        item = new QTableWidgetItem(QString::fromStdString(std::to_string(pB->ID)));
        wrapperBevande->setItem(wrapperBevande->rowCount()-1, 0, item);
        QCheckBox* c = new QCheckBox(wrapperBevande);
        wrapperBevande->setCellWidget(wrapperBevande->rowCount()-1, 1, c);
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
  }
  delete inventario;
}

void MainWindow::visualizzaElementiCheckatiInWizard(bool option_pizza) const{
//  if(option_pizza){
//    //TODO: reupero informazioni contenute nei qtablewidget per mostrarle in nuovoArticolo_end
//    QTableWidget* ingredientiWrapper = findChild<QTableWidget*>("ingredientiWrapper");
//    auto checkBox = ingredientiWrapper->findChild<QTableModel*>();

//    QWidget* visualizationWrapper =
//        findChild<QWidget*>("ingredientiVisualizationWrapper");

//    //eliminazione dei vecchi ingredienti se presenti nel layout
//    QLayoutItem* item = nullptr;
//    while((item = visualizationWrapper->layout()->takeAt(1)) != NULL){
//      //IngredienteCheckBox* p = dynamic_cast<IngredienteCheckBox*>(item->widget());
//      //std::cout << p->text().toStdString() << " " << p->isChecked() << std::endl;
//      delete item->widget();
//      delete item;
//    }
//    //riempimento del layout con gli ingredienti aggiornati
//    for(auto it = ++(checkBox.cbegin()); it != checkBox.cend(); ++it){
//      IngredienteCheckBox* elemento = dynamic_cast<IngredienteCheckBox*>(*it);
//      if(elemento->isChecked()){
//        QLabel* i = new QLabel(elemento->text(),visualizationWrapper);
//        dynamic_cast<QVBoxLayout*>(visualizationWrapper->layout())->addWidget(i);
//      }
//    }
//  }
//  else{
//  }
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

void MainWindow::aggiornaInventario(pacchetto * p){
  if(dynamic_cast<pacchettoBevanda*>(p)){
    TabellaComposita* tabBevande =
        findChild<TabellaComposita*>("tabBevandeInventario");
    tabBevande->inserisciElemento(p);
  }
  else{
    TabellaComposita* tabIngredienti =
        findChild<TabellaComposita*>("tabIngredientiInventario");
    tabIngredienti->inserisciElemento(p);
  }
}

void MainWindow::visualizzaInventario(){
    QList<pacchetto*>* inventario = controller->recuperaInventario();
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
        aggiornaInventario(*it);
    }
    delete inventario;
}

void MainWindow::aggiornaMenu(pacchetto* p){
  TabellaComposita* tab;
  if(dynamic_cast<pacchettoPizza*>(p))
    tab = findChild<TabellaComposita*>("tabPizzeMenu");
  else
    tab = findChild<TabellaComposita*>("tabBevandeMenu");

  tab->inserisciElemento(p);
}

void MainWindow::visualizzaMenu(){
  QList<pacchetto*>* menu = controller->recuperaMenu();
  for(auto it = menu->constBegin(); it != menu->constEnd(); ++it){
      aggiornaMenu(*it);
  }
  delete menu;
}

void MainWindow::mostraErrore(const QString & messaggio){
  QErrorMessage* errorDialog = new QErrorMessage(this);
  errorDialog->showMessage(messaggio);
}
