#ifndef CUBO_H
#define CUBO_H

#include <QDialog>

namespace Ui {
class cubo;
}

class cubo : public QDialog
{
    Q_OBJECT

public:
    explicit cubo(QWidget *parent = 0);
    ~cubo();

private:
    Ui::cubo *ui;
};

#endif // CUBO_H
