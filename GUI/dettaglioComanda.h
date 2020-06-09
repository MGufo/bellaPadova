#ifndef COMANDA_GUI_H
#define COMANDA_GUI_H

#include <QWidget>
#include <QFormLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QScrollArea>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>

class dettaglioComanda: public QWidget{
  Q_OBJECT
public:
  explicit dettaglioComanda(QWidget *parent = nullptr);

signals:

public slots:

private:
  QVBoxLayout* layoutComanda;

};

#endif // COMANDA_H
