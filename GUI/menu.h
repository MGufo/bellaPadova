#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class Menu : public QWidget
{
  Q_OBJECT

private:
  QVBoxLayout* tmp;
  void setStyleMenu();

public:
  explicit Menu(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MENU_H
