#include "gestoreRisorse.h"

GestoreRisorse::GestoreRisorse()
// TODO: costruire liste nello stack
    : menu(new Lista<Articolo*>()), inventario(new Lista<Consumabile*>()) {}
