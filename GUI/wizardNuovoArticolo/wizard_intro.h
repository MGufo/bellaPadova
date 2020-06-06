#ifndef WIZARD_INTRO_H
#define WIZARD_INTRO_H

#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

class wizard_Intro : public QWizardPage{
  Q_OBJECT
public:
  wizard_Intro(QWidget* parent = nullptr);
  int nextId() const override;

private:
  QVBoxLayout* layoutIntro;
};

#endif // WIZARD_INTRO_H
