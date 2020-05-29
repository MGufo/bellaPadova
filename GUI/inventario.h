#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QTableWidget>
#include <QPushButton>

class Inventario : public QWidget
{
    Q_OBJECT
public:
    explicit Inventario(QWidget *parent = nullptr);

signals:

public slots:

private:
  QVBoxLayout* layoutInventario;
  void setStyleInventario();
};

#endif // INVENTARIO_H
