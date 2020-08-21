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
  PaginaComanda(QWidget* parent = nullptr, uint = 0);
  ~PaginaComanda();
  void setInfoComanda(const pacchettoComanda*, const QList<pacchetto*>*);
  void smistaPacchettoInTabella(pacchetto*);

signals:
  void enableButton();
  void riempiTabelleConMenu(uint);

private:
  uint comandaID;
  QGridLayout* layoutPaginaComanda;
  QHBoxLayout* layoutInfoComanda;
  TabellaComande* Pizze;
  TabellaComande* Bevande;
  QWidget* infoComanda;
  QLineEdit* orario;
  QLineEdit* nome;
  QLineEdit* indirizzo;
  QLineEdit* telefono;
  QLabel* totale;
  QPushButton* modificaDati;
  bool paginaEditabile;

  void inizializzaPizze(QWidget*);
  void inizializzaBevande(QWidget*);
  void inizializzaPulsante(QWidget*);
  void inizializzaInfoComanda(QWidget*);
  void setStylePaginaComanda();
  void closeEvent(QCloseEvent*) override;

private slots:
  void toggleModifica();
  void modificaInfo(bool);
  void modificaTabelle(bool);
};

#endif // PAGINACOMANDA_H
