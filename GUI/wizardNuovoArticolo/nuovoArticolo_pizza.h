#ifndef NUOVOARTICOLO_PIZZA_H
#define NUOVOARTICOLO_PIZZA_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>

#include "ingredientecheckbox.h"

class NuovoArticolo_pizza: public QWidget{
  Q_OBJECT
public:
  NuovoArticolo_pizza(QWidget* parent = nullptr);

  QLineEdit* getNomePizza() const;
  QLineEdit* getPrezzoPizza() const;
  QWidget* getIngredientiCheckBoxWrapper() const;

private:
  QGridLayout* layoutPizza;
  QLineEdit* nomePizza;
  QLineEdit* prezzoPizza;
  QWidget* ingredientiCheckBoxWrapper;
};

#endif // WIZARD_PIZZA_H
