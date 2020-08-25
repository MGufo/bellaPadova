#include "GUI/controller.h"
#include <iostream>

Controller::Controller(Pizzeria* bellaPadova, uint idC, uint idR,
                       QObject* parent) :
  QObject(parent), modello(bellaPadova), idComande(idC), idRisorse(idR) {
}

void Controller::setView(MainWindow *v){ vista = v; }


void Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  vista->aggiornaContabilizzazione(modello->contabilizzazione(inizio, fine));
}

void Controller::creaNuovoArticolo(pacchettoArticolo* pA){
    Articolo* pArticolo = nullptr;
    if(dynamic_cast<pacchettoBevanda*>(pA)){
      //recupero la bevanda che voglio inserire nel menu dall'inventario
      Risorsa* r = modello->trovaRisorsa(pA->ID);
      pArticolo = dynamic_cast<Articolo*>(r);
      //creo pacchetto per aggiornare la vista
      Bevanda* pBevanda = dynamic_cast<Bevanda*>(r);
      pA->nome = pBevanda->getNome();
      pA->disponibilita = pBevanda->getDisponibilita();
      dynamic_cast<pacchettoBevanda*>(pA)->prezzo = pBevanda->getPrezzoBase();
      dynamic_cast<pacchettoBevanda*>(pA)->quantita = pBevanda->getQuantita();
      dynamic_cast<pacchettoBevanda*>(pA)->costo = pBevanda->getCosto();
      dynamic_cast<pacchettoBevanda*>(pA)->dataAcquisto = pBevanda->getDataAcquisto();
      dynamic_cast<pacchettoBevanda*>(pA)->capacita = pBevanda->getCapacita();
      dynamic_cast<pacchettoBevanda*>(pA)->tipo = (dynamic_cast<Lattina*>(pBevanda) ? true : false);
    }
    else if(dynamic_cast<pacchettoPizza*>(pA)){
      pA->ID = ++idRisorse;
      pacchettoPizza* ptr = dynamic_cast<pacchettoPizza*>(pA);
      pArticolo = new Pizza(ptr->ID,ptr->nome,ptr->disponibilita,ptr->prezzo);
      //inserisco gli ingredienti e setto la farina
      Pizza* pPizza = dynamic_cast<Pizza*>(pArticolo);
      Lista<Ingrediente*> ingrePizza;
      for(auto it = ptr->ingredienti.cbegin() ; it != ptr->ingredienti.cend() ; ++it){
          Risorsa* r = modello->trovaRisorsa((*it).first);
          if(dynamic_cast<Farina*>(r))
              pPizza->setFarina(dynamic_cast<Farina*>(r));
          else
              ingrePizza.push_back(dynamic_cast<Ingrediente*>(r));
      }
      try{
        pPizza->aggiungiIngredienti(ingrePizza);
      }
      catch (std::domain_error* ecc){
          vista->mostraErrore(QString(ecc->what()));
      }
    }
    try{
        modello->inserisciArticolo(pArticolo);
        risorseSalvate = false;
        vista->aggiornaMenu(pA);
    } catch (std::domain_error* ecc){
        vista->mostraErrore(QString(ecc->what()));
    } catch (std::logic_error* ecc){
        vista->mostraErrore(QString(ecc->what()));
    }
}

