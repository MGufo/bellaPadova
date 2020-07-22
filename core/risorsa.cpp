#include "risorsa.h"
#include <iostream>

Risorsa::Risorsa() {}

Risorsa::Risorsa(unsigned int _id, string _nome, bool _disponibilita)
    : ID(_id), nome(_nome), disponibilita(_disponibilita) {}

unsigned int Risorsa::getIdRisorsa() const{ return ID;}

string Risorsa::getNome() const { return nome; }

bool Risorsa::getDisponibilita() const { return disponibilita; }

void Risorsa::setNome(const string& n) { nome = n; }

void Risorsa::setDisponibilita(bool d) { disponibilita = d; }

void Risorsa::setID(unsigned int _id){ ID = _id; }
