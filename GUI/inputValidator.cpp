#include "inputValidator.h"

InputValidator::InputValidator() {}

void InputValidator::validate(QString value, QVariant valueType){
  switch(valueType.toInt()){
    case _int:
        if(value.toInt() <= 0)
          throw new std::domain_error("Errore: Il numero inserito"
                                      " non può essere negativo");
    case _double: {

      }
    case _string:{

      }
    case _data: {

      }
    default:{}
  }
}
