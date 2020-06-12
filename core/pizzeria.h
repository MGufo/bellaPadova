#ifndef PIZZERIA_H
#define PIZZERIA_H
#include <QDate>
#include <stdexcept>

#include "contatto.h"
#include "gestoreComande.h"
#include "gestoreRisorse.h"
#include "qontainer.h"

class Pizzeria {
 private:
  Contatto contatto;
  GestoreRisorse gestoreRisorse;
  GestoreComande gestoreComande;
  unsigned short capacitaForno;
  //nel controller la costruzione delle comande dovrà usare idComande++ e il controller stesso dovrà incrementare idComande
  //idComande sarà ricaricato ad ogni costruzione del modello dal rispettivo file xml e salvato ad ogni salvataggio su file xml
  unsigned int idComande;

  // TODO: Creare gerarchia di eccezioni appropriata ai possibili tipi di errore
  // e implementarla

  // TODO: Sostituire le 'throw' generiche presenti nel modello con i tipi di
  // eccezione creati
  
 public:
  Pizzeria();
  double contabilizzazione(const QDate&, const QDate&) const;

  // funzione che inserisce un articolo in menu, l'articolo da inserire viene
  // costruito da un'altra funzione che richiama inserisciArticoloInMenu. se
  // tutti gli ingredienti dell'articolo sono disponibili e presenti
  // nell'inventario, la disponibilita dell'articolo viene messa a true;
  // altrimenti false
  void inserisciArticolo(Articolo*);
  void modificaArticolo(Articolo*, Articolo*);
  void rimuoviArticolo(Articolo*);

  void inserisciConsumabile(Consumabile*);
  void modificaConsumabile(Consumabile*, Consumabile*);
  void rimuoviConsumabile(Consumabile*);

  void inserisciComanda(Comanda*);
  void modificaComanda(Comanda*, Comanda*);
  void eseguiComanda();
  void rimuoviComanda(Comanda*);

  const Lista<string>& getContatto() const;

  void setContatto(const Contatto*);

  unsigned short getCapacitaForno();
  /**
   * @brief: Modifica la capacità del forno
   * @param: unsigned int (capacità)
   */
  void setCapacitaForno(unsigned short);

  /**
   * @brief: Lettura da file
   */
  void salva();

  /**
   * @brief: Scrittura su file
   */
  void carica();
};
#endif
