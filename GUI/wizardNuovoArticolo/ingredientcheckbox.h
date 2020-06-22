#ifndef INGREDIENTCHECKBOX_H
#define INGREDIENTCHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <QString>

class IngredientCheckBox : public QCheckBox{
public:
    IngredientCheckBox(QString, unsigned int, QWidget* = nullptr);
    unsigned int getId() const;

private:
    unsigned int id;
};

#endif // INGREDIENTCHECKBOX_H
