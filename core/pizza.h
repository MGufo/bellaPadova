#include "articolo.h"
class Pizza : public Articolo {
 private:
  formatoPizza tipoFormato;
  contenitoreC<string>* ingredienti;
  farina tipoFarina;

 public:
  // Costruttore di default, costruisce una pizza a impasto normale senza
  // ingredienti
  Pizza(string nome = "focaccia", bool disponibilita = true, double prezzo = 0,
        formatoPizza fo = formatoPizza::normale,
        contenitoreC<string>* ingr = nullptr, farina fa = farina::normale)
      : Articolo(nome, disponibilita, prezzo),
        tipoFormato(fo),
        ingredienti(ingr ? new contenitoreC<string>(ingr) : nullptr),
        tipoFarina(fa){};
  // Costruttore di copia
  // TODO: Implementare copia profonda
  Pizza(const Pizza&);
  // Distruttore
  //TODO: Implementare distruttore profondo
  ~Pizza();
  // getter
  string getTipoFormato() const;
  contenitoreC<string> getIngredienti() const;
  string getTipoFarina() const;

  // setter
  void setTipoFormato(const unsigned int);
  void setIngredienti(const string);
  void setTipoFarina(const unsigned int);
};