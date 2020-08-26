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

#include <core/utils.h>
#include "pacchetti.h"

class TabellaComposita : public QWidget {
  Q_OBJECT
public:
  explicit TabellaComposita(QWidget *parent = nullptr,
                            const QString& etichetta="",
                            const QStringList* = nullptr);
  void pulisciTabella();
  virtual void rendiEditabile(bool = true) = 0;
  void cambiaColoreBordoCella(bool = true);
  enum tipoTabella {bevandeM, bevandeI, inventario, pizze};
  enum dataType {_int, _double, _string, _data};
  void setHeaderDimension(tipoTabella);

signals:
  void validationError(const QString);

private slots:
  void eliminaElemento(uint);
  void checkBoxToggled(bool);

protected:
  bool editabile;
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
  void setDefaultValue(int, int);
};

#endif // TABELLACOMPOSITA_H
