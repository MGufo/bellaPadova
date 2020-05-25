#include "header.h"
#include <iostream>

Header::Header(QWidget *parent) : QWidget(parent){
  // layout dell'header
  mainHeader = new QVBoxLayout(this);
  // layout della navbar
  drawMenuBar();
  navBarLayout = new QHBoxLayout();
  drawNavBar();
  // aggiunta sotto-layout navBar al layout header
  mainHeader->addLayout(navBarLayout);
  // applicazione layout header
  setLayout(mainHeader);
}

void Header::drawNavBar(){
  QPushButton* comandeB = new QPushButton("Comande", this);
  comandeB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  navBarLayout->addWidget(comandeB);
  QPushButton* menuB = new QPushButton("Menu", this);
  menuB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  navBarLayout->addWidget(menuB);
  QPushButton* inventarioB = new QPushButton("Inventario", this);
  inventarioB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  navBarLayout->addWidget(inventarioB);
  QPushButton* contabilizzazioneB = new QPushButton("Contabilizzazione", this);
  contabilizzazioneB->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  navBarLayout->addWidget(contabilizzazioneB);
}

void Header::drawMenuBar(){
  QMenuBar* menuBar = new QMenuBar(this);
  menuBar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  QMenu* category_File = new QMenu("File", menuBar);
  QMenu* category_Load = new QMenu("Carica", menuBar);
  QMenu* category_Save = new QMenu("Salva", menuBar);
  QAction* file_Exit = new QAction("Esci", category_File);
  QAction* load_Menu = new QAction("Menu", category_Load);
  QAction* load_Inventario = new QAction("Inventario", category_Load);
  QAction* save_Menu = new QAction("Menu", category_Save);
  QAction* save_Inventario = new QAction("Inventario", category_Save);

  connect(file_Exit, SIGNAL(triggered()), parentWidget(), SLOT(close()));

  category_File->addAction(file_Exit);
  category_Load->addAction(load_Menu);
  category_Load->addAction(load_Inventario);
  category_Save->addAction(save_Menu);
  category_Save->addAction(save_Inventario);

  menuBar->addMenu(category_File);
  menuBar->addMenu(category_Load);
  menuBar->addMenu(category_Save);

  mainHeader->addWidget(menuBar);
}
