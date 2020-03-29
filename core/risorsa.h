#include <string>
#include <QDate>

using std::string;

enum formatoPizza { normale, family, mezzo_metro, battuta };
enum farina { normale, integrale, kamut, farro };
enum formatoBevanda { bottiglia, lattina };
enum capacitaBevanda { CL33, CL50, CL66, L1 };

class Risorsa {
 private:
  string nome;
  bool disponibilita;

 public:
  Risorsa(string, bool);
  virtual ~Risorsa() = default;
  string& getNome() const;
  bool getDisponibilita() const;
  void setNome(const string&);
  void setDisponibilita(bool);
};
