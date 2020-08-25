#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>

template <class T>
class Lista;

template <typename T>
std::ostream& operator<<(std::ostream&, const Lista<T>&);

template <class T>
class Lista {
  friend class Iterator;
  friend std::ostream& operator<< <T>(std::ostream&, const Lista&);

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

  class Iterator {
    friend class Lista;

   private:
    // puntatore al nodo interesssato
    Lista::Nodo* itrCurrent;
    // puntatore al nodo precedente
    Lista::Nodo* itrPrevious;

   public:
    Iterator(Lista::Nodo* cu = nullptr, Lista::Nodo* pr = nullptr)
        : itrCurrent(cu), itrPrevious(pr) {}

    bool operator==(const Iterator& i) const {
      return (itrCurrent == i.itrCurrent) && (itrPrevious == i.itrPrevious);
    }

    bool operator!=(const Iterator& i) const {
      return (itrCurrent != i.itrCurrent) || (itrPrevious != i.itrPrevious);
    }

    T& operator*() const { return itrCurrent->info; }

    T* operator->() const { return &(itrCurrent->info); }

    Iterator& operator++() {
      Nodo* temp = itrCurrent;
      itrCurrent = itrCurrent->nodoNext;
      itrPrevious = temp;
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp(itrCurrent, itrPrevious);
      ++(*this);
      return temp;
    }

    Iterator& operator--() {
      if(itrPrevious) itrCurrent = itrPrevious;
      else itrCurrent = itrCurrent->nodoPrev;
      if (itrCurrent) {
        itrPrevious = itrCurrent->nodoPrev;
      } else
        itrPrevious = nullptr;
      return *this;
    }

    bool isValid() const { return (itrCurrent != nullptr); }
  };

  class const_Iterator {
    friend class Lista;

   private:
    // puntatore al nodo interesssato
    const Lista::Nodo* itrCurrent;
    // puntatore al nodo precedente
    const Lista::Nodo* itrPrevious;

   public:
    const_Iterator(const Lista::Nodo* cu = nullptr,
                   const Lista::Nodo* pr = nullptr)
        : itrCurrent(cu), itrPrevious(pr) {}

    bool operator==(const const_Iterator& i) const {
      return (itrCurrent == i.itrCurrent) && (itrPrevious == i.itrPrevious);
    }

    bool operator!=(const const_Iterator& i) const {
      return (itrCurrent != i.itrCurrent) || (itrPrevious != i.itrPrevious);
    }

    const T& operator*() const { return itrCurrent->info; }

    const T* operator->() const { return &(itrCurrent->info); }

    const_Iterator& operator++() {
      const Nodo* temp = itrCurrent;
      itrCurrent = itrCurrent->nodoNext;
      itrPrevious = temp;
      return *this;
    }

    const_Iterator operator++(int) {
      const_Iterator temp(itrCurrent, itrPrevious);
      ++(*this);
      return temp;
    }

    const_Iterator& operator--() {
      itrCurrent = itrPrevious;
      if (itrCurrent) {
        itrPrevious = itrCurrent->nodoPrev;
      } else
        itrPrevious = nullptr;
      return *this;
    }

    bool isValid() const { return (itrCurrent != nullptr); }
  };

  Lista& operator=(const Lista& v) {
    if (this != &v) {
      destroy(ptr);
      ptr = copy(v.ptr);
    }
    return *this;
  }

  // HACK: la & dev'essere adiacente a p!
  Lista<T>::Iterator find(const T &valore) const {
    Lista<T>::Iterator it;
    for (it = begin(); it != end(); ++it)
      if (*it == valore) return it;
    return it;
  }

  bool isEmpty() const { return ptr == nullptr; }

  Iterator begin() const { return Iterator(ptr, nullptr); }

  const_Iterator const_begin() const { return const_Iterator(ptr, nullptr); }

  Iterator end() const {
    Lista<T>::Iterator it;
    if (!isEmpty()) {
      it = begin();
      while (it.itrCurrent != nullptr) {
        ++it;
      }
    }
    return it;
  }

  const_Iterator const_end() const {
    Lista<T>::const_Iterator it;
    if (!isEmpty()) {
      it = const_begin();
      while (it.itrCurrent != nullptr) {
        ++it;
      }
    }
    return it;
  }
  // HACK: la & dev'essere adiacente a p!
  Iterator insert(Iterator it, const T &p) {
    Nodo* temp = nullptr;
    // controllo validita iteratore
    if (!it.itrCurrent && !it.itrPrevious) {
      // se lista e vuota inseriamo un nuovo nodo come il primo della lista
      // altrimenti non faccio nulla e alla fine ritorna un Iteratorche punta
      // nullptr
      if (isEmpty()) {
        ptr = new Nodo(p, nullptr, nullptr);
        temp = ptr;
      }
    }
    // esistono sempre almeno 2 nodi (2 + past-the-end) perchè esiste
    // l'Iteratorche punta ad un nodo ed esiste pure il nodoPrev di questo
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
    return Iterator(temp, temp->nodoPrev);
  }

  Iterator erase(Iterator it) {
    if (it.itrCurrent) {
      Nodo* temp = nullptr;
      if (it == begin()) {
        temp = it.itrCurrent;
        ++it;
        //aggiusto puntatori ai nodi precedenti
        it.itrPrevious = nullptr;
        if(it.itrCurrent)   it.itrCurrent->nodoPrev = nullptr;
        ptr = it.itrCurrent;
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
        // iteratore che punta al nodo successivo a quello da eliminare
        Iterator ritorno(it.itrCurrent->nodoNext, it.itrCurrent);
        // iteratore che punta al nodo precedente a quello da eliminare
        --it;
        it.itrCurrent->nodoNext = ritorno.itrCurrent;
        // aggiornamento dell'iteratore
        ritorno.itrPrevious = it.itrCurrent;
        // aggiornamento della lista
        ritorno.itrCurrent->nodoPrev = it.itrCurrent;
        delete temp;
        return ritorno;
      }
    }
    return Iterator();
  }
  // HACK: la & dev'essere adiacente a p!
  void push_back(const T &p) { insert(end(), p); }

  void pop_back() { erase(--end()); }
  // HACK: la & dev'essere adiacente a p!
  void push_front(const T &p) { insert(begin(), p); }

  void pop_front() { erase(begin()); }

  void clear() {
    if (ptr) {
      auto it = begin();
      while (it != end()) it = erase(it);
    }
  }
  int count() const{
    int count = 0;
    for(auto it = const_begin(); it != const_end(); ++it) ++count;
    return count;
  }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista) {
  typename Lista<T>::const_Iterator it;
  os << "La lista contiene: ";
  os << "[";
  for (it = lista.const_begin(); it != lista.const_end(); ++it) {
    os << *it << ((it == --(lista.const_end())) ? "" : ", ");
  }
  os << "] \n";
  return os;
}

#endif
