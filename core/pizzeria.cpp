#include "pizzeria.h"

Pizzeria::Pizzeria()
  : contatto(Contatto()),
    gestoreRisorse(GestoreRisorse()),
    gestoreComande(GestoreComande()),
    capacitaForno(5) {
    //caricaRisorse();
}

const Lista<Consumabile *> &Pizzeria::getInventario() const{
    return gestoreRisorse.getInventario();
}

const Lista<Articolo *> &Pizzeria::getMenu() const{
    return gestoreRisorse.getMenu();
}

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
    const unordered_map<Articolo*,unsigned int> *ordinazione = &daInserire->getOrdinazione();
    unordered_map<Articolo*, unsigned int>::const_iterator it;
    for(it = ordinazione->cbegin(); (it != ordinazione->cend()) && inseribile; ++it){
      inseribile = gestoreRisorse.controlloInInventario((*it).first);
    }
    if(inseribile){
      gestoreComande.inserisciComanda(daInserire, capacitaForno);
      // TODO: Emettere segnale per la vista
    }
    else {
      std::stringstream errorMsg;
      errorMsg << "Errore: Non è possibile inserire la comanda perché uno o più ingredienti necessari per creare l'articolo " << ((*it).first)->getNome()
               << " non sono disponibili";
      throw new std::logic_error(errorMsg.str());
    }
  }
}

void Pizzeria::modificaComanda(Comanda* daModificare, Comanda* modificata) {
  bool inseribile = true;
  const unordered_map<Articolo*, unsigned int>* ordinazione = &modificata->getOrdinazione();
  unordered_map<Articolo*, unsigned int>::const_iterator it;
  for(it = ordinazione->cbegin(); (it != ordinazione->cend()) && inseribile; ++it){
    inseribile = gestoreRisorse.controlloInInventario((*it).first);
  }
  if(inseribile) gestoreComande.modificaComanda(daModificare, modificata, capacitaForno);
  else{
    std::stringstream errorMsg;
    errorMsg << "Errore: Non è possibile modificare la comanda perché uno o più ingredienti necessari per creare l'articolo " << ((*it).first)->getNome()
             << " non sono disponibili";
    throw new std::logic_error(errorMsg.str());
  }
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

void Pizzeria::salvaComande(){
  QFile fileComande(":/resources/comande.json");
  if(!fileComande.open(QIODevice::Append | QIODevice::Text))
    throw new std::invalid_argument("Errore: Impossibile aprire il file");

  QJsonObject* comandeJSON = new QJsonObject();
  gestoreComande.salvaComande(comandeJSON);
  QJsonDocument* fileComandeJSON = new QJsonDocument(*comandeJSON);
  fileComande.write(fileComandeJSON->toJson());
  fileComande.close();
  delete fileComandeJSON;

/*
1: Apro il file da disco con QFile
2: Creare un JsonDocument che rappresenta il file json all'interno di Qt
3: Aggiungere il contenuto del model al JsonDocument
4: Scrivere il contenuto del JsonDocument nel QFile
*/
}

void Pizzeria::salvaRisorse(){
  QFile fileRisorse(":/resources/risorse.json");
  if(!fileRisorse.open(QIODevice::Append | QIODevice::Text))
    throw new std::invalid_argument("Errore: Impossibile aprire il file");

  QJsonObject* risorseJSON = new QJsonObject();
  gestoreRisorse.salvaRisorse(risorseJSON);
  QJsonDocument* fileRisorseJSON = new QJsonDocument(*risorseJSON);
  fileRisorse.write(fileRisorseJSON->toJson());
  fileRisorse.close();
  delete fileRisorseJSON;
}

void Pizzeria::caricaComande(){
  QFile fileComande(":/resources/comande.json");
  if(!fileComande.open(QIODevice::ReadOnly | QIODevice::Text))
    throw new std::invalid_argument("Errore: Impossibile aprire il file");

  QByteArray jsonData = fileComande.readAll();
  fileComande.close();

  QJsonParseError* pE = new QJsonParseError();
  QJsonDocument fileComandeJSON = QJsonDocument::fromJson(jsonData, pE);

//  if(fileRisorseJSON.isNull())
//    throw new std::invalid_argument(pE->errorString().toStdString());

  QJsonObject comandeJSON = fileComandeJSON.object();

  gestoreComande.caricaComande(comandeJSON);
  delete pE;
}

void Pizzeria::caricaRisorse(){
  QFile fileRisorse(":/resources/risorse.json");
  if(!fileRisorse.open(QIODevice::ReadOnly | QIODevice::Text))
    throw new std::invalid_argument("Errore: Impossibile aprire il file");

  QByteArray jsonData = fileRisorse.readAll();
  fileRisorse.close();

  QJsonParseError* pE = new QJsonParseError();
  QJsonDocument fileRisorseJSON = QJsonDocument::fromJson(jsonData, pE);

//  if(fileRisorseJSON.isNull())
//    throw new std::invalid_argument(pE->errorString().toStdString());

  QJsonObject risorseJSON = fileRisorseJSON.object();
  gestoreRisorse.caricaRisorse(risorseJSON);

//  QJsonObject inventarioJSON = risorseJSON["inventario"].toObject();
//  gestoreRisorse.caricaRisorse(inventarioJSON);

  delete pE;
}

  /*leggere id ultima comanda e mandarlo come signal allo slot del controller
  *che si setta l'id corretto
  * Poi si legge il resto del file e si caricano le robe
  */

