#include "pizzeria.h"

double Pizzeria::calcoloGuadagno(const QJsonObject & comandeJSON,
                                 const QDate& inizio, const QDate& fine) const {
  double guadagno = 0;
  for(auto it = comandeJSON.constBegin(); it != comandeJSON.constEnd(); ++it){
    QDate dataConsegna =
        QDate::fromString((*(*it).toObject().constFind("dataConsegna")).toString());
    if(inizio <= dataConsegna && dataConsegna <= fine)
      guadagno += (*(*it).toObject().constFind("totale")).toDouble();
  }
  return guadagno;
}

QFile *Pizzeria::openFile(const string& path, char mode) const{
  QFile* file = new QFile(QString::fromStdString(path));
  if(mode == 'w')
    if(!file->open(QIODevice::Append | QIODevice::Text))
      throw new std::invalid_argument("Errore: Impossibile aprire il file");
  if(mode == 'r')
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
      throw new std::invalid_argument("Errore: Impossibile aprire il file");
  return file;
}

QJsonObject *Pizzeria::parseFile(QFile* file) const{
  QByteArray jsonData = file->readAll();
  file->close();

  QJsonParseError* pE = new QJsonParseError();
  QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData, pE);

//  if(fileRisorseJSON.isNull())
//    throw new std::invalid_argument(pE->errorString().toStdString());
  delete pE;
  QJsonObject* jsonContent = new QJsonObject(jsonDocument.object());
  return jsonContent;
}

Pizzeria::Pizzeria() : contatto(Contatto()),
                       gestoreRisorse(GestoreRisorse()),
                       gestoreComande(GestoreComande()),
                       capacitaForno(5) {}

const Lista<Consumabile *> &Pizzeria::getInventario() const{
    return gestoreRisorse.getInventario();
}

const Lista<Articolo *> &Pizzeria::getMenu() const{
    return gestoreRisorse.getMenu();
}

double Pizzeria::contabilizzazione(const QDate & inizio, const QDate & fine) const{
  double guadagni = calcoloGuadagno(caricaComande(), inizio, fine);;
  double costi = 0;
  const Lista<Consumabile*>* consumabili = &gestoreRisorse.getInventario();
  for(auto it = consumabili->const_begin(); it != consumabili->const_end(); ++it){
    if((inizio <= (*it)->getDataAcquisto()) && ((*it)->getDataAcquisto() <= fine)){
      costi += (*it)->getSpesa();
    }
  }
  return (guadagni - costi);
}

Risorsa *Pizzeria::trovaRisorsa(unsigned int ID) const{
  return gestoreRisorse.trovaRisorsa(ID);
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

void Pizzeria::salvaComande() const{
  QFile* fileComande = openFile(":/resources/comande.json", 'w');
  QJsonObject* comandeJSON = new QJsonObject();
  gestoreComande.salvaComande(comandeJSON);
  gestoreComande.salvaIdComande(comandeJSON);
  QJsonDocument* fileComandeJSON = new QJsonDocument(*comandeJSON);
  fileComande->write(fileComandeJSON->toJson());
  fileComande->close();
  delete fileComandeJSON;
}

void Pizzeria::salvaRisorse() const{
  QFile* fileRisorse = openFile(":/resources/risorse.json", 'w');
  QJsonObject* risorseJSON = new QJsonObject();
  gestoreRisorse.salvaRisorse(risorseJSON);
  gestoreRisorse.salvaIdRisorse(risorseJSON);
  QJsonDocument* fileRisorseJSON = new QJsonDocument(*risorseJSON);
  fileRisorse->write(fileRisorseJSON->toJson());
  fileRisorse->close();
  delete fileRisorseJSON;
}

const QJsonObject& Pizzeria::caricaComande() const{
  QFile* fileComande = openFile(":/resources/comande.json", 'r');
  const QJsonObject* comandeJSON = new QJsonObject(
        (*(parseFile(fileComande)->constFind("Comande"))).toObject());
  delete fileComande;
  return *comandeJSON;
}

void Pizzeria::caricaRisorse(){
  QFile* fileRisorse = openFile(":/resources/risorse.json", 'r');
  QJsonObject* risorseJSON = parseFile(fileRisorse);
  gestoreRisorse.caricaInventario((*risorseJSON->constFind("inventario")).toObject());
  gestoreRisorse.caricaMenu((*risorseJSON->constFind("menu")).toObject());
  delete risorseJSON;
  delete fileRisorse;
}

unsigned int Pizzeria::getIdComande() const{
  QFile* fileComande = openFile(":/resources/comande.json");
  QJsonObject* idComandeJSON = new QJsonObject(
        (*(parseFile(fileComande)->constFind("idComande"))).toObject());
  uint idComande = (*idComandeJSON->constFind("idComande")).toInt();
  delete fileComande;
  delete idComandeJSON;
  return idComande;
}

unsigned int Pizzeria::getIdRisorse() const{
  QFile* fileRisorse = openFile(":/resources/risorse.json");
  QJsonObject* idRisorseJSON = new QJsonObject(
        (*(parseFile(fileRisorse)->constFind("idRisorse"))).toObject());
  uint idRisorse = (*idRisorseJSON->constFind("idRisorse")).toInt();
  delete fileRisorse;
  delete idRisorseJSON;
  return idRisorse;
}
