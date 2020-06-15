#include "pizzeria.h"

Pizzeria::Pizzeria()
  : contatto(Contatto()),
    gestoreRisorse(GestoreRisorse()),
    gestoreComande(GestoreComande()),
    capacitaForno(5) {}

double Pizzeria::contabilizzazione(const QDate & inizio, const QDate & fine) const{
  double guadagni = 0;
  double costi = 0;
  const unordered_map<Articolo*, unsigned int>* ordinazione = nullptr;
  const Lista<Comanda*>* comande = &gestoreComande.getBacheca();
  const Lista<Consumabile*>* consumabili = &gestoreRisorse.getInventario();

  for(auto it = comande->const_begin(); it != comande->const_end(); ++it){
    if(inizio <= (*it)->getDataConsegna() && (*it)->getDataConsegna() <= fine){
      ordinazione = &(*it)->getOrdinazione();
      for(auto it2 =ordinazione->cbegin(); it2 != ordinazione->cend(); ++it2){
        guadagni += (*it2).first->getPrezzo() * (*it2).second;
      }
    }
  }
  for(auto it = consumabili->const_begin(); it != consumabili->const_end(); ++it){
    if((inizio <= (*it)->getDataAcquisto()) && ((*it)->getDataAcquisto() <= fine)){
      costi += (*it)->getSpesa();
    }
  }
  return (guadagni - costi);
}

void Pizzeria::inserisciArticolo(Articolo* daInserire) {
  gestoreRisorse.inserisciArticolo(daInserire);
}

void Pizzeria::modificaArticolo(Articolo* daModificare,
                                Articolo* modificato) {
  gestoreRisorse.modificaArticolo(daModificare, modificato);
  delete modificato;
}

void Pizzeria::rimuoviArticolo(Articolo* daRimuovere) {
  gestoreRisorse.rimuoviArticolo(daRimuovere);
  delete daRimuovere;
}

void Pizzeria::inserisciConsumabile(Consumabile* daInserire) {
  gestoreRisorse.inserisciConsumabile(daInserire);
}

void Pizzeria::modificaConsumabile(Consumabile* daModificare,
                                   Consumabile* modificato) {
  gestoreRisorse.modificaConsumabile(daModificare, modificato);
  delete modificato;
}

void Pizzeria::rimuoviConsumabile(Consumabile* daRimuovere) {
  gestoreRisorse.rimuoviConsumabile(daRimuovere);
  delete daRimuovere;
}

void Pizzeria::inserisciComanda(Comanda* daInserire) {
  if(daInserire){
    //controllo che per ogni elemento dell'ordinazione tutti gli elementi
    //della sua composizione siano presenti nell'inventario
    bool inseribile = true;
    const unordered_map<Articolo*, unsigned int>* ordinazione = &daInserire->getOrdinazione();
    for(auto it = ordinazione->cbegin(); (it != ordinazione->cend()) && inseribile; ++it){
      inseribile = gestoreRisorse.controlloInInventario((*it).first);
    }
    if(inseribile) gestoreComande.inserisciComanda(daInserire, capacitaForno);
    else  throw;
  }
}

void Pizzeria::modificaComanda(Comanda* daModificare,
                               Comanda* modificata) {
  bool inseribile = true;
  const unordered_map<Articolo*, unsigned int>* ordinazione = &modificata->getOrdinazione();
  for(auto it = ordinazione->cbegin(); (it != ordinazione->cend()) && inseribile; ++it){
    inseribile = gestoreRisorse.controlloInInventario((*it).first);
  }
  if(inseribile) gestoreComande.modificaComanda(daModificare, modificata, capacitaForno);
  else throw;
  delete modificata;
}

void Pizzeria::eseguiComanda() { gestoreComande.eseguiComanda(); }

void Pizzeria::rimuoviComanda(Comanda* daRimuovere) {
  gestoreComande.rimuoviComanda(daRimuovere);
  delete daRimuovere;
}

const Lista<string>& Pizzeria::getContatto() const {
  return contatto.getContatto();
}

void Pizzeria::setContatto(const Contatto* modificato) {
  contatto = *modificato;
}

unsigned short Pizzeria::getCapacitaForno() { return capacitaForno; }

void Pizzeria::setCapacitaForno(unsigned short _forno) {
  capacitaForno = _forno;
}

void Pizzeria::salva(){

}

void Pizzeria::carica(){

}
