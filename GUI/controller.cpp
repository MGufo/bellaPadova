#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, uint idC, uint idR,
                       QObject* parent) :
  QObject(parent), modello(bellaPadova), idComande(idC), idRisorse(idR) {
}

void Controller::setView(MainWindow *v){ vista = v; }


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}

void Controller::creaNuovoConsumabile(pacchetto* pC){
  Consumabile* pConsumabile = nullptr;
  pC->ID = ++idRisorse;
  if(dynamic_cast<pacchettoBevanda*>(pC)){
    pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
    if(ptr->tipo == true){
      pConsumabile = new Lattina(ptr->ID,ptr->nome,ptr->disponibilita,
                                 ptr->prezzo,ptr->quantita,ptr->costo,
                                 ptr->dataAcquisto,ptr->capacita);
    }
    else{
      pConsumabile = new Bottiglia(ptr->ID,ptr->nome,ptr->disponibilita,
                                   ptr->prezzo,ptr->quantita,ptr->costo,
                                   ptr->dataAcquisto,ptr->capacita);
    }
  }
  else if(dynamic_cast<pacchettoFarina*>(pC)){
    pacchettoFarina* ptr = dynamic_cast<pacchettoFarina*>(pC);
    pConsumabile = new Farina(ptr->ID,ptr->nome,ptr->disponibilita,
                              ptr->quantita,ptr->costo,ptr->dataAcquisto,
                              ptr->locale,ptr->tipologia);
  }
  else if(dynamic_cast<pacchettoIngrediente*>(pC)){
    pacchettoIngrediente* ptr = dynamic_cast<pacchettoIngrediente*>(pC);
    pConsumabile = new Ingrediente(ptr->ID,ptr->nome,ptr->disponibilita,
                                   ptr->quantita,ptr->costo,ptr->dataAcquisto,
                                   ptr->locale);
  }
  modello->inserisciConsumabile(pConsumabile);
  risorseSalvate = false;
  vista->aggiornaInventario(pC);
}

void Controller::modificaConsumabile(pacchetto * pC){
  Consumabile* pConsumabile = nullptr;
  if(dynamic_cast<pacchettoBevanda*>(pC)){
    pacchettoBevanda* ptr = dynamic_cast<pacchettoBevanda*>(pC);
    if(ptr->tipo == true){
      pConsumabile = new Lattina(ptr->ID,ptr->nome,ptr->disponibilita,
                                 ptr->prezzo,ptr->quantita,ptr->costo,
                                 ptr->dataAcquisto,ptr->capacita);
    }
    else{
      pConsumabile = new Bottiglia(ptr->ID,ptr->nome,ptr->disponibilita,
                                   ptr->prezzo,ptr->quantita,ptr->costo,
                                   ptr->dataAcquisto,ptr->capacita);
    }
  }
  else if(dynamic_cast<pacchettoFarina*>(pC)){
    pacchettoFarina* ptr = dynamic_cast<pacchettoFarina*>(pC);
    pConsumabile = new Farina(ptr->ID,ptr->nome,ptr->disponibilita,
                              ptr->quantita,ptr->costo,ptr->dataAcquisto,
                              ptr->locale,ptr->tipologia);
  }
  else if(dynamic_cast<pacchettoIngrediente*>(pC)){
    pacchettoIngrediente* ptr = dynamic_cast<pacchettoIngrediente*>(pC);
    pConsumabile = new Ingrediente(ptr->ID,ptr->nome,ptr->disponibilita,
                                   ptr->quantita,ptr->costo,ptr->dataAcquisto,
                                   ptr->locale);
  }
  Risorsa* temp = modello->trovaRisorsa(pC->ID);
  Consumabile* vecchioConsumabile = dynamic_cast<Consumabile*>(temp);
  modello->modificaConsumabile(vecchioConsumabile,pConsumabile);
  risorseSalvate = false;
  //non serve aggiornamento della vista
  //vista->visualizzaInventario();
}

void Controller::eliminaConsumabile(uint id){
  Risorsa* daEliminare = modello->trovaRisorsa(id);
  modello->rimuoviConsumabile(dynamic_cast<Consumabile*>(daEliminare));
  risorseSalvate = false;
  //non serve aggiornamento della vista (effettuato dallo slot di tabellaComposita)
  //vista->visualizzaInventario();
}

