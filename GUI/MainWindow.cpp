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
  QMenu* category_Load = new QMenu("Carica", menuBar);
  QMenu* category_Save = new QMenu("Salva", menuBar);
  QAction* file_Exit = new QAction("Esci", category_File);
  QAction* caricaRisorse = new QAction("Inventario e Menu", category_Load);
  QAction* salvaComande = new QAction("Comande", category_Save);
  QAction* salvaRisorse = new QAction("Inventario e Menu", category_Save);

  connect(caricaRisorse, SIGNAL(triggered()), controller, SLOT(caricaRisorse()));
  connect(salvaComande, SIGNAL(triggered()), controller, SLOT(salvaComande()));
  connect(salvaRisorse, SIGNAL(triggered()), controller, SLOT(salvaRisorse()));

  connect(file_Exit, SIGNAL(triggered()), this, SLOT(close()));

  category_File->addAction(file_Exit);
  category_Load->addAction(caricaRisorse);
  category_Save->addAction(salvaComande);
  category_Save->addAction(salvaRisorse);

  menuBar->addMenu(category_File);
  menuBar->addMenu(category_Load);
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

void MainWindow::visualizzaIngredientiInWizard() const{
    QList<pacchetto*>* inventario = controller->recuperaInventario();
    //TODO: sistemo il recupero del puntatore al wrapper delle checkbox
    QWidget* wrapper = findChild<QWidget*>("ingredientiCheckBoxWrapper");
    for(auto it = inventario->constBegin(); it != inventario->constEnd(); ++it){
        if(dynamic_cast<pacchettoIngrediente*>(*it)){
            IngredientCheckBox* i = new IngredientCheckBox(QString::fromStdString((*it)->nome),(*it)->ID,wrapper);
            std::cout << (*it)->nome << (*it)->ID << std::endl;
            wrapper->layout()->addWidget(i);
            wrapper->layout()->addWidget(new QLabel("daghe"));
        }
    }
    delete inventario;
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
        TabellaComposita* tabIngredienti = findChild<TabellaComposita*>("tabIngredienti");
        tabIngredienti->inserisciElemento(p);
    }
}

void MainWindow::mostraErrore(const QString & messaggio){
  QErrorMessage* errorDialog = new QErrorMessage(this);
  errorDialog->showMessage(messaggio);
}
