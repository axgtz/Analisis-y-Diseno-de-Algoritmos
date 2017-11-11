#ifndef PRISMABASERECT_H
#define PRISMABASERECT_H

#include <QDialog>

namespace Ui {
class prismabaserect;
}

class prismabaserect : public QDialog
{
    Q_OBJECT

public:
    explicit prismabaserect(QWidget *parent = 0);
    ~prismabaserect();

private:
    Ui::prismabaserect *ui;
};

#endif // PRISMABASERECT_H
