#ifndef NUOVOARTICOLO_BEVANDA_H
#define NUOVOARTICOLO_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QLineEdit>
#include <QFormLayout>
#include <QRadioButton>
#include <QVBoxLayout>

class NuovoArticolo_bevanda : public QWidget{
  Q_OBJECT
public:
  NuovoArticolo_bevanda(QWidget* parent = nullptr);

  QLineEdit* getNomeBevanda() const;
  QLineEdit* getPrezzoBevanda() const;
  QLineEdit* getCapacitaBevanda() const;
  QRadioButton* getRadioBottiglia() const;

private:
  QVBoxLayout* layoutBevanda;
  QLineEdit* nomeBevanda;
  QLineEdit* prezzoBevanda;
  QLineEdit* capacitaBevanda;
  QRadioButton* radioBottiglia;
};
#endif // WIZARD_BEVANDA_H
