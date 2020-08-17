#include "tabellarisorse.h"

TabellaRisorse::TabellaRisorse(QWidget *parent, const QString& etichetta, const QStringList* labels) : TabellaComposita(parent, etichetta, labels){
  connect(tabella,SIGNAL(cellChanged(int,int)),
          this,SLOT(emitDataOnCellChanged(int,int)));
  connect(this,SIGNAL(validationError(const QString)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(mostraErrore(const QString)));
  connect(this,SIGNAL(sendPacketToModel(pacchetto*, bool)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(modificaRisorsa(pacchetto*, bool)));
  connect(this,SIGNAL(sendIdToModel(uint, bool)),
          parentWidget()->parentWidget()->parentWidget(),
          SLOT(eliminaRisorsa(uint, bool)));
  connect(this,SIGNAL(sendIdToModel(uint, bool)),
          this,SLOT(eliminaElemento(uint, bool)));
}
