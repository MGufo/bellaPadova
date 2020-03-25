enum formato { normale, family, mezzo_metro, battuta };
enum farina { normale, integrale, kamut, farro };
enum condimento { normale, bianca, rossa };

class Risorsa {
 public:
  String nome;
  bool disponibilita;
  ~Risorsa();
};

class Articolo : public Risorsa {
 public:
  double prezzo;
};

class Attrezzatura : public Risorsa {
 public:
  Fornitore fornitore;
  unsigned int quantita;
  double costo;
  Data dataAcquisto;
};

class Pizza : public Articolo {
 public:
  formato tipoFormato;
  contenitoreC<string> ingredienti() = 0;
};

class Fritto : public Articolo {
 public:
  formato tipoFormato;
  contenitoreC<string> ingredienti() = 0;
};

// classe concreta
class Frittura : public Fritto {
 public:
  farina tipoFarina;
  condimento tipoCondimento;
  pizzaFarcita(){};
  contenitoreC<string> ingredienti();
};

class Bevanda : public Attrezzatura {};

// classe concreta
class pizzaFarcita : public Pizza {
 public:
  farina tipoFarina;
  condimento tipoCondimento;
  pizzaFarcita(){};
  contenitoreC<string> ingredienti();
};

class Fornitore {};
