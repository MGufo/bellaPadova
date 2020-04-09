#include "articolo.h"
#include "container.h"
#include "ingrediente.h"

class Pizza : public Articolo {
 private:
  Lista<Ingrediente*>* ingredienti;
  static double extra;

 public:
  // Costruttore non usiamo valori di default perchè vengono tutti sempre
  // passati
  // per costruire l'oggetto
  Pizza(string nome, bool disponibilita, double prezzo,
        Lista<Ingrediente*>* ingr);
  // Costruttore di copia
  Pizza(const Pizza&);
  // Distruttore
  ~Pizza();
  // getter
  const Lista<Ingrediente*>& getIngredienti() const;
  string getTipoFarina() const;

  // setter
  void setTipoFarina(const string&);
  void addIngrediente(const string&);

  // implementazione metodo di clonazione (classe diventa concreta)
  // metodo da utilizzare per aggiungere una pizza del menu tra gli articoli di
  // una comanda
  Pizza* clone() const;
  double getPrezzo() const;
};
