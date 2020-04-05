#include "ingrediente.h"

//un'istanza di questa classe rappresenta l'ingrediente farina, il quale viene usato per creare una pizza
//base e l'abbiamo implementato come classe in modo tale che sia più estensibile e gestibile nel tempo
//(è possibile inserire farine nuove nell'inventario e usarle per creare nuove pizze e modificarne 
//di esistenti senza modificare il modello logico)

class Farina : public Ingrediente {
 private:     
  string tipoFarina; 
 public:
  Farina(string = "farina", bool = true, unsigned int = 1, double, QDate = QDate::currentDate(), bool = false, 
  string = "normale");
  const string& getTipoFarina() const;
  void setTipoFarina(const string&);
};