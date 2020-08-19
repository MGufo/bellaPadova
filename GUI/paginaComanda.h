#ifndef PAGINACOMANDA_H
#define PAGINACOMANDA_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QCloseEvent>

#include "tabellacomande.h"

class PaginaComanda : public QWidget {
  Q_OBJECT

public:
  PaginaComanda(QWidget* parent = nullptr);
  ~PaginaComanda();
  void setInfoComanda(const pacchettoComanda*);

signals:
  void enableButton();

private:
  QGridLayout* layoutPaginaComanda;
  QHBoxLayout* layoutInfoComanda;
  TabellaComande* Pizze;
  TabellaComande* Bevande;
  QWidget* infoComanda;
  QPushButton* newArticolo;
  QPushButton* modificaDati;

  void inizializzaPizze(QWidget*);
  void inizializzaBevande(QWidget*);
  void inizializzaPulsanti(QWidget*);
  void inizializzaInfoComanda(QWidget*);
  void setStylePaginaComanda();
  void closeEvent(QCloseEvent*) override;
};

#endif // PAGINACOMANDA_H
