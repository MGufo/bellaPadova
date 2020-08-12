#ifndef COMANDAGUI_H
#define COMANDAGUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>

#include "paginaComanda.h"

class ComandaGUI : public QWidget{
  Q_OBJECT
public:
  explicit ComandaGUI(QWidget *parent = nullptr);

signals:

public slots:
  showDetails();

private:
    QVBoxLayout* layoutComanda;
    paginaComanda* dettagli;
};

#endif // COMANDAGUI_H
