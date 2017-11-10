#ifndef CUBO_H
#define CUBO_H

#include <QWidget>

namespace Ui {
class cubo;
}

class cubo : public QWidget
{
    Q_OBJECT

public:
    explicit cubo(QWidget *parent = 0);
    ~cubo();

private:
    Ui::cubo *ui;
};

#endif // CUBO_H
