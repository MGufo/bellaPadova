#ifndef NUOVOARTICOLO_BEVANDA_H
#define NUOVOARTICOLO_BEVANDA_H

#include <QWidget>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>


class NuovoArticolo_bevanda : public QWidget{
  Q_OBJECT
public:
  NuovoArticolo_bevanda(QWidget* parent = nullptr);

private:
  QVBoxLayout* layoutBevanda;
  QTableWidget* bevandeWrapper;
};
#endif // WIZARD_BEVANDA_H
