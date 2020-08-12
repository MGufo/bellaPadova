#ifndef PAGINACOMANDA_H
#define PAGINACOMANDA_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
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
  QVBoxLayout* layoutPaginaComande;
  QHBoxLayout* layoutContenuto;
  QHBoxLayout* layoutPulsanti;
  TabellaComposita* Pizze;
  TabellaComposita* Bevande;
  QWidget* wrapperInfo;
  QWidget* wrapperContenuto;
  QWidget* wrapperPulsanti;
  QPushButton* newArticolo;
  QPushButton* modificaDati;

  void inizializzaPizze(QWidget*);
  void inizializzaBevande(QWidget*);
  void inizializzaWrapperInfo(QWidget*);
};

#endif // PAGINACOMANDA_H
