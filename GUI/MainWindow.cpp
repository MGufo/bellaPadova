#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent): QWidget(parent){
  mainLayout = new QVBoxLayout(this);
  Header* header = new Header(this);
  Menu* menu = new Menu(this);
  setStylePizzeria();
  mainLayout->addWidget(header);
  mainLayout->addWidget(menu);
  setLayout(mainLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::setStylePizzeria() {
  mainLayout->setSpacing(0);
  mainLayout->setContentsMargins(0,0,0,0);
  setMinimumSize(QSize(900,600));
  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
