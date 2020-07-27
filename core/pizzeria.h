#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <QDate>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

#include <sstream>
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
  double calcoloGuadagno(const QJsonObject&, const QDate&, const QDate&) const;
 public:
  Pizzeria();
  const Lista<Consumabile*>& getInventario() const;
  const Lista<Articolo*>& getMenu() const;

  double contabilizzazione(const QDate&, const QDate&) const;
  Risorsa* trovaRisorsa(unsigned int ID) const;

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
   * @brief: Serializza le comande presenti nel modello e le scrive
   *         in un file JSON
   */
  void salvaComande();

  /**
   * @brief: Serializza le risorse (articoli in menù e inventario) presenti
   *         nel modello e le scrive in un file JSON
   */
  void salvaRisorse();

  /**
   * @brief: Legge da file JSON una lista di comande e le aggiunge al modello
   */
  void caricaComande();

  /**
   * @brief: Legge da file JSON una lista di articoli e li aggiunge
   *         rispettivamente a menù e inventario
   */
  void caricaRisorse();


};
#endif
