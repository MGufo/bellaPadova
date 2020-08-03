#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

bool GestoreRisorse::controlloInInventario(Articolo * daControllare) const{
    bool presente = true;
    const Lista<Consumabile*>* consumabili = daControllare->getComposizione();
    for(auto it = consumabili->const_begin(); (it != consumabili->const_end()) && presente; ++it){
        presente = controlloConsumabile(&inventario, *it);
    }
    return presente;
}

Risorsa *GestoreRisorse::trovaRisorsa(unsigned int ID) const{
  for(auto it = menu.const_begin(); it != menu.const_end(); ++it){
      if((*it)->getIdRisorsa()==ID) return *it;
  }
  for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it){
      if((*it)->getIdRisorsa()==ID) return *it;
  }
  return nullptr;
}

bool GestoreRisorse::controlloDisponibilita(
    const Lista<Consumabile*>* daCercare) const {
  Lista<Consumabile*>::const_Iterator it;
  bool disponibile = true;
  for (it = daCercare->const_begin();
       it != daCercare->const_end() && disponibile; ++it)
    if (!(*it)->getDisponibilita()) disponibile = false;
  return disponibile;
}

bool GestoreRisorse::controlloConsumabile(const Lista<Consumabile*>* _lista,
                                          Consumabile* daCercare) const {
  if ((_lista->find(daCercare).isValid())) return true;
  return false;
}

unsigned int GestoreRisorse::getMaxId() const{
  unsigned int maxID = 0;
  for(auto it = menu.const_begin(); it != menu.const_end(); ++it)
    if((*it)->getIdRisorsa() > maxID) maxID = (*it)->getIdRisorsa();

  for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it)
    if((*it)->getIdRisorsa() > maxID) maxID = (*it)->getIdRisorsa();

  return maxID;
}

//TODO:
//ATTENZIONE all'inserimento di un articolo gia presente nel menu!
//implementare funzione privata che controlla campo dati per campo dati
//se daInserire == articoloGiaPresenteNelMenu
void GestoreRisorse::inserisciArticolo(Articolo* daInserire) {
  if (daInserire) {
    const Lista<Consumabile*>* lista = daInserire->getComposizione();
    for (auto it = lista->const_begin(); it != lista->const_end(); ++it)
      if (!controlloConsumabile(&inventario, *it))
        throw new std::logic_error("Errore: Uno o più elementi della composizione di questo articolo non sono attualmente disponibili.");
    daInserire->setDisponibilita(controlloDisponibilita(lista));
    menu.push_back(daInserire);
    delete lista;
  }
}

void GestoreRisorse::rimuoviArticolo(Articolo* daRimuovere) {
  if (daRimuovere) {
    Lista<Articolo*>::Iterator it = menu.find(daRimuovere);
    if (it.isValid()) {
      menu.erase(it);
    }
  }
}

//TODO:
//ATTENZIONE all'inserimento di un consumabile gia presente nell'inventario!
//implementare funzione privata che controlla campo dati per campo dati
//se daInserire == consumabileGiaPresenteNellInventario
void GestoreRisorse::inserisciConsumabile(Consumabile* daInserire) {
  if (daInserire) {
    inventario.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviConsumabile(Consumabile* daRimuovere) {
  if (daRimuovere) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
      const Lista<Consumabile*>* lista = (*it)->getComposizione();
      if (controlloConsumabile(lista, daRimuovere)) it = menu.erase(it);
      if (it != menu.begin()) --it;
      delete lista;
    }
    inventario.erase(inventario.find(daRimuovere));
  }
}

void GestoreRisorse::modificaArticolo(Articolo* daModificare,
                                      const Articolo* modificato) {
  *daModificare = *modificato;
  const Lista<Consumabile*>* lista = daModificare->getComposizione();
  for (auto it = lista->const_begin(); it != lista->const_end(); ++it)
    if (!controlloConsumabile(&inventario, *it))
      throw new std::logic_error("Errore: Uno o più ingredienti selezionati"
                                 "non sono disponibili.");
  daModificare->setDisponibilita(controlloDisponibilita(lista));
  delete lista;
}

