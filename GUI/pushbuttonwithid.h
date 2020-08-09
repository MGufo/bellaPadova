#ifndef PUSHBUTTONWITHID_H
#define PUSHBUTTONWITHID_H

#include <QWidget>
#include <QPushButton>

class PushButtonWithId : public QPushButton
{
  Q_OBJECT
public:
  explicit PushButtonWithId(uint ID = 0, QWidget* parent = nullptr);
  void setId(uint);
private:
  uint id;
signals:
  void sendId(uint);
private slots:
  void emitIdOnButtonClicked();
};

#endif // PUSHBUTTONWITHID_H
