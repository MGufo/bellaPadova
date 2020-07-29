#include "GUI/controller.h"

//TODO: settare idComande e idRisorse a zero dopo aver implementato correttamente I/O da file
Controller::Controller(Pizzeria* bellaPadova, uint idC, uint idR,
                       QObject* parent) :
  QObject(parent), modello(bellaPadova), idComande(idC), idRisorse(idR) {
}

void Controller::setView(MainWindow *v){
  vista = v;
}


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}

void Controller::creaNuovoConsumabile(pacchetto* pC){
    Consumabile* pConsumabile = nullptr;
    pC->ID = ++idRisorse;
    if(dynamic_cast<pacchettoBevanda*>(pC)){
        pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
        if(ptr->tipo == true){
            pConsumabile = new Lattina(ptr->ID,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
        else{
            pConsumabile = new Bottiglia(ptr->ID,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
    }
    else if(dynamic_cast<pacchettoFarina*>(pC)){
        pacchettoFarina* ptr = dynamic_cast<pacchettoFarina*>(pC);
        pConsumabile = new Farina(ptr->ID,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale,ptr->tipologia);
    }
    else if(dynamic_cast<pacchettoIngrediente*>(pC)){
        pacchettoIngrediente* ptr = dynamic_cast<pacchettoIngrediente*>(pC);
        pConsumabile = new Ingrediente(ptr->ID,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale);
    }
    modello->inserisciConsumabile(pConsumabile);
    vista->aggiornaInventario(pC);
}

void Controller::modificaConsumabile(pacchetto * pC){
    Consumabile* pConsumabile = nullptr;
    if(dynamic_cast<pacchettoBevanda*>(pC)){
        pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
        if(ptr->tipo == true){
            pConsumabile = new Lattina(ptr->ID,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
        else{
            pConsumabile = new Bottiglia(ptr->ID,ptr->nome,ptr->disponibilita,ptr->prezzo,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->capacita);
        }
    }
    else if(dynamic_cast<pacchettoFarina*>(pC)){
        pacchettoFarina* ptr = dynamic_cast<pacchettoFarina*>(pC);
        pConsumabile = new Farina(ptr->ID,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale,ptr->tipologia);
    }
    else if(dynamic_cast<pacchettoIngrediente*>(pC)){
        pacchettoIngrediente* ptr = dynamic_cast<pacchettoIngrediente*>(pC);
        pConsumabile = new Ingrediente(ptr->ID,ptr->nome,ptr->disponibilita,ptr->quantita,ptr->costo,ptr->dataAcquisto,ptr->locale);
    }
    Risorsa* temp = modello->trovaRisorsa(pC->ID);
    Consumabile* vecchioConsumabile = dynamic_cast<Consumabile*>(temp);
    modello->modificaConsumabile(vecchioConsumabile,pConsumabile);
}

QList<pacchetto*>* Controller::recuperaInventario() const{
    auto inventario = modello->getInventario();
    pacchetto* p = nullptr;
    QList<pacchetto*>* pacchetti = new QList<pacchetto*>();
    for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it){
        if(dynamic_cast<Lattina*>(*it)){
            Lattina* pL = dynamic_cast<Lattina*>(*it);
            p = new pacchettoBevanda(pL->getIdRisorsa(),pL->getNome(),pL->getDisponibilita(),pL->getPrezzoBase(),pL->getQuantita(),pL->getCosto(),pL->getDataAcquisto(),pL->getCapacita(),true);
        }
        if(dynamic_cast<Bottiglia*>(*it)){
            Bottiglia* pB = dynamic_cast<Bottiglia*>(*it);
            p = new pacchettoBevanda(pB->getIdRisorsa(),pB->getNome(),pB->getDisponibilita(),pB->getPrezzoBase(),pB->getQuantita(),pB->getCosto(),pB->getDataAcquisto(),pB->getCapacita(),false);
        }
        else if(dynamic_cast<Farina*>(*it)){
            Farina* pF = dynamic_cast<Farina*>(*it);
            p = new pacchettoFarina(pF->getIdRisorsa(),pF->getNome(),pF->getDisponibilita(),pF->getQuantita(),pF->getCosto(),pF->getDataAcquisto(),pF->isLocal(),pF->getTipoFarina());
        }
        else if(dynamic_cast<Ingrediente*>(*it)){
            Ingrediente* pI = dynamic_cast<Ingrediente*>(*it);
            p = new pacchettoIngrediente(pI->getIdRisorsa(),pI->getNome(),pI->getDisponibilita(),pI->getQuantita(),pI->getCosto(),pI->getDataAcquisto(),pI->isLocal());
        }
        pacchetti->push_back(p);
    }
    return pacchetti;
}

void Controller::caricaComande(){
  try{
    modello->caricaComande();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  // TODO: Aggiornamento vista
}

void Controller::caricaRisorse(){
  try{
    modello->caricaRisorse();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  // TODO: Aggiornamento vista
}

void Controller::salvaComande() const{
  try{
    modello->salvaComande();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
}

void Controller::salvaRisorse() const{
  try{
    modello->salvaRisorse();
  } catch (std::logic_error *ecc) {
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
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }

}
