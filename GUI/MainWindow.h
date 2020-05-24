#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();


private:
  QVBoxLayout *mainLayout;
  QHBoxLayout* navBar;
  void addNavBar();
  void addMenu();
  void setStyle();
};

#endif
