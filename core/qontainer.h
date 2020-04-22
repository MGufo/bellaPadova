#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>
#include <typeinfo>

#include "ingrediente.h"

template <class T>
class Lista {
  friend class Iteratore;

 private:
  class Nodo {
   public:
    T info;
    Nodo* next;
    Nodo* prev;
    Nodo(const T& i, Nodo* n, Nodo* p) : info(i), next(n), prev(p) {}
  };

  static Nodo* copy(Nodo* l1) {
    Nodo* first = new Nodo(T(l1->info), nullptr, nullptr);
    Nodo* l2 = first;
    while (l1->next) {
      l1 = l1->next;
      l2->next = new Nodo(T(l1->info), nullptr, l2);
      l2 = l2->next;
    }
    return first;
  }

  static void destroy(Nodo* p) {
    Nodo* temp;
    while (p) {
      temp = p;
      p = p->next;
      delete temp;
    }
  }

  Nodo* ptr;

 public:
  Lista() : ptr(nullptr) {}

  Lista(const Lista& l) : ptr(copy(l.ptr)) {}

  ~Lista() { destroy(ptr); }

  class Iteratore {
    friend class Lista;

   private:
   public:
    // puntatore al nodo interesssato
    Lista::Nodo* punt;
    // puntatore al nodo precedente
    Lista::Nodo* prec;

    Iteratore(Lista::Nodo* pu, Lista::Nodo* pr) : punt(pu), prec(pr) {}

    bool operator==(const Iteratore& i) const {
      return (punt == i.punt) && (prec == i.prec);
    }

    bool operator!=(const Iteratore& i) const {
      return (punt != i.punt) || (prec != i.prec);
    }

    const T& operator*() const { return punt->info; }

    T& operator*() { return punt->info; }

    const T* operator->() const { return &(punt->info); }

    T* operator->() { return &(punt->info); }

    Iteratore& operator++() {
      Nodo* temp = punt;
      punt = punt->next;
      prec = temp;
      return *this;
    }

    Iteratore operator++(int) {
      Iteratore temp(punt, prec);
      ++(*this);
      return temp;
    }

    Iteratore& operator--() {
      punt = prec;
      if (punt) {
        prec = punt->prev;
      } else {
        prec = nullptr;
      }
      return *this;
    }
  };

  Lista& operator=(const Lista& v) {
    if (this != &v) {
      destroy(ptr);
      ptr = copy(v.ptr);
    }
    return *this;
  }

  const T& operator*() const { return ptr->info; }

  T& operator*() { return ptr->info; }

  bool isEmpty() const { return ptr == nullptr; }

  Iteratore begin() const { return Iteratore(ptr, nullptr); }

  Iteratore end() const {
    Lista<T>::Iteratore it(nullptr, nullptr);
    if (!isEmpty()) {
      it = begin();
      while (it.punt != nullptr) {
        ++it;
      }
    }
    return it;
  }

  Iteratore insert(Iteratore it, const T& p) {
    Nodo* temp = nullptr;
    // controllo validita iteratore
    if (!it.punt && !it.prec) {
      // se lista e vuota inseriamo un nuovo nodo come il primo della lista
      // altrimenti non faccio nulla e alla fine ritorna un iteratore che punta
      // nullptr
      if (isEmpty()) {
        ptr = new Nodo(p, nullptr, nullptr);
        // std::cout << ptr->info->getCosto() << std::endl;
        temp = ptr;
      }
    }
    // esistono sempre almeno 2 nodi (2 + past-the-end) perchè esiste
    // l'iteratore che punta ad un nodo ed esiste pure il prev di questo nodo
    else if (it.prec) {
      temp = new Nodo(p, it.punt, it.prec);
      it.prec->next = temp;  // collegamento tra precedente e nuovo nodo
      if (it.punt)
        it.punt->prev = temp;  // collegamento tra il successivo e nuovo nodo
    } else {
      temp = new Nodo(p, it.punt, nullptr);
      it.punt->prev = temp;
      ptr = temp;
    }
    return Iteratore(temp, temp->prev);
  }

  Iteratore erase(Iteratore it) {
    if (it.punt) {
      Nodo* temp = nullptr;
      if (it == begin()) {
        temp = it.punt;
        ptr = (++it).punt;
        delete temp;
        return it;
      } else if (it == --end()) {
        temp = it.punt;
        --it;
        it.punt->next = nullptr;
        delete temp;
        return ++it;
      } else {
        temp = it.punt;
        Iteratore ritorno(it.punt->prev);
        --it;
        it.punt->next = ritorno.punt;
        ritorno.punt->prev = it.punt;
        delete temp;
        return ritorno;
      }
    }
    return Iteratore(nullptr);
  }

  void push_back(const T& p) { insert(end(), p); }

  void pop_back() { erase(--end()); }

  void push_front(const T& p) { insert(begin(), p); }

  void pop_front() { erase(begin()); }

  void clear() {
    if (ptr) {
      auto it = begin();
      while (it != end()) it = erase(it);
    }
  }
};

#endif
