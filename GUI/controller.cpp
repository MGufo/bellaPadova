#include "GUI/controller.h"

Controller::Controller(Pizzeria* bellaPadova, QObject* parent) :
  QObject(parent), modello(bellaPadova) {}


double Controller::calcoloFatturato(const QDate& inizio, const QDate& fine){
  return modello->contabilizzazione(inizio, fine);
}
