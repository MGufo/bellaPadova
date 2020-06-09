#ifndef COMANDE_H
#define COMANDE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include "comanda_GUI.h"
class Comande : public QWidget{
  Q_OBJECT
public:
  explicit Comande(QWidget *parent = nullptr);

private:
  QVBoxLayout* comandeLayout;
  void setStyleComande();

signals:

public slots:

};

#endif // COMANDE_H
