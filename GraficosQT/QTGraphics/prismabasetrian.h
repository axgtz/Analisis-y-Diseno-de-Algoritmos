#ifndef PRISMABASETRIAN_H
#define PRISMABASETRIAN_H

#include <QDialog>

namespace Ui {
class prismabasetrian;
}

class prismabasetrian : public QDialog
{
    Q_OBJECT

public:
    explicit prismabasetrian(QWidget *parent = 0);
    ~prismabasetrian();

private:
    Ui::prismabasetrian *ui;
};

#endif // PRISMABASETRIAN_H
