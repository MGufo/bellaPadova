#ifndef PIZZERIA_H
#define PIZZERIA_H
#include <QDate>

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

 public:
  Pizzeria();
  double contabilizzazione(QDate, QDate) const;
  const Lista<const string> getContatto() const;

  // funzione che inserisce un articolo in menu, l'articolo da inserire viene
  // costruito da un'altra funzione che richiama inserisciArticoloInMenu. se
  // tutti gli ingredienti dell'articolo sono disponibili e presenti
  // nell'inventario, la disponibilita dell'articolo viene messa a true;
  // altrimenti false
  void inserisciArticoloInMenu(Articolo*);

  // 1. creazione nuova comanda (gestoreRisorse controlla se sia possibile
  // creare la comanda)
  // 2. si invoca il metodo di gestoreComande che inserirà la comanda creata
  // nella lista per gestire le comande
  void nuovaComanda(Comanda*);

  // gestoreComande.lista.*iteratore.
  // void modificaComanda(Comanda*);

  static unsigned short getCapacitaForno();

  /**
   * @brief: Modifica la capacità del forno
   * @param: unsigned int (capacità)
   */
  static void setCapacitaForno(unsigned short);
};
#endif
