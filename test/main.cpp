#include <QDate>
#include <QApplication>
#include <iostream>
#include <string>
#include "../core/pizzeria.h"
#include <stdexcept>
#include "../GUI/MainWindow.h"
using std::string;

int main(int argc, char* argv[]) {

  QApplication app(argc, argv);
  Pizzeria bellaPadova("../progettoP2/comande.json", "../progettoP2/risorse.json");
  Controller controller(&bellaPadova,
                        bellaPadova.getIdComande(),
                        bellaPadova.getIdRisorse());
  MainWindow view(&controller);
  controller.setView(&view);
  view.show();
  controller.caricaRisorse();
  return app.exec();
}
