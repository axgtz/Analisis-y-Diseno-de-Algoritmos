#ifndef POLIGONONLADOS_H
#define POLIGONONLADOS_H

#include <QWidget>

namespace Ui {
class poligonoNLados;
}

class poligonoNLados : public QWidget
{
    Q_OBJECT

public:
    explicit poligonoNLados(QWidget *parent = 0);
    ~poligonoNLados();

private:
    Ui::poligonoNLados *ui;
};

#endif // POLIGONONLADOS_H
