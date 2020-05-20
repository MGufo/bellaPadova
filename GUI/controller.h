#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "pizzeria.h"

class Controller : public QObject {
  Q_OBJECT

 private:
  Pizzeria* pizzeria;

 public:
  explicit Controller(Pizzeria*, QObject* parent = nullptr);

 public slots:
};

#endif