void Controller::creaNuovoConsumabile(pacchettoConsumabile* pC){
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

void Controller::modificaConsumabile(pacchettoConsumabile * pC){
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
  Consumabile* vecchioConsumabile = dynamic_cast<Consumabile*>(modello->trovaRisorsa(pC->ID));

  //casi in cui voglio trasformare Lattina in Bottiglia o viceversa
  bool lattToBott = dynamic_cast<Lattina*>(vecchioConsumabile) && !dynamic_cast<pacchettoBevanda*>(pC)->tipo;
  bool bottToLatt = dynamic_cast<Bottiglia*>(vecchioConsumabile) && dynamic_cast<pacchettoBevanda*>(pC)->tipo;
  if(lattToBott || bottToLatt){
      modello->rimuoviConsumabile(vecchioConsumabile);
      modello->inserisciConsumabile(pConsumabile);
  }
  else{
      modello->modificaConsumabile(vecchioConsumabile,pConsumabile);
  }
  risorseSalvate = false;
}

void Controller::modificaArticolo(pacchettoArticolo* p){
  Articolo* modificato= nullptr;
  if(dynamic_cast<pacchettoPizza*>(p)){
    pacchettoPizza* pP = dynamic_cast<pacchettoPizza*>(p);
    modificato = new Pizza(pP->ID, pP->nome, pP->disponibilita, pP->prezzo);
  }
  // le bevande sono modificabili solo nell'inventario
  Articolo* daModificare = dynamic_cast<Articolo*>(modello->trovaRisorsa(p->ID));
  try{
    modello->modificaArticolo(daModificare, modificato);
    vista->visualizzaMenu();
  }
  catch (std::logic_error* ecc){
      vista->mostraErrore(QString(ecc->what()));
  }
  risorseSalvate = false;
}

void Controller::eliminaConsumabile(uint id){
  Risorsa* daEliminare = modello->trovaRisorsa(id);
  modello->rimuoviConsumabile(dynamic_cast<Consumabile*>(daEliminare));
  risorseSalvate = false;
}

void Controller::eliminaArticolo(uint id){
  Risorsa* daEliminare = modello->trovaRisorsa(id);
  modello->rimuoviArticolo(dynamic_cast<Articolo*>(daEliminare));
  risorseSalvate = false;
}

void Controller::creaNuovaComanda(pacchettoComanda *pC){
  Comanda* c = new Comanda(++idComande,
                           Contatto(pC->nome, pC->indirizzo, pC->telefono),
                           pC->oraConsegna, QDate::currentDate());
  auto ord = pC->ordinazione;
  for(auto it = ord.cbegin(); it!= ord.cend(); ++it){
    c->inserisciArticolo(
          dynamic_cast<Articolo*>(modello->trovaRisorsa((*it).first)),
          (*it).second);
  }
  try{
  modello->inserisciComanda(c);
  }
  catch(std::logic_error* ecc){
    vista->mostraErrore(QString(ecc->what()));
  }
  vista->visualizzaComande();
  comandeSalvate = false;
}

void Controller::modificaComanda(pacchettoComanda *pC){
  // TODO: Rivedere implementazione delle funzioni modificaComanda() e
  Comanda* c = modello->trovaComanda(pC->ID);
  Comanda* newC = new Comanda(pC->ID,
                              Contatto(pC->nome, pC->indirizzo, pC->telefono),
                              pC->oraConsegna, c->getDataConsegna());
  for(auto it = pC->ordinazione.cbegin(); it != pC->ordinazione.cend(); ++it)
    newC->inserisciArticolo(
          dynamic_cast<Articolo*>(modello->trovaRisorsa((*it).first)),
          (*it).second);
  // TODO: gestire eccezione lanciata da modello->modificaComanda
  modello->modificaComanda(c, newC);
  vista->visualizzaComande();
  vista->riapriComanda(c->getIdComanda());
  comandeSalvate = false;
}

void Controller::eliminaComanda(uint ID){
  modello->rimuoviComanda(modello->trovaComanda(ID));
  vista->visualizzaComande();
  comandeSalvate = false;
}

void Controller::eseguiComanda(){
  //if(modello->getComandaCorrente()->getOraConsegna() >= QTime::currentTime())
  modello->eseguiComanda();
  vista->visualizzaComande();
  comandeSalvate = false;
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
      Pizza* pP = dynamic_cast<Pizza*>(*it);
      p = new pacchettoPizza(pP->getIdRisorsa(), pP->getNome(),
                             pP->getDisponibilita(), pP->getPrezzo());
      auto listaIngr = pP->getIngredienti();
      for(auto it = listaIngr.const_begin(); it != listaIngr.const_end();
          ++it){
        Ingrediente* i = dynamic_cast<Ingrediente*>(*it);
        (dynamic_cast<pacchettoPizza*>(p))->ingredienti[i->getIdRisorsa()] = i->getNome();
      }
    }
    pacchetti->push_back(p);
  }
  return pacchetti;
}

