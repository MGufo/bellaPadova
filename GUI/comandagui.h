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
  explicit ComandaGUI(QWidget *parent = nullptr, pacchettoComanda* = nullptr);

signals:

public slots:
  void showDetails();

private:
  uint ID;
  QTime oraConsegna;
  std::string nomeCliente;
  QVBoxLayout* layoutComanda;
  QPushButton* wrapperComanda;
  QPushButton* rimuovi;
  QPushButton* completata;
  PaginaComanda* dettagli;
};

#endif // COMANDAGUI_H
