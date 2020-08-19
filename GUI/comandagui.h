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
  void rendiEseguita();
  uint getID() const;
  QTime getOraConsegna() const;

signals:
  void eliminaComanda(uint);


public slots:
  void showDetails();
  void enableButton();
  void removeClicked();

private:
  bool eseguita;
  uint ID;
  QTime oraConsegna;
  QString contenutoID;
  QString nomeCliente;
  QVBoxLayout* layoutComanda;
  QPushButton* wrapperComanda;
  QHBoxLayout* layoutButtons;
  QVBoxLayout* layoutWrapper;
  QPushButton* rimuovi;
  QPushButton* completata;
  PaginaComanda* dettagli;
};

#endif // COMANDAGUI_H
