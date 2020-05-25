#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent): QWidget(parent){
  mainLayout = new QVBoxLayout(this);
  //navBar = new QHBoxLayout();

  Header* header = new Header(this);
  //drawHeader();
  //addMenu();
  setStylePizzeria();
  mainLayout->addWidget(header);
  setLayout(mainLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::setStylePizzeria() {
  setMinimumSize(QSize(1200,800));
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
  QFile file(":/resources/GUI/style.css");
  file.open(QFile::ReadOnly);
  QString style = QLatin1String(file.readAll());
  setStyleSheet(style);
}

//void MainWindow::addMenu(){
//  QMenuBar *menuBar = new QMenuBar(this);
//  QMenu *menu = new QMenu("File", menuBar);
//  QAction* exit = new QAction("Exit", menu);
//  connect(exit, SIGNAL(triggered()), this, SLOT(close()));
//  menu->addAction(exit);
//  // Aggiunta Menu alla MenuBar
//  menuBar->addMenu(menu);
//  // Aggiunta MenuBar al layout
//  mainLayout->addWidget(menuBar);
//}

//void MainWindow::addNavBar(){
//  QPushButton* comandeB = new QPushButton("Comande", this);
//  comandeB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
//  navBar->addWidget(comandeB);
//  QPushButton* menuB = new QPushButton("Menu", this);
//  menuB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
//  navBar->addWidget(menuB);
//  QPushButton* inventarioB = new QPushButton("Inventario", this);
//  inventarioB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
//  navBar->addWidget(inventarioB);
//  QPushButton* contabilizzazioneB = new QPushButton("Contabilizzazione", this);
//  contabilizzazioneB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
//  navBar->addWidget(contabilizzazioneB);
//}

