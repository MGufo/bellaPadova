#include <string>
using std::string;

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  // costruttore
  Risorsa(string n, bool b = true);
  virtual ~Risorsa();
};