#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget* parent): QWidget(parent){
  mainLayout = new QVBoxLayout(this);
  Header* header = new Header(this);
  Comande* comande = new Comande();
  Menu* menu = new Menu();
  Inventario* inventario = new Inventario();
  Contabilizzazione* contabilizzazione = new Contabilizzazione();
  QTabWidget* content = new QTabWidget(this);

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
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

QMenuBar* MainWindow::drawMenubar() const{
  QMenuBar* menuBar = new QMenuBar();
  QMenu* category_File = new QMenu("File", menuBar);
  QMenu* category_Load = new QMenu("Carica", menuBar);
  QMenu* category_Save = new QMenu("Salva", menuBar);
  QAction* file_Exit = new QAction("Esci", category_File);
  QAction* load_Menu = new QAction("Menu", category_Load);
  QAction* load_Inventario = new QAction("Inventario", category_Load);
  QAction* save_Menu = new QAction("Menu", category_Save);
  QAction* save_Inventario = new QAction("Inventario", category_Save);

  connect(file_Exit, SIGNAL(triggered()), this, SLOT(close()));

  category_File->addAction(file_Exit);
  category_Load->addAction(load_Menu);
  category_Load->addAction(load_Inventario);
  category_Save->addAction(save_Menu);
  category_Save->addAction(save_Inventario);

  menuBar->addMenu(category_File);
  menuBar->addMenu(category_Load);
  menuBar->addMenu(category_Save);

  return menuBar;
}

// SLOT
void MainWindow::calcoloFatturato(const QDate& inizio, const QDate& fine){
  controller->calcoloFatturato(inizio, fine);
}

void MainWindow::aggiornaContabilizzazione(double tmp){
//  QLabel* x = findChild<QLabel*>("mGuadagno");
//  std::cout << x->text().toStdString() << std::endl;
//  (this->findChild<QLabel*>("mGuadagno"))->setNum(tmp);
}