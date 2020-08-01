#ifndef INGREDIENTECHECKBOX_H
#define INGREDIENTECHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <QString>

class IngredienteCheckBox : public QCheckBox{
public:
    IngredienteCheckBox(QString, unsigned int, QWidget* = nullptr);
    unsigned int getId() const;

private:
    unsigned int id;
};

#endif // CONSUMABILICHECKBOX_H
