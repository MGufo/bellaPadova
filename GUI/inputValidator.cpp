#include "inputValidator.h"

InputValidator::InputValidator() :
  intV(new QIntValidator(0, 999)),
  doubleV(new QDoubleValidator(0, 999, 3)),
  regEx(new QRegExp("^[a-zA-Z0-9]*$")),
  stringV(new QRegExpValidator(*regEx)) {}

void InputValidator::validate(QString value, QVariant valueType){
  int i = 0;
  switch(valueType.toInt()){
    case _int:{
        if(intV->validate(value, i) == QValidator::Invalid)
          throw new std::domain_error("Errore: Il numero inserito"
                                      " non può essere negativo");
      }
    case _double: {
        if(doubleV->validate(value, i) == QValidator::Invalid)
          throw new std::domain_error("Errore: Il numero inserito"
                                    " non può essere negativo");
      }
    case _string:{
        if(value.isEmpty())
          throw new std::domain_error("Errore: La stringa non può"
                                      " essere nulla");
        if(stringV->validate(value, i) == QValidator::Invalid)
          throw new std::domain_error("Errore: La stringa può contenere solo "
                                      "caratteri alfanumerici.");
      }
    case _data: {
        if(!(QDate::fromString(valueType.toString()).isValid()))
          throw new std::invalid_argument("Errore: La data inserita non"
                                          " rispetta il formato gg/mm/aaaa.");
      }
    default:{}
  }
}
