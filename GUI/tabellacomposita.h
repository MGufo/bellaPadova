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
#include <QCheckBox>

#include "inputValidator.h"
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
  enum dataType {_int, _double, _string, _data};
  void setHeaderDimension(tipoTabella);

signals:
  //0: articolo; 1:consumabile
  void sendPacketToModel(pacchetto*, bool);
   //0: articolo; 1:consumabile
  void sendIdToModel(uint, bool);
  void validationError(const QString);

private slots:
  void emitDataOnCellChanged(int,int);
  void eliminaElemento(uint, bool);
  void checkBoxToggled(bool);
  void forwardIdToModel(uint);

protected:
  bool editabile;
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
  void validateInput(int, int);
  void setDefaultValue(int, int);
};

#endif // TABELLACOMPOSITA_H