// Cambiare segnatura in (const comanda*, bool);
// Eliminare ighe 296 - 298
pacchettoComanda* Controller::impacchettaComanda(const Comanda* c,
                                                 const Comanda* current) const{
  bool eseguita = true;
  if(current)
    eseguita = ((*c) < (*current)) ? true : false;
  pacchettoComanda* pC =
      new pacchettoComanda(c->getIdComanda(), c->getCliente().getNome(),
                           c->getCliente().getIndirizzo(),
                           c->getCliente().getTelefono(),
                           c->getOraConsegna(), c->getTotale(), eseguita);
  auto ordine = c->getOrdinazione();
  for(auto it = ordine.cbegin(); it!= ordine.cend(); ++it)
    pC->ordinazione[((*it).first)->getIdRisorsa()] = (*it).second;
  return pC;
}

pacchetto* Controller::trovaPacchetto(uint ID) const{
  QList<pacchetto*>* menu = recuperaMenu();
  pacchetto* p = nullptr;
  for(auto it = menu->cbegin(); it != menu->cend(); ++it)
    if((*it)->ID == ID)
      p = *it;
  return p;
}

QList<pacchettoComanda*>* Controller::recuperaComande() const{
  QList<pacchettoComanda*>* pacchetti =
      new QList<pacchettoComanda*>();
  if(!modello->getComande().isEmpty()){
    auto comande = modello->getComande();
    const Comanda* current = modello->getComandaCorrente();
    for(auto it = comande.const_begin(); it != comande.const_end(); ++it){
      // impacchetta singola comanda
      const Comanda* c = *it;
      /*
      * - Calcolo se comanda eseguita o meno usando indexOf
      * bool eseguita = (indexOf(c) < indexOf(current)) ? false : true;
      * Cambio segnatura impacchettaComanda: deve ricevere solo la comanda da
      * impacchettare e il bool per sapere se la comanda è eseguita o no
      * pacchetti->push_back(impacchettaComanda(c, eseguita));
      */
      pacchetti->push_back(impacchettaComanda(c, current));
    }
  }
  return pacchetti;
}

const pacchettoComanda *Controller::recuperaInfoComanda(uint ID) const {
  const pacchettoComanda* pC = nullptr;
  if(!modello->getComande().isEmpty()){
    const Comanda* current = modello->getComandaCorrente();
    pC = impacchettaComanda(modello->trovaComanda(ID), current);
  }
  return pC;
}

QList<pacchetto*>* Controller::recuperaContenutoComanda(uint ID) const{
  QList<pacchetto*>* contenuto = new QList<pacchetto*>();
  const pacchettoComanda* pC = recuperaInfoComanda(ID);
  for(auto it = pC->ordinazione.cbegin(); it != pC->ordinazione.cend(); ++it){
    contenuto->push_back(trovaPacchetto((*it).first));
  }
  return contenuto;
}

const QList<pacchetto *> *Controller::recuperaMenuPerComanda(uint ID) const{
  QList<pacchetto*>* menu = recuperaMenu();
  const QList<pacchetto*>* contenutoComanda = recuperaContenutoComanda(ID);
  for(auto it = contenutoComanda->cbegin(); it != contenutoComanda->cend(); ++it){
    for(auto it2 = menu->begin(); it2 != menu->end(); ++it2){
      std::cout << (*it)->nome << " " << (*it)->ID << std::endl;
      std::cout << (*it2)->nome << " " << (*it2)->ID << std::endl;
      if((*it)->ID == (*it2)->ID || !(*it2)->disponibilita){
        it2=menu->erase(it2);
        if(it2 != menu->begin()) --it2;
      }
    }
  }
  return menu;
}

const QList<pacchetto*>* Controller::recuperaMenuPerWizardNuovaComanda() const{
    QList<pacchetto*>* menu = recuperaMenu();
    for(auto it = menu->begin(); it != menu->end() ; ++it){
        if(!(*it)->disponibilita){
            it = menu->erase(it);
            if((it == menu->end()) || (it != menu->begin())) --it;
        }
    }
    return menu;
}

bool Controller::canQuit() const { return (comandeSalvate && risorseSalvate); }

void Controller::caricaComande(){
  try{
    modello->caricaComande();
  } catch (std::logic_error *ecc) {
    vista->mostraErrore(QString(ecc->what()));
  }
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
