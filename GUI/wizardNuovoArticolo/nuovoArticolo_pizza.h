#ifndef NUOVOARTICOLO_PIZZA_H
#define NUOVOARTICOLO_PIZZA_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>


class NuovoArticolo_pizza: public QWidget{
  Q_OBJECT
public:
  NuovoArticolo_pizza(QWidget* parent = nullptr);
  QLineEdit* getNomePizza() const;
  QLineEdit* getPrezzoPizza() const;

private:
  QVBoxLayout* layoutPizza;
  QLineEdit* nomePizza;
  QLineEdit* prezzoPizza;
  QTableWidget* ingredientiWrapper;
  QTableWidget* farineWrapper;
};

#endif // WIZARD_PIZZA_H
