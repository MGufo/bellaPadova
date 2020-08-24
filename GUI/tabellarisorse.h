#ifndef TABELLARISORSE_H
#define TABELLARISORSE_H

#include "tabellacomposita.h"
#include "inputValidator.h"
#include "pushbuttonwithid.h"

class TabellaRisorse : public TabellaComposita {
  Q_OBJECT
public:
  TabellaRisorse(QWidget *parent = nullptr,
                 const QString& etichetta="",
                 const QStringList* = nullptr);
  void inserisciElemento(pacchetto*);
  void sostituisciElemento(pacchetto*);
  virtual void rendiEditabile(bool = true) override;

signals:
  void sendArticoloPacketToModel(pacchettoArticolo*);
  void sendConsumabilePacketToModel(pacchettoConsumabile*);
  void sendArticoloIdToModel(uint);
  void sendConsumabileIdToModel(uint);

private slots:
 virtual void emitDataOnCellChanged(int,int) override;
 virtual void forwardIdToModel(uint) override;

private:
 void validateInput(int, int);
};

#endif // TABELLARISORSE_H
