#ifndef WIZARDNUOVOARTICOLO_H
#define WIZARDNUOVOARTICOLO_H

#include <QWidget>
#include <QWizard>

class WizardNuovoArticolo : public QWizard{
  Q_OBJECT
public:
  explicit WizardNuovoArticolo(QWidget *parent = nullptr);
  enum { Page_tipoArticolo, Page_tipoPizza, Page_tipoBevanda, Page_end};

signals:

public slots:
  //void accept() override;
};

#endif // WIZARDNUOVOARTICOLO_H
