#ifndef ARCO_H
#define ARCO_H

#include <QDialog>

namespace Ui {
class arco;
}

class arco : public QDialog
{
    Q_OBJECT

public:
    explicit arco(QWidget *parent = 0);
    ~arco();

private:
    Ui::arco *ui;
};

#endif // ARCO_H
