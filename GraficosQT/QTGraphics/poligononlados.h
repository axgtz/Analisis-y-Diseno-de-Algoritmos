#ifndef POLIGONONLADOS_H
#define POLIGONONLADOS_H

#include <QDialog>

namespace Ui {
class poligononlados;
}

class poligononlados : public QDialog
{
    Q_OBJECT

public:
    explicit poligononlados(QWidget *parent = 0);
    ~poligononlados();

private:
    Ui::poligononlados *ui;
};

#endif // POLIGONONLADOS_H
