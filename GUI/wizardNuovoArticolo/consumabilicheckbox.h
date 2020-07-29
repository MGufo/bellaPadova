#ifndef CONSUMABILICHECKBOX_H
#define CONSUMABILICHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <QString>

class ConsumabiliCheckBox : public QCheckBox{
public:
    ConsumabiliCheckBox(QString, unsigned int, QWidget* = nullptr);
    unsigned int getId() const;

private:
    unsigned int id;
};

#endif // CONSUMABILICHECKBOX_H
