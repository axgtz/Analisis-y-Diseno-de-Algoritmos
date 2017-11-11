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

protected:
     void paintEvent(QPaintEvent *e);

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();

private:
    Ui::prismabasetrian *ui;
};

#endif // PRISMABASETRIAN_H
