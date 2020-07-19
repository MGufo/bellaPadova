#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova), idComande(0), idRisorse(0) {
}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}

void Controller::creaNuovoConsumabile(pacchetto* pC){
    Consumabile* pConsumabile = nullptr;
    if(dynamic_cast<pacchettoBevanda*>(pC)){
        pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
        if(ptr->tipo == true){
            pConsumabile = new Lattina(++idRisorse,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
        else{
            pConsumabile = new Bottiglia(++idRisorse,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
    }
    else if(dynamic_cast<pacchettoFarina*>(pC)){
        pacchettoFarina* ptr = dynamic_cast<pacchettoFarina*>(pC);
        pConsumabile = new Farina(++idRisorse,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale,ptr->tipologia);
    }
    else if(dynamic_cast<pacchettoIngrediente*>(pC)){
        pacchettoIngrediente* ptr = dynamic_cast<pacchettoIngrediente*>(pC);
        pConsumabile = new Ingrediente(++idRisorse,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale);
    }
    modello->inserisciConsumabile(pConsumabile);
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
  try{
    modello->salvaRisorse();
  } catch (std::invalid_argument *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
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
