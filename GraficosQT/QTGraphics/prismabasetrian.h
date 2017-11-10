#ifndef PRISMABASETRIAN_H
#define PRISMABASETRIAN_H

#include <QWidget>

namespace Ui {
class prismaBaseTrian;
}

class prismaBaseTrian : public QWidget
{
    Q_OBJECT

public:
    explicit prismaBaseTrian(QWidget *parent = 0);
    ~prismaBaseTrian();

private:
    Ui::prismaBaseTrian *ui;
};

#endif // PRISMABASETRIAN_H
