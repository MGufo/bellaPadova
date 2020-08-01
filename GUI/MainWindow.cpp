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
  setMinimumSize(QSize(900,600));
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
    QWidget* wrapper = findChild<QWidget*>("ingredientiCheckBoxWrapper");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
      if(dynamic_cast<pacchettoIngrediente*>(*it) &&
         !dynamic_cast<pacchettoFarina*>(*it)){
        QWidget* i = new IngredienteCheckBox
            (QString::fromStdString((*it)->nome),(*it)->ID,wrapper);
        dynamic_cast<QVBoxLayout*>(wrapper->layout())->addWidget(i);
      }
    }
  }
  else{
    QWidget* wrapper = findChild<QWidget*>("bevandeRadioButtonWrapper");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
      pacchettoBevanda* b = dynamic_cast<pacchettoBevanda*>(*it);
      if(b){
        QWidget* completeRadio = new QWidget(wrapper);
        QHBoxLayout* completeRadioLayout = new QHBoxLayout(completeRadio);
        QWidget* bb = new BevandaRadioButton(
              b->ID,QString::fromStdString(b->nome),b->prezzo,b->capacita,
              (b->tipo? "Lattina" : "Bottiglia"),completeRadio);
        QLabel* id = new QLabel(QString::fromStdString(std::to_string(b->ID)));
        QLabel* prezzo = new QLabel(
              QString::fromStdString(to_string_with_precision(b->prezzo)));
        QLabel* capacit = new QLabel(
              QString::fromStdString(to_string_with_precision(b->capacita)));
        QLabel* tipologia = new QLabel((b->tipo? "Lattina" : "Bottiglia"));

        completeRadioLayout->addWidget(bb);
        completeRadioLayout->addWidget(id);
        completeRadioLayout->addWidget(prezzo);
        completeRadioLayout->addWidget(capacit);
        completeRadioLayout->addWidget(tipologia);

        dynamic_cast<QVBoxLayout*>(wrapper->layout())->addWidget(completeRadio);
      }
    }
  }
  delete inventario;
}

void MainWindow::visualizzaElementiCheckatiInWizard(bool option_pizza) const{
  if(option_pizza){
    QWidget* checkboxWrapper = findChild<QWidget*>("ingredientiCheckBoxWrapper");
    auto checkBox = checkboxWrapper->children();

    QWidget* visualizationWrapper =
        findChild<QWidget*>("ingredientiVisualizationWrapper");

    //eliminazione dei vecchi ingredienti se presenti nel layout
    QLayoutItem* item = nullptr;
    while((item = visualizationWrapper->layout()->takeAt(1)) != NULL){
      //IngredienteCheckBox* p = dynamic_cast<IngredienteCheckBox*>(item->widget());
      //std::cout << p->text().toStdString() << " " << p->isChecked() << std::endl;
      delete item->widget();
      delete item;
    }
    //riempimento del layout con gli ingredienti aggiornati
    for(auto it = ++(checkBox.cbegin()); it != checkBox.cend(); ++it){
      IngredienteCheckBox* elemento = dynamic_cast<IngredienteCheckBox*>(*it);
      if(elemento->isChecked()){
        QLabel* i = new QLabel(elemento->text(),visualizationWrapper);
        dynamic_cast<QVBoxLayout*>(visualizationWrapper->layout())->addWidget(i);
      }
    }
  }
  else{
  }
}
	
void MainWindow::closeEvent(QCloseEvent *event){
  if(!controller->canQuit()){
    QMessageBox* savePrompt = new QMessageBox(this);
    savePrompt->setText("The document has been modified.");
    savePrompt->setInformativeText("Do you want to save your changes?");
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

void MainWindow::visualizzaInventario(){
    QList<pacchetto*>* inventario = controller->recuperaInventario();
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
        aggiornaInventario(*it);
    }
    delete inventario;
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
    TabellaComposita* tabBevande = findChild<TabellaComposita*>("tabBevande");
    tabBevande->inserisciElemento(p);
  }
  else{
    TabellaComposita* tabIngredienti =
        findChild<TabellaComposita*>("tabIngredienti");
    tabIngredienti->inserisciElemento(p);
  }
}

void MainWindow::mostraErrore(const QString & messaggio){
  QErrorMessage* errorDialog = new QErrorMessage(this);
  errorDialog->showMessage(messaggio);
}
