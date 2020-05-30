#ifndef CONTABILIZZAZIONE_H
#define CONTABILIZZAZIONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDateEdit>
#include <QPushButton>
#include <QTextEdit>
class Contabilizzazione : public QWidget
{
    Q_OBJECT
public:
    explicit Contabilizzazione(QWidget *parent = nullptr);

signals:

public slots:
private:
  QVBoxLayout* layoutContabilizzazione;
  void setStyleContabilizzazione();
};

#endif // CONTABILIZZAZIONE_H
