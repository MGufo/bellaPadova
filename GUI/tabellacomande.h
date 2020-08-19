#ifndef TABELLACOMANDE_H
#define TABELLACOMANDE_H

#include "tabellacomposita.h"

class TabellaComande : public TabellaComposita {
  Q_OBJECT
public:
  TabellaComande(QWidget *parent = nullptr,
                 const QString& etichetta="",
                 const QStringList* = nullptr);
  void inserisciElemento(pacchettoComanda*);
  virtual void rendiEditabile(bool = true) override;

signals:
  void sendComandaPacketToModel(pacchettoComanda*);
  void sendComandaIdToModel(uint);

private slots:
 virtual void emitDataOnCellChanged(int,int) override;
 void checkBoxToggled(bool);
 void forwardIdToModel(uint);
};

#endif // TABELLACOMANDE_H
