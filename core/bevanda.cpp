#include "bevanda.h"

Bevanda::Bevanda(string nome, bool disponibilita, double prezzo,
        unsigned int qta, double costo, QDate dataAcquisto,
        formatoBevanda fb,
        capacitaBevanda cb)
        : Risorsa(nome, disponibilita), Articolo(nome, disponibilita, prezzo), Consumabile(nome, disponibilita, qta, costo, dataAcquisto),
          formato(fb), capacita(cb){}

