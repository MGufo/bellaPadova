#include "risorsa.h"

//esempio: Vettore<Articolo*>
//TODO: sostituire _size con campo dati size di Vettore
template <class T, unsigned int _size = 0>
class Vettore {
private:
  T* ptr;
public:

  //da controllare
  class Iteratore{
  friend class Vettore;
  private:
      const T* punt;
  public:

      Iteratore(const T* p) : punt(p){}

      bool operator==(const Iteratore& i) const{
          return punt == i.punt;
      }

      bool operator!=(const Iteratore& i) const{
          return punt != i.punt;
      }

      Iteratore& operator++(){
          if(punt){
              ++punt;
          }
          return *this;
      }

      Iteratore& operator--(){
          if(punt){
              --punt;
          }
          return *this;
      }

      const T& operator[](unsigned int i) const {
        return punt[i];
      }

      T& operator[](unsigned int i) {
        return punt[i];
      }

      const T& operator*() const {
        return punt[0];
      }

      T& operator*() {
        return punt[0];
      }

  };

  //TODO
  Iteratore begin() const{
  }
  Iteratore end() const{
  }

  Vettore::Iteratore erase(Vettore::Iteratore it);
  void clear();
  //push_back, pop_back, search

  Vettore(): ptr(_size == 0 ? nullptr : new T[_size]){}

  Vettore(const Vettore& v) : ptr(new T[_size]){
    for(int i=0; i<_size; ++i){
        ptr[i]=*(v.(ptr[i]).clone());
    }
  }

  Vettore& operator=(const Vettore& v) {
    if(this != &v) {
      delete[] ptr;
      ptr = _size == 0 ? nullptr : new T[_size];
      for(int i=0; i<_size; ++i){
          ptr[i]=*(v.(ptr[i]).clone());
      }
    }
    return *this;
  }

  ~Vettore() {
    delete[] ptr;
  }

  //controllo
  const T& operator[](unsigned int i) const {
    return ptr[i];
  }

  T& operator[](unsigned int i) {
    return ptr[i];
  }

  const T& operator*() const {
    return ptr[0];
  }

  T& operator*() {
    return ptr[0];
  }

};
