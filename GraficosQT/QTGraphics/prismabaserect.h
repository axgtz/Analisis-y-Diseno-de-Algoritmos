#ifndef PRISMABASERECT_H
#define PRISMABASERECT_H

#include <QDialog>

namespace Ui {
class prismabaserect;
}

class prismabaserect : public QDialog
{
    Q_OBJECT

public:
    explicit prismabaserect(QWidget *parent = 0);
    ~prismabaserect();

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
    Ui::prismabaserect *ui;
};

#endif // PRISMABASERECT_H
