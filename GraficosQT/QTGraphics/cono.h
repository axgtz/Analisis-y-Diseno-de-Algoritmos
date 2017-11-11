#ifndef CONO_H
#define CONO_H

#include <QDialog>

namespace Ui {
class cono;
}

class cono : public QDialog
{
    Q_OBJECT

public:
    explicit cono(QWidget *parent = 0);
    ~cono();

private:
    Ui::cono *ui;
};

#endif // CONO_H
