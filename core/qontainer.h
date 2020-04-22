#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>

template <class T>
class Lista {
  friend class Iteratore;

 private:
  class Nodo {
   public:
    // campo dati
    T info;
    // puntatore al nodo successivo
    Nodo* nodoNext;
    // puntatore al nodo precedente
    Nodo* nodoPrev;
    Nodo(const T& i, Nodo* n, Nodo* p) : info(i), nodoNext(n), nodoPrev(p) {}
  };

  Nodo* ptr;

  static Nodo* copy(Nodo* l1) {
    Nodo* first = new Nodo(T(l1->info), nullptr, nullptr);
    Nodo* l2 = first;
    while (l1->nodoNext) {
      l1 = l1->nodoNext;
      l2->nodoNext = new Nodo(T(l1->info), nullptr, l2);
      l2 = l2->nodoNext;
    }
    return first;
  }

  static void destroy(Nodo* p) {
    Nodo* temp;
    while (p) {
      temp = p;
      p = p->nodoNext;
      delete temp;
    }
  }

 public:
  Lista() : ptr(nullptr) {}

  Lista(const Lista& l) : ptr(copy(l.ptr)) {}

  ~Lista() { destroy(ptr); }

  class Iteratore {
    friend class Lista;

   public:
    // puntatore al nodo interesssato
    Lista::Nodo* itrCurrent;
    // puntatore al nodo precedente
    Lista::Nodo* itrPrevious;

    Iteratore(Lista::Nodo* pu, Lista::Nodo* pr)
        : itrCurrent(pu), itrPrevious(pr) {}

    bool operator==(const Iteratore& i) const {
      return (itrCurrent == i.itrCurrent) && (itrPrevious == i.itrPrevious);
    }

    bool operator!=(const Iteratore& i) const {
      return (itrCurrent != i.itrCurrent) || (itrPrevious != i.itrPrevious);
    }

    const T& operator*() const { return itrCurrent->info; }

    T& operator*() { return itrCurrent->info; }

    const T* operator->() const { return &(itrCurrent->info); }

    T* operator->() { return &(itrCurrent->info); }

    Iteratore& operator++() {
      Nodo* temp = itrCurrent;
      itrCurrent = itrCurrent->nodoNext;
      itrPrevious = temp;
      return *this;
    }

    Iteratore operator++(int) {
      Iteratore temp(itrCurrent, itrPrevious);
      ++(*this);
      return temp;
    }

    Iteratore& operator--() {
      itrCurrent = itrPrevious;
      if (itrCurrent) {
        itrPrevious = itrCurrent->nodoPrev;
      } else {
        itrPrevious = nullptr;
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
      while (it.itrCurrent != nullptr) {
        ++it;
      }
    }
    return it;
  }

  Iteratore insert(Iteratore it, const T& p) {
    Nodo* temp = nullptr;
    // controllo validita iteratore
    if (!it.itrCurrent && !it.itrPrevious) {
      // se lista e vuota inseriamo un nuovo nodo come il primo della lista
      // altrimenti non faccio nulla e alla fine ritorna un iteratore che punta
      // nullptr
      if (isEmpty()) {
        ptr = new Nodo(p, nullptr, nullptr);
        temp = ptr;
      }
    }
    // esistono sempre almeno 2 nodi (2 + past-the-end) perchè esiste
    // l'iteratore che punta ad un nodo ed esiste pure il nodoPrev di questo
    // nodo
    else if (it.itrPrevious) {
      temp = new Nodo(p, it.itrCurrent, it.itrPrevious);
      it.itrPrevious->nodoNext =
          temp;  // collegamento tra precedente e nuovo nodo
      if (it.itrCurrent)
        it.itrCurrent->nodoPrev =
            temp;  // collegamento tra il successivo e nuovo nodo
    } else {
      temp = new Nodo(p, it.itrCurrent, nullptr);
      it.itrCurrent->nodoPrev = temp;
      ptr = temp;
    }
    return Iteratore(temp, temp->nodoPrev);
  }

  Iteratore erase(Iteratore it) {
    if (it.itrCurrent) {
      Nodo* temp = nullptr;
      if (it == begin()) {
        temp = it.itrCurrent;
        ptr = (++it).itrCurrent;
        delete temp;
        return it;
      } else if (it == --end()) {
        temp = it.itrCurrent;
        --it;
        it.itrCurrent->nodoNext = nullptr;
        delete temp;
        return ++it;
      } else {
        temp = it.itrCurrent;
        Iteratore ritorno(it.itrCurrent->nodoPrev);
        --it;
        it.itrCurrent->nodoNext = ritorno.itrCurrent;
        ritorno.itrCurrent->nodoPrev = it.itrCurrent;
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
