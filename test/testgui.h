#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class testGUI : public QWidget{
  Q_OBJECT
public:
  testGUI(QWidget* parent = nullptr);

private:
  QVBoxLayout* layout;
};

class testLabel : public QWidget {
  Q_OBJECT
public:
  testLabel(QWidget* parent = nullptr, int = 2);
  int x;
private:
  QHBoxLayout* layout2;
};

class testButton : public QWidget {
  Q_OBJECT
public:
  testButton(QWidget* parent = nullptr, double = 3);
  double y;
private:
};
