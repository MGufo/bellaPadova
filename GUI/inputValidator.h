#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QDate>
#include <QString>
#include <QVariant>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegExpValidator>

class InputValidator{
private:
   enum dataType {_int, _double, _string, _data};
   QIntValidator* intV;
   QDoubleValidator* doubleV;
   QRegExp* regEx;
   QRegExpValidator* stringV;
public:
  InputValidator();
  void validate(QString, QVariant);
};

#endif // INPUTVALIDATOR_H
