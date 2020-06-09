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

class Comanda_GUI : public QWidget{
  Q_OBJECT
public:
  explicit Comanda_GUI(QWidget *parent = nullptr);

signals:

public slots:

private:
  QGridLayout* layoutComanda;

};

#endif // COMANDA_H
