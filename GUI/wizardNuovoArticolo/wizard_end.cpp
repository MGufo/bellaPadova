#include "wizard_end.h"

wizard_end::wizard_end(QWidget* parent) : QWizardPage(parent) {

  QLabel* endLabel = new QLabel(this);
//  if(nuovoArticolo->hasVisitedPage(WizardNuovoArticolo::PAGE_Pizza))
//    endLabel->setText("La pizza è stata inserita con successo nel Menù!");
//  else
//    endLabel->setText("La pizza è stata inserita con successo nel Menù!");

  endLabel->setText("L'articolo è stato inserito con successo nel Menù!");
  layoutEnd = new QVBoxLayout(this);
  layoutEnd->addWidget(endLabel);
  setLayout(layoutEnd);
}
