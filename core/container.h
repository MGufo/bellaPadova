template <class T>
class Lista {
  friend class Iteratore;

 private:
  class Nodo {
   public:
    T info;
    Nodo* next;
    Nodo* prev;
    Nodo(T i, Nodo* n, Nodo* p) : info(i), next(n), prev(p) {}
  };

  static Nodo* copy(Nodo* l1) {
    Nodo* first = new Nodo(*(new T(l1->info)), nullptr, nullptr);
    Nodo* l2 = first;
    while (l1->next) {
      l1 = l1->next;
      l2->next = new Nodo(*(new T(l1->info)), nullptr, l2);
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

    ~Iteratore(){ delete punt; }

    bool operator==(const Iteratore& i) const { return punt == i.punt; }

    bool operator!=(const Iteratore& i) const { return punt != i.punt; }

    const T& operator*() const { return punt->info; }

    T& operator*() { return punt->info; }
     
    const T* operator->() const { return &(punt->info); }

    T* operator->() { return &(punt->info); }

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

  const T& operator*() const { return ptr->info; }

  T& operator*() { return ptr->info; }

  bool isEmpty() const { return ptr == nullptr; }

  Iteratore begin() const { return Iteratore(ptr); }

  Iteratore end() const {
    Lista<T>::Iteratore it;
    for (it = this->begin();
         it.punt->next == nullptr && it.punt->prev != nullptr; ++it) {}
    return it;
  }

  Iteratore insert(Iteratore it, const T& p) {
    Nodo* temp = nullptr;
    // controllo validita iteratore
    if (!it.punt) {
      // se lista e vuota inseriamo un nuovo nodo come il primo della lista 
      // altrimenti non faccio nulla e alla fine ritorna un iteratore che punta nullptr
      if(isEmpty()){
        ptr = new Nodo(*(new T(p)), nullptr, nullptr);
        temp = ptr;
      }
    }
    // esistono sempre almeno 2 nodi (1 + past-the-end) perchè esiste l'iteratore che punta 
    // ad un nodo ed esiste pure il prev d questo nodo
    else if(it.punt->prev){
      temp = new Nodo(*(new T(p)), it.punt, it.punt->prev);
      it.punt->prev->next = temp;  // collegamento tra precedente e nuovo nodo
      it.punt->prev = temp;        // collegamento tra il successivo e nuovo nodo
    }
    else{
      temp = new Nodo(*(new T(p)), it.punt, nullptr);
      it.punt->prev = temp;
      ptr = temp; 
    }
    return Iteratore(temp);
  }

  Iteratore erase(Iteratore it) {
    if(it.punt){
      Nodo* temp = nullptr;
      if(it == begin()){
        temp = it.punt;
        ptr = (++it).punt;
        delete temp;
        return it;
      }
      else if(it == --end()){
        temp = it.punt;
        --it;
        it.punt->next = nullptr;
        delete temp;
        return ++it;
      }
      else{
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

  void push_back(const T& p) {
    insert(end(), p);
  }

  void pop_back() {
    erase(--end());
  }

  void push_front(const T& p){
    insert(begin(), p);
  }
  
  void pop_front(){
    erase(begin());
  }

  void clear() {
    if (ptr) {
      auto it = begin();
      while (it != end())
        it = erase(it);
    }
  }
};
