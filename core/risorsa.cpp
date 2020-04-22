#include "risorsa.h"

#include <iostream>

Risorsa::Risorsa(string _nome, bool _disponibilita)
    : nome(_nome), disponibilita(_disponibilita) {}

string Risorsa::getNome() const { return nome; }

bool Risorsa::getDisponibilita() const { return disponibilita; }

void Risorsa::setNome(const string& n) { nome = n; }

void Risorsa::setDisponibilita(bool d) { disponibilita = d; }
