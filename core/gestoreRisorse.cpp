#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
    : menu(new Lista<Articolo*>()), inventario(new Lista<Consumabile*>()) {}