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

void Controller::caricaComande(){
  modello->caricaComande();
  // TODO: Aggiornamento vista
}

void Controller::caricaRisorse(){
  try{
    modello->caricaRisorse();
  } catch (std::invalid_argument *ecc) {
    emit mostraErrore(QString(ecc->what()));
  }
  // TODO: Aggiornamento vista
}

void Controller::salvaComande() const{
  try{
    modello->salvaComande();
  } catch (std::invalid_argument *ecc) {
    emit mostraErrore(QString(ecc->what()));
  }
}

void Controller::salvaRisorse() const{}
