#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QString>
#include <QVariant>
#include <QIntValidator>
#include <QDoubleValidator>

class InputValidator{
private:
   enum dataType {_int, _double, _string, _data};
public:
  InputValidator();
  void validate(QString, QVariant);
};

#endif // INPUTVALIDATOR_H
