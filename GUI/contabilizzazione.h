#ifndef CONTABILIZZAZIONE_H
#define CONTABILIZZAZIONE_H

#include <QDateEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtWidgets>

class Contabilizzazione : public QWidget {
  Q_OBJECT
 public:
  explicit Contabilizzazione(QWidget* parent = nullptr);

 signals:
  void con_calcoloFatturato(const QDate&, const QDate&);
 public slots:
  void calcoloFatturato();

 private:
  QHBoxLayout* layoutDate;
  QVBoxLayout* layoutContabilizzazione;
  void setStyleContabilizzazione();
};

#endif  // CONTABILIZZAZIONE_H
