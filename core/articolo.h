#ifndef ARTICOLO_H
#define ARTICOLO_H

#include "consumabile.h"
#include "qontainer.h"
#include "risorsa.h"

class Articolo : virtual public Risorsa {
 private:
  double prezzoBase;

 public:
  Articolo();
  /**
   * @brief: Costruttore di default
   * @param: string (nome dell'articolo)
   * @param: bool (disponibilità dell'articolo)
   * @param: double (costo dell'articolo)
   */
  Articolo(unsigned int, string, bool, double);

  /**
   * @brief: Ritorna il prezzo base di un articolo
   * @return: double prezzoBase
   */
  double getPrezzoBase() const;

  // TODO: Add exception se prezzo <= 0
  /**
   * @brief: Imposta il prezzo base di un articolo
   * @param: const double& (nuovo prezzo)
   */
  void setPrezzoBase(const double&);

  /**
   * @brief: Ritorna il prezzo finale di un articolo
   * @return: double prezzo
   */
  virtual double getPrezzo() const = 0;

  virtual const Lista<Consumabile*>* getComposizione() const = 0;

  /**
   * @brief: Legge i dati di una risorsa da file JSON e li assegna ai campi
   * dati dell'oggetto di invocazione
   * @param: const QJsonObject& (file da cui leggere)
   */
  virtual void carica(const QJsonObject&,
                      const std::unordered_map<uint, Risorsa*>* ) = 0;

  /**
   * @brief: Serializza l'oggetto di invocazione in un file JSON
   * @param: bool (nuova disponibilità)
   */
  virtual void salva(QJsonObject&) const = 0;
};
#endif
