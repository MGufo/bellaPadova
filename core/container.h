template <class T>
class Lista {
  friend class Iteratore;

 private:
  class Nodo {
   public:
    T* info;
    Nodo* next;
    Nodo* prev;
    Nodo(T* i, Nodo* n, Nodo* p) : info(i), next(n), prev(p) {}
  };

  static Nodo* copy(Nodo* l1) {
    Nodo* first = new Nodo(new T(l1->info), nullptr, nullptr);
    Nodo* l2 = first;
    while (l1->next) {
      l1 = l1->next;
      l2->next = new Nodo(new T(l1->info), nullptr, l2);
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
    Lista::Nodo* punt;

   public:
    Iteratore(const Lista::Nodo* p) : punt(p) {}

    bool operator==(const Iteratore& i) const { return punt == i.punt; }

    bool operator!=(const Iteratore& i) const { return punt != i.punt; }

    const T& operator*() const { return *(punt->info); }

    T& operator*() { return *(punt->info); }

    Iteratore& operator++() { punt = punt->next; }

    Iteratore operator++(int) {
      Iteratore temp(*this->punt);
      ++(*this);
      return temp;
    }

    Iteratore& operator--() { punt = punt->prev; }
  };

  Lista& operator=(const Lista& v) {
    if (this != &v) {
      destroy(ptr);
      ptr = copy(v.ptr);
    }
    return *this;
  }

  const T& operator*() const { return *(ptr->info); }

  T& operator*() { return *(ptr->info); }

  bool isEmpty() const { return ptr == nullptr; }

  Iteratore begin() const { return Iteratore(ptr); }

  Iteratore end() const {
    for (auto it = this->begin();
         it.punt->next == nullptr && it.punt->prev != nullptr; ++it) {
    }
    return it;
  }

  Iteratore insert(Iteratore it, const T* p) {
    // esistono sempre almeno 2 nodi (1 + past-the-end)
    Nodo* temp = new Nodo(new T(*p), it.punt, it.punt->prev);
    it.punt->prev->next = temp;  // collegamento tra precedente e nuovo nodo
    it.punt->prev = temp;        // collegamento tra il successivo e nuovo nodo
    return Iteratore(temp);
  }

  Iteratore erase(Iteratore pt) {
    Iteratore temp(pt.punt->prev);
    temp.punt->next = pt.punt->next;  // collegamento tra precedente e
                                      // successivo
    pt.punt->next->prev = temp.punt;  // collegamento inverso
    delete pt.punt;
    return ++temp;
  }

  void push_back(const T* p) {
    if (isEmpty()) {
      ptr = new Nodo(new T(*p), nullptr, nullptr);
    } else {
      insert(this->end(), p);
    }
  }

  void pop_back() {
    if (!isEmpty()) {
      this->erase(--this->end());
    }
  }

  // TODO: push_front
  // TODO: pop_front

  void clear() {
    if (ptr) {
      auto it = this->begin();
      while (it != this->end()) {
        it = this->erase(it);
      }
    }
  }
};
