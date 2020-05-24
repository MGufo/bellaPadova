#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent): QWidget(parent){
  mainLayout = new QVBoxLayout(this);
  navBar = new QHBoxLayout(this);
  addMenu();
  addNavBar();
  setStyle();
  setLayout(mainLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::setStyle() {
  setMinimumSize(QSize(900,600));
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void MainWindow::addMenu(){
  QMenuBar *menuBar = new QMenuBar(this);
  QMenu *menu = new QMenu("File", menuBar);
  QAction* exit = new QAction("Exit", menu);
  connect(exit, SIGNAL(triggered()), this, SLOT(close()));
  menu->addAction(exit);
  // Aggiunta Menu alla MenuBar
  menuBar->addMenu(menu);
  // Aggiunta MenuBar al layout
  mainLayout->addWidget(menuBar);
}

void MainWindow::addNavBar(){
  QPushButton* comandeB = new QPushButton("Comande", this);
  comandeB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  navBar->addWidget(comandeB);
  QPushButton* menuB = new QPushButton("Menu", this);
  menuB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  navBar->addWidget(menuB);
  QPushButton* inventarioB = new QPushButton("Inventario", this);
  inventarioB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  navBar->addWidget(inventarioB);
  QPushButton* contabilizzazioneB = new QPushButton("Contabilizzazione", this);
  contabilizzazioneB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  navBar->addWidget(contabilizzazioneB);
}

