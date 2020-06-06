#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include "GUI/tabellacomposita.h"


class Menu : public QWidget
{
  Q_OBJECT

private:
  QVBoxLayout* layoutMenu;
  void setStyleMenu();

public:
  explicit Menu(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MENU_H
