#ifndef CONO_H
#define CONO_H

#include <QWidget>

namespace Ui {
class cono;
}

class cono : public QWidget
{
    Q_OBJECT

public:
    explicit cono(QWidget *parent = 0);
    ~cono();

private:
    Ui::cono *ui;
};

#endif // CONO_H
