#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova) {
    //TODO: Implementare funzione che chiede al model di leggere
    //i currentID e ritornarli
}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}

void Controller::creaNuovoConsumabile(pacchetto* pC){
  pacchettoBevandaC* x = dynamic_cast<pacchettoBevandaC*>(pC);
  std::cout << x->nome;
}

void Controller::caricaComande(){
  try{
    modello->caricaComande();
  } catch (std::invalid_argument *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  // TODO: Aggiornamento vista
}

void Controller::caricaRisorse(){
  try{
    modello->caricaRisorse();
  } catch (std::invalid_argument *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  // TODO: Aggiornamento vista
}

void Controller::salvaComande() const{
  try{
    modello->salvaComande();
  } catch (std::invalid_argument *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
}

void Controller::salvaRisorse() const{

}

void Controller::modificaComande(){
    //modello->modificaComanda();
}

void Controller::modificaRisorse(){
    //modello->modificaArticolo();
  try{
    modello->salvaRisorse();
  } catch (std::invalid_argument *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }

}
