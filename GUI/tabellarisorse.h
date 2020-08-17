#ifndef TABELLARISORSE_H
#define TABELLARISORSE_H
#include "tabellacomposita.h"

class TabellaRisorse : public TabellaComposita {
  Q_OBJECT
public:
  TabellaRisorse(QWidget *parent = nullptr,
                 const QString& etichetta="",
                 const QStringList* = nullptr);
};

#endif // TABELLARISORSE_H
