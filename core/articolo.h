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
  /**
   * @brief: Restituisce la lista di ingredienti presenti nell'articolo di
   * invocazione.
   */
  virtual const Lista<const Consumabile*>* getComposizione() const = 0;
};
#endif
