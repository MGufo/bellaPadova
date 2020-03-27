#include <queue>
#include <string>
enum formatoPizza { normale, family, mezzo_metro, battuta };
enum farina { normale, integrale, kamut, farro };
enum formatoBevanda {
  bottiglia33cl,
  bottiglia50cl,
  bottiglia1L,
  lattina33cl,
  lattina50cl
};
enum tipoFornitore { mercato, supermercato, azienda, altro };

using std::priority_queue;
using std::string;

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  virtual ~Risorsa();
};

class Articolo : virtual public Risorsa {
 private:
  double prezzo;
};

class Attrezzatura : virtual public Risorsa {
 private:
  Fornitore fornitore;
  unsigned int quantita;
  double costo;
  // TODO: Import data library
  // Data dataAcquisto;
};

class Bevanda : public Articolo, public Attrezzatura {
 private:
  formatoBevanda formato;
};

class Ingrediente : public Attrezzatura {};

class Strumentazione : public Attrezzatura {};

class Pizza : public Articolo {
 private:
  formatoPizza tipoFormato;
  // contenitoreC<string>* ingredienti;
  farina tipoFarina;

 public:
  // Costruttore di default, costruisce una pizza a impasto normale senza
  // ingredienti
  Pizza(formatoPizza fo =
            formatoPizza::normale,  // contenitoreC<string>* ingr = nullptr,
        farina fa = farina::normale)
      : tipoFormato(fo),
        // ingredienti(ingr ? new //contenitoreC<string>(ingr) : nullptr),
        tipoFarina(fa){};

  // getter
  string getTipoFormato() const;
  // contenitoreC<string> getIngredienti() const;
  string getTipoFarina() const;

  // setter
  void setTipoFormato(const unsigned int);
  void setIngredienti(const string);
  void setTipoFarina(const unsigned int);
};

class Anagrafica {
 private:
  string indirizzo;
  string telefono;
};

class Cliente {
 private:
  string nome;
  Anagrafica recapito;
};

class Fornitore {
 private:
  string nome;
  Anagrafica recapito;
  tipoFornitore tipologia;
};

class Comanda {
 private:
  // TODO: Verificare se si possano usare le mappe STL
  // contenitoreC<Articolo*> articoli;
  // contenitoreC<unsigned int> quantita;
  Cliente cliente;
  bool omaggio;
  bool domicilio;
  // Data data;
  // Time orario;
};

class GestioneComande {
 private:
  priority_queue<Comanda> coda;
  // TODO: Metodi per la gestione della coda
};

class Menu {
 private:
  // contenitoreC<Articolo*> articoli;
};

class Pizzeria {
 private:
  string nome;
  Anagrafica contatto;
  string pIVA;
  // contenitoreC<Risorsa*> inventario;
  Menu* menu;
};
