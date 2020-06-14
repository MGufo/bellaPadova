#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova) {}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}


void Controller::caricaComande(){
}

void Controller::caricaMenu(){

}

void Controller::caricaInventario(){

}

void Controller::salvaComande() const{
  modello->salva();
}

void Controller::salvaMenu() const{
  modello->salva();
}

void Controller::salvaInventario() const{
  modello->salva();
}
