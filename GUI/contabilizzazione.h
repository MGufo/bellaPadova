#ifndef CONTABILIZZAZIONE_H
#define CONTABILIZZAZIONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>

class Contabilizzazione : public QWidget{
  Q_OBJECT
public:
  explicit Contabilizzazione(QWidget *parent = nullptr);

signals:
  void con_calcoloFatturato(const QDate&, const QDate&);
// TODO: Verificare se aggiungere i const a segnali/slot
public slots:
  void calcoloFatturato();
private:
  QVBoxLayout* layoutContabilizzazione;
  void setStyleContabilizzazione();
};

#endif // CONTABILIZZAZIONE_H
