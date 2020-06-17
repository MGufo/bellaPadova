#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova) {
    //load(comande);
    //idComande = ultimaComanda->getId();
    //load(risorse);
    //idRisorse = ultimaRisorsaAggiunta->getId();
}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}


void Controller::caricaComande(){}

void Controller::caricaRisorse(){}

void Controller::salvaComande() const{}

void Controller::salvaRisorse() const{}
