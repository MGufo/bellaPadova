#ifndef NUOVOARTICOLO_BEVANDA_H
#define NUOVOARTICOLO_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QScrollArea>


class NuovoArticolo_bevanda : public QWidget{
  Q_OBJECT
public:
  NuovoArticolo_bevanda(QWidget* parent = nullptr);
  QWidget* getBevandeRadioButtonWrapper() const;

private:
  QVBoxLayout* layoutBevanda;
  QWidget* bevandeRadioButtonWrapper;
};
#endif // WIZARD_BEVANDA_H
