#ifndef PRISMABASERECT_H
#define PRISMABASERECT_H

#include <QWidget>

namespace Ui {
class prismaBaseRect;
}

class prismaBaseRect : public QWidget
{
    Q_OBJECT

public:
    explicit prismaBaseRect(QWidget *parent = 0);
    ~prismaBaseRect();

private:
    Ui::prismaBaseRect *ui;
};

#endif // PRISMABASERECT_H
