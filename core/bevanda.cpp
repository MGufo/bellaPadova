#include "bevanda.h"

Bevanda(string nome = "acqua", bool disponibilita = true, double prezzo = 4.5,
        unsigned int qta, double costo = 10, QDate dataAcquisto,
        formatoBevanda fb = formatoBevanda::bottiglia,
        capacitaBevanda cb = capacitaBevanda::CL50)
    : Consumabile() formato(fb){};