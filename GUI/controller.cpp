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
    if(dynamic_cast<pacchettoBevanda*>(pC)){
        pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
        if(ptr->tipo == true){
            Lattina* pLattina = new Lattina(++idRisorse,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
        else{
            //Bottiglia* pBottiglia = new Bottiglia();
        }
    }
    else if(dynamic_cast<pacchettoFarina*>(pC)){
        pacchettoFarina* pFarina = dynamic_cast<pacchettoFarina*>(pC);
        //...
    }
    else if(dynamic_cast<pacchettoIngrediente*>(pC)){
        pacchettoIngrediente* pIngrediente = dynamic_cast<pacchettoIngrediente*>(pC);
        //...
    }
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
