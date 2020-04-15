#include <QDate>

#include "contatto.h"
#include "gestore.h"
#include "risorsa.h"

class Pizzeria {
 private:
  Contatto* contatto;
  Gestore* gestore;

 public:
  Pizzeria(string, string, string);
  double contabilizzazione(QDate, QDate) const;
  const Lista<const string&> getContatto() const;

  // funzione che inserisce un articolo in menu, l'articolo da inserire viene costruito da 
  // un'altra funzione che richiama inserisciArticoloInMenu. 
  // se tutti gli ingredienti dell'articolo sono disponibili e presenti nell'inventario, la disponibilita
  // dell'articolo viene messa a true; altrimenti false
  void inserisciArticoloInMenu(Articolo*); 
};
