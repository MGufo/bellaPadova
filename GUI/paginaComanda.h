#ifndef PAGINACOMANDA_H
#define PAGINACOMANDA_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QTimeEdit>
#include <QCloseEvent>

#include "tabellacomande.h"

class PaginaComanda : public QWidget {
  Q_OBJECT

public:
  PaginaComanda(QWidget* parent = nullptr, uint = 0);
  void setInfoComanda(const pacchettoComanda*, QList<pacchetto*>*);
  void smistaPacchettoInTabella(pacchetto*);

signals:
  void enableButton();
  void riempiTabelleConMenu(uint);
  void inviaComanda(pacchettoComanda*);
  void mostraErrore(const QString&);

public slots:
  void disableEdit();
private:
  uint comandaID;
  QGridLayout* layoutPaginaComanda;
  QHBoxLayout* layoutInfoComanda;
  QStringList* headerLabelsPizze;
  TabellaComande* Pizze;
  QStringList* headerLabelsBevande;
  TabellaComande* Bevande;
  QWidget* infoComanda;
  QTimeEdit* orario;
  const QTime* oldOrario;
  QLineEdit* nome;
  QLineEdit* indirizzo;
  QLineEdit* telefono;
  QLabel* totale;
  QPushButton* modificaDati;
  bool paginaEditabile;
  bool contenutoModificato;

  void inizializzaPizze(QWidget*);
  void inizializzaBevande(QWidget*);
  void inizializzaPulsante(QWidget*);
  void inizializzaInfoComanda(QWidget*);
  void creaPacchettoComanda();
  void setStylePaginaComanda();
  void closeEvent(QCloseEvent*) override;
  bool checkStatoInfo();

private slots:
  void toggleModifica();
  void modificaInfo(bool);
  void modificaTabelle(bool);
  void infoModificate();
  void orarioModificato(const QTime&);
  void tabellaModificata(); // da usare per segnalare una modifica alle tabelle
};

#endif // PAGINACOMANDA_H