QList<pacchetto*>* Controller::recuperaInventario() const{
  auto inventario = modello->getInventario();
  pacchetto* p = nullptr;
  QList<pacchetto*>* pacchetti = new QList<pacchetto*>();
  for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it){
    if(dynamic_cast<Lattina*>(*it)){
      Lattina* pL = dynamic_cast<Lattina*>(*it);
      p = new pacchettoBevanda(pL->getIdRisorsa(),pL->getNome(),
                               pL->getDisponibilita(),pL->getPrezzoBase(),
                               pL->getQuantita(),pL->getCosto(),
                               pL->getDataAcquisto(),pL->getCapacita(),true);
    }
    if(dynamic_cast<Bottiglia*>(*it)){
      Bottiglia* pB = dynamic_cast<Bottiglia*>(*it);
      p = new pacchettoBevanda(pB->getIdRisorsa(),pB->getNome(),
                               pB->getDisponibilita(),pB->getPrezzoBase(),
                               pB->getQuantita(),pB->getCosto(),
                               pB->getDataAcquisto(),pB->getCapacita(),false);
    }
    else if(dynamic_cast<Farina*>(*it)){
      Farina* pF = dynamic_cast<Farina*>(*it);
      p = new pacchettoFarina(pF->getIdRisorsa(),pF->getNome(),
                              pF->getDisponibilita(),pF->getQuantita(),
                              pF->getCosto(),pF->getDataAcquisto(),pF->isLocal(),
                              pF->getTipoFarina());
    }
    else if(dynamic_cast<Ingrediente*>(*it)){
      Ingrediente* pI = dynamic_cast<Ingrediente*>(*it);
      p = new pacchettoIngrediente(pI->getIdRisorsa(),pI->getNome(),
                                   pI->getDisponibilita(),pI->getQuantita(),
                                   pI->getCosto(),pI->getDataAcquisto(),
                                   pI->isLocal());
    }
    pacchetti->push_back(p);
  }
  return pacchetti;
}

void Controller::creaNuovoArticolo(pacchetto *){
    //TODO: chiamare modello->inserisciArticolo() dentro a un blocco try-catch
}

QList<pacchetto *>* Controller::recuperaMenu() const{
  auto menu = modello->getMenu();
  pacchetto* p = nullptr;
  QList<pacchetto*>* pacchetti = new QList<pacchetto*>();
  for(auto it = menu.const_begin(); it != menu.const_end(); ++it){
    if(dynamic_cast<Lattina*>(*it)){
      Lattina* pL = dynamic_cast<Lattina*>(*it);
      p = new pacchettoBevanda(pL->getIdRisorsa(),pL->getNome(),
                               pL->getDisponibilita(),pL->getPrezzoBase(),
                               pL->getQuantita(),pL->getCosto(),
                               pL->getDataAcquisto(),pL->getCapacita(),true);
    }
    if(dynamic_cast<Bottiglia*>(*it)){
      Bottiglia* pB = dynamic_cast<Bottiglia*>(*it);
      p = new pacchettoBevanda(pB->getIdRisorsa(),pB->getNome(),
                               pB->getDisponibilita(),pB->getPrezzoBase(),
                               pB->getQuantita(),pB->getCosto(),
                               pB->getDataAcquisto(),pB->getCapacita(),false);
    }
    else if(dynamic_cast<Pizza*>(*it)){
      Pizza* pF = dynamic_cast<Pizza*>(*it);
      p = new pacchettoPizza(pF->getIdRisorsa(), pF->getNome(),
                             pF->getDisponibilita(), pF->getPrezzo());
      auto listaIngr = pF->getComposizione();
      for(auto it = listaIngr->const_begin(); it != listaIngr->const_end();
          ++it){
        Ingrediente* i = dynamic_cast<Ingrediente*>(*it);
        pacchettoIngrediente* pI =
            new pacchettoIngrediente(i->getIdRisorsa(),i->getNome(),
                                     i->getDisponibilita(),i->getQuantita(),
                                     i->getCosto(),i->getDataAcquisto(),
                                     i->isLocal());
        (dynamic_cast<pacchettoPizza*>(p))->ingredienti[pI->ID] = pI->nome;
      }
    }
    pacchetti->push_back(p);
  }
  return pacchetti;
}

QList<pacchetto *> *Controller::recuperaComande() const{
  QList<pacchettoComanda*>* pacchetti = new QList<pacchettoComanda*>();
  auto comande = modello->getComande();
  for(auto it = comande.const_begin(); it != comande.const_end(); ++it){
    Comanda* c = *it;
    pacchettoComanda* pC =
        new pacchettoComanda(c->getIdComanda(), c->getCliente().getNome(),
                             c->getCliente().getIndirizzo(),
                             c->getCliente().getTelefono(),
                             c->getOraConsegna().toString().toStdString());
    // TODO : Riempire mappa ordinazione del pacchetto
    pacchetti->push_back(pC);
  }
}

bool Controller::canQuit() const { return (comandeSalvate && risorseSalvate); }

void Controller::caricaComande(){
  try{
    modello->caricaComande();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  vista->visualizzaComande();
}

void Controller::caricaRisorse(){
  try{
    modello->caricaRisorse();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  vista->visualizzaInventario();
  vista->visualizzaMenu();
}

void Controller::salvaComande(){
  try{
    modello->salvaComande();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  comandeSalvate = true;
}

void Controller::salvaRisorse(){
  try{
    modello->salvaRisorse();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  risorseSalvate = true;
}

void Controller::modificaComande(){
  //modello->modificaComanda();
  comandeSalvate = false;
}

void Controller::modificaRisorse(){
  //modello->modificaArticolo();
  try{
    modello->salvaRisorse();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
  risorseSalvate = false;
}

void Controller::saveAndExit(){
  if(!comandeSalvate) modello->salvaComande();
  if(!risorseSalvate) modello->salvaRisorse();
}
