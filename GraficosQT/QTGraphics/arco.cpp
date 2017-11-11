#include "arco.h"
#include "ui_arco.h"

arco::arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arco)
{
    ui->setupUi(this);
}

arco::~arco()
{
    delete ui;
}

void arco::paintEvent(QPaintEvent *e){

}

void arco::on_pushButton_clicked()
{
    //Dibujar

}

void arco::on_pushButton_2_clicked()
{
    //Trasladar
}

void arco::on_pushButton_4_clicked()
{
    //Zoom In

}

void arco::on_pushButton_5_clicked()
{
    //Zoom Out

}

void arco::on_pushButton_3_clicked()
{
    //Rotar
}

void arco::on_pushButton_7_clicked()
{
    //Refl Vertical

}

void arco::on_pushButton_6_clicked()
{
    //Refl Horizontal

}
