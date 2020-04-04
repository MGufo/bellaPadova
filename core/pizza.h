#include "articolo.h"
#include "container.h"

enum class formatoPizza { normale, family, mezzo_metro, battuta };
enum class farina { normale, integrale, kamut, farro };

class Pizza : public Articolo {
 private:
  formatoPizza tipoFormato;
  farina tipoFarina;
  Lista<Ingrediente*>* ingredienti;
  static double extra;
 public:
  // Costruttore di default, costruisce una pizza a impasto normale senza
  // ingredienti
  Pizza(string nome = "focaccia", bool disponibilita = true, double prezzo = 0,
        formatoPizza fo = formatoPizza::normale, farina fa = farina::normale,
        Lista<Ingrediente*>* ingr = nullptr);
  // Costruttore di copia
  Pizza(const Pizza&);
  // Distruttore
  ~Pizza();
  // getter
  formatoPizza getTipoFormato() const;
  const Lista<Ingrediente*>& getIngredienti() const;
  farina getTipoFarina() const;

  // setter
  void setTipoFormato(const unsigned int);
  void setTipoFarina(const unsigned int);
  void addIngrediente(const string&);

  // implementazione metodo di clonazione (classe diventa concreta)
  // metodo da utilizzare per aggiungere una pizza del menu tra gli articoli di
  // una comanda
  Pizza* clone() const;
  double getPrezzo() const;
};
