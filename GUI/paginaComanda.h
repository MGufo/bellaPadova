#ifndef PAGINACOMANDA_H
#define PAGINACOMANDA_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>

#include "tabellacomposita.h"

class PaginaComanda : public QWidget {
  Q_OBJECT

public:
  PaginaComanda(QWidget* parent = nullptr);
  ~PaginaComanda();

private:
  QGridLayout* layoutPaginaComanda;
  QHBoxLayout* layoutInfoComanda;
  TabellaComposita* Pizze;
  TabellaComposita* Bevande;
  QWidget* infoComanda;
  QPushButton* newArticolo;
  QPushButton* modificaDati;

  void inizializzaPizze(QWidget*);
  void inizializzaBevande(QWidget*);
  void inizializzaPulsanti(QWidget*);
  void inizializzaInfoComanda(QWidget*);
};

#endif // PAGINACOMANDA_H