void GestoreRisorse::modificaConsumabile(Consumabile* daModificare,
                                         Consumabile* modificato) {
  //TODO: implemento modifica() come funzione virtuale pura in consumabile
  auto it = inventario.find(daModificare);
  if(it.isValid())  (*it)->modifica(modificato);

  for (auto it = menu.begin(); it != menu.end(); ++it) {
    const Lista<Consumabile*>* lista = (*it)->getComposizione();
    (*it)->setDisponibilita(controlloDisponibilita(lista));
    delete lista;
  }
}

const Lista<Articolo*>& GestoreRisorse::getMenu() const { return menu; }

const Lista<Consumabile*>& GestoreRisorse::getInventario() const {
  return inventario;
}

void GestoreRisorse::salvaRisorse(QJsonObject *risorseJSON) const{
  QJsonObject* menuJSON = new QJsonObject();
  for(auto it = menu.const_begin(); it != menu.const_end(); ++it){
    QJsonObject* articoloJSON = new QJsonObject();
    (*it)->salva(*articoloJSON);
    menuJSON->insert(QString::fromStdString((*it)->getNome()), *articoloJSON);
    delete articoloJSON;
  }
  risorseJSON->insert("Menu", *menuJSON);
  delete menuJSON;

  QJsonObject* inventarioJSON = new QJsonObject();
  for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it){
    QJsonObject* consumabileJSON = new QJsonObject();
    (*it)->salva(*consumabileJSON);
    inventarioJSON->insert(
          QString::fromStdString((*it)->getNome()), *consumabileJSON);
    delete consumabileJSON;
  }
  risorseJSON->insert("Inventario", *inventarioJSON);
  delete inventarioJSON;
}

void GestoreRisorse::salvaIdRisorse(QJsonObject* idRisorseJSON) const{
  idRisorseJSON->insert("ID", static_cast<double>(getMaxId()));
}

void GestoreRisorse::caricaMenu(const QJsonObject& menuJSON){
  string tipo;
  for(auto it = menuJSON.constBegin(); it != menuJSON.constEnd(); ++it){
    QJsonObject* risorsaJSON = new QJsonObject((*it).toObject());
    tipo = (*(risorsaJSON->find("tipo"))).toString().toStdString();
    Risorsa* risorsa;

    if(tipo == "pizza") risorsa = new Pizza();
    else if (tipo == "bottiglia") risorsa = new Bottiglia();
    else if (tipo == "lattina") risorsa = new Lattina();
    else if (tipo == "ingrediente") risorsa = new Ingrediente();
    else if (tipo == "farina") risorsa = new Farina();

    std::unordered_map<uint, Risorsa*>* keymap =
        new std::unordered_map<uint, Risorsa*>;
    if(tipo == "pizza"){
      QJsonArray* ingrJSON =
          new QJsonArray((*(risorsaJSON->find("Ingredienti"))).toArray());
      for(auto it = ingrJSON->constBegin(); it!=ingrJSON->constEnd(); ++it)
        (*keymap)[(*((*it).toObject()).find("ID")).toInt()] =
              trovaRisorsa((*((*it).toObject()).find("ID")).toInt());
    }
      /**
      TODO: Discutere cosa fare nel caso in cui un ingrediente di una pizza
      non venga mappato a un puntatore valido ma a un nullptr.
      */
    risorsa->carica(*risorsaJSON, keymap);
    menu.push_back(dynamic_cast<Articolo*>(risorsa));
    delete keymap;
    delete risorsaJSON;
  }
}

void GestoreRisorse::caricaInventario(const QJsonObject & risorseJSON){
  string tipo;
  for(auto it = risorseJSON.constBegin(); it != risorseJSON.constEnd(); ++it){
    QJsonObject* risorsaJSON = new QJsonObject((*it).toObject());
    tipo = (*(risorsaJSON->find("tipo"))).toString().toStdString();
    Risorsa* risorsa;

    if (tipo == "bottiglia") risorsa = new Bottiglia();
    else if (tipo == "lattina") risorsa = new Lattina();
    else if (tipo == "ingrediente") risorsa = new Ingrediente();
    else if (tipo == "farina") risorsa = new Farina();

    risorsa->carica(*risorsaJSON, nullptr);
    inventario.push_back(dynamic_cast<Consumabile*>(risorsa));
    delete risorsaJSON;
  }
}

