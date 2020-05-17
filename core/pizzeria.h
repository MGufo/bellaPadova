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
  static unsigned short capacitaForno;

  // TODO: Creare gerarchia di eccezioni appropriata ai possibili tipi di errore
  // e implementarla

  // TODO: Sostituire le 'throw' generiche presenti nel modello con i tipi di
  // eccezione creati
  
 public:
  Pizzeria();
  double contabilizzazione(QDate, QDate) const;

  // funzione che inserisce un articolo in menu, l'articolo da inserire viene
  // costruito da un'altra funzione che richiama inserisciArticoloInMenu. se
  // tutti gli ingredienti dell'articolo sono disponibili e presenti
  // nell'inventario, la disponibilita dell'articolo viene messa a true;
  // altrimenti false
  void inserisciArticolo(Articolo*);
  void modificaArticolo(Articolo*, const Articolo*);
  void rimuoviArticolo(Articolo*);

  void inserisciConsumabile(Consumabile*);
  void modificaConsumabile(Consumabile*, const Consumabile*);
  void rimuoviConsumabile(Consumabile*);

  void inserisciComanda(Comanda*);
  void modificaComanda(Comanda*, const Comanda*);
  void eseguiComanda();
  void rimuoviComanda(Comanda*);

  const Lista<string>& getContatto() const;

  void setContatto(const Contatto*);

  static unsigned short getCapacitaForno();
  /**
   * @brief: Modifica la capacità del forno
   * @param: unsigned int (capacità)
   */
  static void setCapacitaForno(unsigned short);

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
