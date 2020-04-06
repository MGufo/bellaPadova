#include "gestore.h"

Gestore::Gestore() : menu(new Lista<Articolo*>()), inventario(new Lista<Consumabile*>()){}