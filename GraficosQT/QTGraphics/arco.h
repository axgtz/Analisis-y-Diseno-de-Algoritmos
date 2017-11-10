#ifndef ARCO_H
#define ARCO_H

#include <QWidget>

namespace Ui {
class arco;
}

class arco : public QWidget
{
    Q_OBJECT

public:
    explicit arco(QWidget *parent = 0);
    ~arco();

private:
    Ui::arco *ui;
};

#endif // ARCO_H
