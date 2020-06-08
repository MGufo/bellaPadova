#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova) {}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}
