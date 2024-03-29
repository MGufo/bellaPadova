class Pizzeria {
  void modifica(Articolo* toModify, Articolo* modified) {
    gestoreRisorse.modifica(Articolo * toModify, Articolo * modified);
  }
};
class GestoreRisorse {
  List<Consumabili> consumabili;

  // ver 1
  void modifica(Articolo* toModify, Articolo* modified) {
    if (modified.checkRisorse(consumabili))
    // replace e setta disp=true
  }
  else {  // replace con disp=false
  }
};
// ver 2
// checkDisponibilitàConsumabili sarebbe funz privata
void modifica(Articolo* toModify, Articolo* modified) {
  if (checkDisponibilitàConsumabili(modified.getConsumabili()))
  // replace e setta disp=true
}
else {  // replace con disp=false
}

void addArticolo(Articolo* a) {
  if (a.checkRisorse(consumabili)) {
    // aggiungi con disp=true
  } else  // aggiungi con disp=false
}

void rimuovi(Articolo a) {}
}

class Articolo {
  ....
      // ver 1
      virtual bool checkRisorse(List<Consumabili>) = 0;
  // ver2
  virtual List<Consumabili> getConsumabili() = 0;

}

class Pizza {
  List<Ingrediente> ingredienti;
  // ver 1
  bool checkRisorse(List<Consumabili> consumabili) {
    // controlla che ingredienti stiano dentro consumabili con le risp. quantità
  }
  // ver 2
  List<Consumabili> getConsumabili() { return ingrendienti }

}

class Bevanda {
  // vers 1
  bool checkRisorse(List<Consumabili*> consumabili) {
    for (c in consumabili) {
      if (c == this) return true;
    }
    return false;
  }
  // ver 2
  List<Consumabili> getConsumabili() { return new List<Consumabili>(this); }
}
------------

void GestoreComande::modificaComanda(Pizza* _pizza,
                                     const Lista<Ingrediente*>* daAggiungere,
                                     const Lista<Ingrediente*>* daRimuovere) {
  Lista<Ingrediente*>::const_Iterator it = daAggiungere->const_begin();

  if (!daAggiungere->isEmpty()) {
    // controllo presenza nuova farina
    if (dynamic_cast<Farina*>(*it)) {
      _pizza->setFarina(static_cast<Farina*>(*it));
      ++it;
    }
    while (it != daAggiungere->const_end()) {
      if (!_pizza->checkIngrediente(*it)) _pizza->addIngrediente(*it);
      ++it;
    }
  }
  it = daRimuovere->const_begin();
  if (!daRimuovere->isEmpty()) {
    while (it != daRimuovere->const_end()) {
      if (_pizza->checkIngrediente(*it)) _pizza->removeIngrediente(*it);
      ++it;
    }
  }
}