#ifndef TABELLACOMPOSITA_H
#define TABELLACOMPOSITA_H

#include <QWidget>
#include <QHeaderView>
#include <QLabel>
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "pacchetti.h"
#include "pushbuttonwithid.h"

class TabellaComposita : public QWidget {
  Q_OBJECT
public:
  explicit TabellaComposita(QWidget *parent = nullptr,
                            const QString& etichetta="",
                            const QStringList* = nullptr);
  void pulisciTabella();
  void inserisciElemento(pacchetto*);
  void rendiEditabile(bool = true);
  void cambiaColoreBordoCella(bool = true);
  enum tipoTabella {bevandeM, bevandeI, inventario, pizze};
  void setHeaderDimension(tipoTabella);

signals:
  void sendPacketToModel(pacchetto*);
  void sendIdToModel(uint);

private slots:
  void emitDataOnCellChanged(int,int);
  void eliminaElemento(uint);

private:
  bool editabile;
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
};

#endif // TABELLACOMPOSITA_H
