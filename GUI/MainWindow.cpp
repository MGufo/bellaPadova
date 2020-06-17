#include "MainWindow.h"
#include <iostream>
#include <QList>

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
  QAction* caricaComande = new QAction("Comande", category_Load);
  QAction* caricaMenu = new QAction("Menu", category_Load);
  QAction* caricaInventario = new QAction("Inventario", category_Load);
  QAction* salvaComande = new QAction("Comande", category_Save);
  QAction* salvaMenu = new QAction("Menu", category_Save);
  QAction* salvaInventario = new QAction("Inventario", category_Save);

  connect(caricaComande, SIGNAL(triggered()), controller, SLOT(caricaComande()));
  connect(caricaMenu, SIGNAL(triggered()), controller, SLOT(caricaMenu()));
  connect(caricaInventario, SIGNAL(triggered()), controller, SLOT(caricaInventario()));
  connect(salvaComande, SIGNAL(triggered()), controller, SLOT(salvaComande()));
  connect(salvaMenu, SIGNAL(triggered()), controller, SLOT(salvaMenu()));
  connect(salvaInventario, SIGNAL(triggered()), controller, SLOT(salvaInventario()));

  connect(file_Exit, SIGNAL(triggered()), this, SLOT(close()));

  category_File->addAction(file_Exit);
  category_Load->addAction(caricaComande);
  category_Load->addAction(caricaMenu);
  category_Load->addAction(caricaInventario);
  category_Save->addAction(salvaComande);
  category_Save->addAction(salvaMenu);
  category_Save->addAction(salvaInventario);

  menuBar->addMenu(category_File);
  menuBar->addMenu(category_Load);
  menuBar->addMenu(category_Save);

  return menuBar;
}

// SLOT
void MainWindow::calcoloFatturato(const QDate& inizio, const QDate& fine){
  controller->calcoloFatturato(inizio, fine);
}

void MainWindow::aggiornaContabilizzazione(double guadagno){
  if(guadagno > 0)
    findChild<QLineEdit*>("mGuadagno")->setStyleSheet("color: darkgreen;");
  else
    findChild<QLineEdit*>("mGuadagno")->setStyleSheet("color: darkred;");
  findChild<QLineEdit*>("mGuadagno")->clear();
  findChild<QLineEdit*>("mGuadagno")->insert(QString::number(guadagno));
}
