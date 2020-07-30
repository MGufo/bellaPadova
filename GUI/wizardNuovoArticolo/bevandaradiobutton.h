#ifndef BEVANDARADIOBUTTON_H
#define BEVANDARADIOBUTTON_H

#include <QWidget>
#include <QRadioButton>
#include <QString>

class BevandaRadioButton : public QRadioButton
{
public:
    BevandaRadioButton(uint, QString, double, double, QString, QWidget* = nullptr);

    uint getId() const;
    QString getNome() const;
    double getPrezzo() const;
    double getCapacita() const;
    QString getFormato() const;

private:
    uint id;
    QString nome;
    double prezzo;
    double capacita;
    QString formato;
};

#endif // BEVANDARADIOBUTTON_H
