#include <string>
using std::string;

class Contatto {
 private:
  string nome;
  string indirizzo;
  string telefono;

 public:
  void setNome(const string&);
  void setIndirizzo(const string&);
  void setTelefono(const string&);

  string getNome() const;
  string getIndirizzo() const;
  string getTelefono() const;
};
