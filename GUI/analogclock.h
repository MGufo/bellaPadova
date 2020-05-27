#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QPainter>

class analogClock : public QWidget{
  Q_OBJECT

public:
  explicit analogClock(QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent *event) override;
};

#endif // ANALOGCLOCK_H
