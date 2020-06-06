#ifndef TABELLACOMPOSITA_H
#define TABELLACOMPOSITA_H

#include <QWidget>
#include <QHeaderView>
#include <QLabel>
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>

class TabellaComposita : public QWidget
{
  Q_OBJECT
public:
  explicit TabellaComposita(QWidget *parent = nullptr, const QString& etichetta="", const QStringList* = nullptr);

signals:

public slots:

private:
  QVBoxLayout* layoutTabellaComposita;
  void setStyleTabella();
};

#endif // TABELLACOMPOSITA_H
