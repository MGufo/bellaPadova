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
  void eliminaComanda(uint);


public slots:
  void showDetails();
  void enableButton();
  void removeClicked();
  void completedClicked();

private:
  bool eseguita;
  uint ID;
  QTime oraConsegna;
  QString nomeCliente;
  QVBoxLayout* layoutComanda;
  QPushButton* wrapperComanda;
  QPushButton* rimuovi;
  QPushButton* completata;
  PaginaComanda* dettagli;
};

#endif // COMANDAGUI_H
