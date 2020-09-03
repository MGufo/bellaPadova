#ifndef BEVANDA_H
#define BEVANDA_H

#include "articolo.h"
#include "consumabile.h"
#include "qontainer.h"

class Bevanda : public Articolo, public Consumabile {
 private:
  static double plasticTax;
  float capacita;

 public:
  Bevanda();

  Bevanda(unsigned int, string, bool, double, unsigned int, double, QDate,
          float);

  /**
   * @brief: Ritorna la spesa sostenuta dalla pizzeria per l'acquisto di una
   * bevanda.
   * @return: double (spesa)
   */
  double getSpesa() const;

  /**
   * @brief: Ritorna la capacità di una bevanda
   * @return: double (capacità bevanda in L)
   */
  double getCapacita() const;

  /**
   * @brief: Ritorna la "plastic tax"
   * @return: double (costo extra per contenitori in plastica)
   */
  double getPlasticTax() const;

  /**
   * @brief: Modifica la "plastic tax"
   * @param: double (costo extra per contenitori in plastica)
   */
  void setPlasticTax(double);

  /**
   * @brief: Modifica la capacità della bevanda
   * @param: double (nuova capacità espressa in L)
   */
  void setCapacita(float);

  /**
   * @brief: Ritorna la composizione (la lista di consumabili) di una bevanda.
   * @note: Usata nella classe GestoreRisorse per impostare correttamente la
   * disponibilità della bevanda.
   */
  virtual const Lista<const Consumabile*>* getComposizione() const;

  /**
   * @brief: Metodo polimorfo di clonazione dell'oggetto
   * @returns: Farina* (puntatore a un nuovo oggetto creato di copia a partire
   * dall'oggetto di invocazione)
   */
  virtual void modifica(Risorsa*);

  /**
   * @brief: Effettua la deserializzazione dell'oggetto, assegnando ai campi
   * privati i valori corrispondenti contenuti nell'oggetto JSON.
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>* = nullptr);

  /**
   * @brief: Effettua la serializzazione dell'oggetto, salvando il contenuto dei
   * campi privati nell'oggetto JSON ricevuto come parametro.
   */
  virtual void salva(QJsonObject&) const;
};
#endif
