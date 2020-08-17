#ifndef TABELLACOMANDE_H
#define TABELLACOMANDE_H

#include "tabellacomposita.h"

class TabellaComande : public TabellaComposita {
  Q_OBJECT
public:
  TabellaComande(QWidget *parent = nullptr,
                 const QString& etichetta="",
                 const QStringList* = nullptr);
};

#endif // TABELLACOMANDE_H
