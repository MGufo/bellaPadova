#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "analogclock.h"

class Header : public QWidget
{
  Q_OBJECT
public:
  explicit Header(QWidget *parent = nullptr);

private:
  QHBoxLayout* headerLayout;
  void setStyleHeader();
};

#endif // HEADER_H
