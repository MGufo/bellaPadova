#ifndef TABELLACOMANDE_H
#define TABELLACOMANDE_H

#include <QSpinBox>

#include "tabellacomposita.h"

class TabellaComande : public TabellaComposita {
  Q_OBJECT
public:
  TabellaComande(QWidget *parent = nullptr,
                 const QString& etichetta="",
                 const QStringList* = nullptr);
  void inserisciElemento(pacchetto*, uint = 0);
  virtual void rendiEditabile(bool = true) override;
  void riempiContenutoPacchetto(std::unordered_map<uint,uint>&);

signals:
  void sendComandaPacketToModel(pacchettoComanda*);
  void sendComandaIdToModel(uint);
  void datiModificati();

private slots:
 virtual void emitDataOnCellChanged(int,int) override;
 void checkBoxToggled(bool);
 void forwardIdToModel(uint);
 void selezionaQuantitaHandler(int);
};

#endif // TABELLACOMANDE_H
