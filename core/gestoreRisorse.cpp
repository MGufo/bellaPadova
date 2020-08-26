#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(Lista<Articolo*>()), inventario(Lista<Consumabile*>()) {}

bool GestoreRisorse::controlloInInventario(Articolo * daControllare) const{
    bool presente = true;
    const Lista<const Consumabile*>* consumabili = daControllare->getComposizione();
    for(auto it = consumabili->const_begin(); (it != consumabili->const_end()) && presente; ++it){
      for(auto it = inventario.const_begin(); it != inventario.const_end() && !presente; ++it)
        if((*it)->getIdRisorsa() == daControllare->getIdRisorsa()) presente = true;
    }
    delete consumabili;
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
    const Lista<const Consumabile*>* daCercare) const {
  Lista<const Consumabile*>::const_Iterator it;
  bool disponibile = true;
  for (it = daCercare->const_begin();
       it != daCercare->const_end() && disponibile; ++it)
    if (!(*it)->getDisponibilita()) disponibile = false;
  return disponibile;
}

bool GestoreRisorse::controlloConsumabile(const Lista<const Consumabile*>* _lista,
                                          const Consumabile* daCercare) const {
  bool trovato = false;
  for(auto it = _lista->const_begin(); it != _lista->const_end() && !trovato; ++it)
    if((*it)->getIdRisorsa() == daCercare->getIdRisorsa()) trovato = true;
  return trovato;
}

unsigned int GestoreRisorse::getMaxId() const{
  unsigned int maxID = 0;
  for(auto it = menu.const_begin(); it != menu.const_end(); ++it)
    if((*it)->getIdRisorsa() > maxID) maxID = (*it)->getIdRisorsa();

  for(auto it = inventario.const_begin(); it != inventario.const_end(); ++it)
    if((*it)->getIdRisorsa() > maxID) maxID = (*it)->getIdRisorsa();

  return maxID;
}


void GestoreRisorse::inserisciArticolo(Articolo* daInserire) {
  if (daInserire) {
    const Lista<const Consumabile*>* lista = daInserire->getComposizione();
    if (!controlloInInventario(daInserire))
      throw new std::logic_error("Errore: uno o più elementi della composizione di questo articolo non sono attualmente disponibili.");
    for (auto it = menu.const_begin(); it != menu.const_end(); ++it){
      if(daInserire->getIdRisorsa() == (*it)->getIdRisorsa())
        throw new std::domain_error("Errore: l'articolo è già presente nel menù.");
    }
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

void GestoreRisorse::inserisciConsumabile(Consumabile* daInserire) {
  if (daInserire) {
    inventario.push_back(daInserire);
  }
}

void GestoreRisorse::rimuoviConsumabile(Consumabile* daRimuovere) {
  if (daRimuovere) {
      auto it = menu.begin();
    bool controlloPrimoElemento = false;
    while(it != menu.end()) {
      controlloPrimoElemento = false;
      const Lista<const Consumabile*>* lista = (*it)->getComposizione();
      if (controlloConsumabile(lista, daRimuovere)){
          it = menu.erase(it);
          if (it != menu.begin()){
              --it;
          }
          else{
              //caso in cui non vogliamo incrementare it perchè corrisponde al begin e deve essere ancora controllato
              controlloPrimoElemento = true;
          }
      }
      delete lista;
      if(!controlloPrimoElemento){
          ++it;
      }
    }
    inventario.erase(inventario.find(daRimuovere));
  }
}

void GestoreRisorse::modificaArticolo(Articolo* daModificare,
                                      Articolo* modificato) {
  const Lista<const Consumabile*>* composizioneDaModificare = daModificare->getComposizione();
  if (modificato->getDisponibilita() && !controlloDisponibilita(composizioneDaModificare))
    throw new std::logic_error("Errore: Impossibile modificare l'elemento in quanto uno o più elementi della sua composizione non sono disponibili.");
  for(auto it = menu.begin() ; it != menu.end() ; ++it){
      if(daModificare->getIdRisorsa() == (*it)->getIdRisorsa())
          (*it)->modifica(modificato);
  }
  daModificare->setDisponibilita(daModificare->getDisponibilita() && controlloDisponibilita(composizioneDaModificare));
  delete composizioneDaModificare;
}

void GestoreRisorse::modificaConsumabile(Consumabile* daModificare,
                                         Consumabile* modificato) {
  //auto it = inventario.find(daModificare);
  //if(it.isValid())  (*it)->modifica(modificato);
  for(auto it = inventario.begin() ; it != inventario.end() ; ++it){
      if(daModificare->getIdRisorsa() == (*it)->getIdRisorsa())
          (*it)->modifica(modificato);
  }

  for (auto it = menu.begin(); it != menu.end(); ++it) {
    const Lista<const Consumabile*>* lista = (*it)->getComposizione();
    (*it)->setDisponibilita((*it)->getDisponibilita() && controlloDisponibilita(lista));
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
    Risorsa* risorsa = nullptr;

    if(tipo == "pizza") risorsa = new Pizza();

    std::unordered_map<uint, Risorsa*>* keymap =
        new std::unordered_map<uint, Risorsa*>;
    if(tipo == "pizza"){
      QJsonArray* ingrJSON =
          new QJsonArray((*(risorsaJSON->find("Ingredienti"))).toArray());
      for(auto it = ingrJSON->constBegin(); it!=ingrJSON->constEnd(); ++it)
        (*keymap)[(*it).toInt()] =
              trovaRisorsa((*it).toInt());
      delete ingrJSON;
    }
      /**
      TODO: Discutere cosa fare nel caso in cui un ingrediente di una pizza
      non venga mappato a un puntatore valido ma a un nullptr.
      */
    if(risorsa){
        risorsa->carica(*risorsaJSON, keymap);
        menu.push_back(dynamic_cast<Articolo*>(risorsa));
    }
    else{
        Articolo* bevandaInMenu = nullptr;
        uint id = (*(risorsaJSON->find("ID"))).toInt();
        for(auto it = inventario.const_begin() ; it != inventario.const_end() ; ++it){

            if((*it)->getIdRisorsa() == id) bevandaInMenu = dynamic_cast<Articolo*>(static_cast<Risorsa*>(*it));
        }
        menu.push_back(bevandaInMenu);
    }
    delete keymap;
    delete risorsaJSON;
  }
}

void GestoreRisorse::caricaInventario(const QJsonObject & risorseJSON){
  string tipo;
  for(auto it = risorseJSON.constBegin(); it != risorseJSON.constEnd(); ++it){
    QJsonObject* risorsaJSON = new QJsonObject((*it).toObject());
    tipo = (*(risorsaJSON->find("tipo"))).toString().toStdString();
    Risorsa* risorsa = nullptr;

    if (tipo == "bottiglia") risorsa = new Bottiglia();
    else if (tipo == "lattina") risorsa = new Lattina();
    else if (tipo == "ingrediente") risorsa = new Ingrediente();
    else if (tipo == "farina") risorsa = new Farina();

    risorsa->carica(*risorsaJSON, nullptr);
    Consumabile* newP = dynamic_cast<Consumabile*>(risorsa);
    inventario.push_back(newP);
    delete risorsaJSON;
  }
}

