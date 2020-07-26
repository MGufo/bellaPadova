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
#include <sstream>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

class TabellaComposita : public QWidget
{
  Q_OBJECT
public:
  explicit TabellaComposita(QWidget *parent = nullptr, const QString& etichetta="", const QStringList* = nullptr);
  void inserisciElemento(pacchetto*);
  void rendiEditabile(bool = true);

signals:
  void sendPacketToModel(pacchetto*);

private slots:
  void emitDataOnCellChanged(int,int);

private:
  bool editabile;
  QHeaderView* header = nullptr;
  QTableWidget* tabella = nullptr;
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
};

#endif // TABELLACOMPOSITA_H
