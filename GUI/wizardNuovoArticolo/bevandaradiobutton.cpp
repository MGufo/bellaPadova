#include "bevandaradiobutton.h"

BevandaRadioButton::BevandaRadioButton(uint idBevanda, QString nomeBevanda, double prezzoBevanda, double capacitaBevanda, QString formatoBevanda, QWidget* parent) : QRadioButton(parent), id(idBevanda), nome(nomeBevanda), prezzo(prezzoBevanda), capacita(capacitaBevanda), formato(formatoBevanda){}

uint BevandaRadioButton::getId() const{ return id;}

QString BevandaRadioButton::getNome() const{    return nome;}

double BevandaRadioButton::getPrezzo() const{   return prezzo;}

double BevandaRadioButton::getCapacita() const{ return capacita;}

QString BevandaRadioButton::getFormato() const{ return formato;}
