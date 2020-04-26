#include "comanda.h"

/* Gli oggetti passati come parametri al costruttore vengono costruiti ad alto
  livello; per questo motivo non vengono costruiti di copia nel costruttore.
*/
Comanda::Comanda(unordered_map<Articolo*, unsigned int> _ordinazione,
                 Contatto _cliente, QTime _oraConsegna)
    : ordinazione(_ordinazione), cliente(_cliente), oraConsegna(_oraConsegna){};

Comanda::Comanda(const Comanda& c)
    : ordinazione(c.ordinazione),
      cliente(c.cliente),
      oraConsegna(c.oraConsegna){};

const unordered_map<Articolo*, unsigned int>& Comanda::getOrdinazione() const {
  return ordinazione;
}

const Contatto& Comanda::getCliente() const { return cliente; }

const QTime& Comanda::getOraConsegna() const { return oraConsegna; }

void Comanda::setOraConsegna(QTime _oraConsegna) { oraConsegna = _oraConsegna; }

void Comanda::sostituisciArticolo(Articolo* daSostituire, int qtaDS,
                                  Articolo* daInserire, unsigned int qtaDI) {
  if (daSostituire) {
    if (qtaDS < 0) {
      if (ordinazione[daSostituire] <= qtaDS * (-1))
        ordinazione.erase(daSostituire);
      else
        ordinazione[daSostituire] += qtaDS;
    } else
      ordinazione[daSostituire] += qtaDS;
  }
  if (daInserire) ordinazione[daInserire] = qtaDI;
}
// sottocaso 1: aggiungere un nuovo articolo non presente in comanda
void Comanda::inserisciArticolo(Articolo* _daInserire, unsigned int _qtaDI) {
  sostituisciArticolo(nullptr, 0, _daInserire, _qtaDI);
}

// sottocaso 4: rimuovere un articolo presente in comanda
void Comanda::rimuoviArticolo(Articolo* _daSostituire) {
  ordinazione.erase(_daSostituire);
}

// controlli su esistenza farina e TD dell'articolo fatti ad alto livello dal
// chiamante
void Comanda::modificaFarina(Pizza* _daModificare, Farina* _farina) {
  _daModificare->setFarina(_farina);
}

void aggiungiIngrediente(Pizza* _daModificare, Ingrediente* _ingrediente) {
  _daModificare->addIngrediente(_ingrediente);
}

void rimuoviIngrediente(Pizza* _daModificare, Ingrediente* _ingrediente) {
  _daModificare->removeIngrediente(_ingrediente);
}

void Comanda::modificaContatto(string _nome, string _indirizzo, string _tel) {
  if (_nome != "") cliente.setNome(_nome);
  if (_indirizzo != "") cliente.setIndirizzo(_indirizzo);
  if (_tel != "") cliente.setTelefono(_tel);
}

void Comanda::modificaQuantita(Articolo* _daModificare, int _qta) {
  sostituisciArticolo(_daModificare, _qta, nullptr, 0);
}