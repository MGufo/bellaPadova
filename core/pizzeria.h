#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <QDate>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <sstream>
#include <stdexcept>
#include <string>

#include "contatto.h"
#include "gestoreComande.h"
#include "gestoreRisorse.h"
#include "qontainer.h"
#include "utils.h"

class Pizzeria {
 private:
  Contatto contatto;
  GestoreRisorse gestoreRisorse;
  GestoreComande gestoreComande;
  unsigned short capacitaForno;
  const string pathComande;
  const string pathRisorse;

  double calcoloGuadagno(const QJsonObject&, const QDate&, const QDate&) const;

  /**
   * @brief: Se esiste apre il file al percorso specificato, altrimenti lancia
   * un'eccezione
   * @param: stringa rappresentante il percorso su disco al file da aprire
   * * @param: char rappresentante la modalità di apertura (r = read, w = write)
   * @returns: Puntatore a QFile rappresentante il file aperto
   * @throws: std::invalid_argument
   */
  QFile* openFile(const string&, char) const;

  /**
   * @brief: Se esiste apre il file al percorso specificato, altrimenti lancia
   * un'eccezione
   * @returns: Puntatore a QFile rappresentante il file aperto
   * @throws: std::invalid_argument (errore di parsing del file)
   */
  QJsonObject* parseFile(QFile*) const;

 public:
  Pizzeria(const string, const string);
  const Lista<Consumabile*>& getInventario() const;
  const Lista<Articolo*>& getMenu() const;
  const Lista<Comanda*>& getComande() const;
  const Comanda* getComandaCorrente() const;

  double contabilizzazione(const QDate&, const QDate&) const;
  Risorsa* trovaRisorsa(unsigned int ID) const;
  Comanda* trovaComanda(unsigned int ID) const;

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
  void salvaComande() const;

  /**
   * @brief: Serializza le risorse (articoli in menù e inventario) presenti
   *         nel modello e le scrive in un file JSON
   */
  void salvaRisorse() const;

  /**
   * @brief: Legge da file JSON una lista di comande e le aggiunge al modello
   * @returns: QJsonObject& (oggetto JSON contenente oggetti JSON rappresentanti
   * le comande eseguite dalla pizzeria)
   */
  QJsonObject& caricaComande() const;

  /**
   * @brief: Legge da file JSON una lista di articoli e li aggiunge
   *         rispettivamente a menù e inventario
   */
  void caricaRisorse();

  /**
   * @brief: Legge da file JSON l'ultimo ID assegnato ad una comanda e lo
   * ritorna
   */
  unsigned int getIdComande() const;

  /**
   * @brief: Legge da file JSON l'ultimo ID assegnato ad una risorsa e lo
   * ritorna
   */
  unsigned int getIdRisorse() const;

  bool getDaSalvare() const;
  string getPathComande() const;
  string getPathRisorse() const;
};
#endif
