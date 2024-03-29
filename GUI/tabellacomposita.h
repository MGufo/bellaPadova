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
  void setHeaderDimension(tipoTabella);

private slots:
  void eliminaElemento(uint);
  void checkBoxToggled(bool);

protected:
  bool editabile;
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
};

#endif // TABELLACOMPOSITA_H
