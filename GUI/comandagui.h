#ifndef COMANDAGUI_H
#define COMANDAGUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>

class ComandaGUI : public QWidget{
  Q_OBJECT
public:
  explicit ComandaGUI(QWidget *parent = nullptr);

signals:

public slots:

private:
    QVBoxLayout* layoutComanda;
};

#endif // COMANDAGUI_H
