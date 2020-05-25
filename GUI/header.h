#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>

class Header : public QWidget
{
  Q_OBJECT
public:
  explicit Header(QWidget *parent = nullptr);

private:
  QVBoxLayout* mainHeader;
  QHBoxLayout* navBarLayout;
  void drawHeader();
  void drawMenuBar();
  void drawNavBar();
};

#endif // HEADER_H
