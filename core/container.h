#include "risorsa.h"

template <class T>
class Lista {
    friend class Iteratore;
private:
    class Nodo{
    public:
        T* info;
        Nodo* next;
        Nodo* prev;
        Nodo(T* i, Nodo* n, Nodo* p): info(i), next(n), prev(p){}
    };

    Nodo* ptr;

public:

  Lista(): ptr(nullptr) {}

  Lista(const Lista& l){
      Nodo* l1 = l.ptr;
      ptr = new Nodo(new T(l1->info), nullptr, nullptr);
      Nodo* l2 = ptr;
      while(l1->next){
          l1 = l1->next;
          l2->next = new Nodo(new T(l1->info),l2,nullptr);
          l2 = l2->next;
      }
  }

  ~Lista() {
      Nodo* p;
      while(ptr){
          p = ptr;
          ptr = ptr->next;
          delete p;
      }
  }

  class Iteratore{
  friend class Lista;
  private:
      Lista::Nodo* punt;
  public:

      Iteratore(const T* p) : punt(p){}

      bool operator==(const Iteratore& i) const{
          return punt == i.punt;
      }

      bool operator!=(const Iteratore& i) const{
          return punt != i.punt;
      }

      const T& operator*() const {
        return *(punt->info);
      }

      T& operator*() {
        return *(punt->info);
      }

      //implemento

      Iteratore& operator++(){
      }

      Iteratore operator++(int){
      }

      Iteratore& operator--(){
      }

  };

  Lista& operator=(const Lista& v) {
  }

  //implemento

  const T& operator*() const {}

  T& operator*() {}

  Iteratore begin() const{}

  Iteratore end() const{}

  Iteratore erase(Iteratore it){}

  void clear(){}

  //push_back, pop_back, search
  void push_back(const T* p){}
};
