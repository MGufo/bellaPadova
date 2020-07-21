#ifndef TABELLACOMPOSITA_H
#define TABELLACOMPOSITA_H

#include <QWidget>
#include <QHeaderView>
#include <QLabel>
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>
#include "pacchetti.h"

class TabellaComposita : public QWidget
{
  Q_OBJECT
public:
  explicit TabellaComposita(QWidget *parent = nullptr, const QString& etichetta="", const QStringList* = nullptr);
  void inserisciElemento(pacchetto*);

signals:

public slots:

private:
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
};

#endif // TABELLACOMPOSITA_H
