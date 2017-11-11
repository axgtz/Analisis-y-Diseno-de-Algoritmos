#include "prismabasetrian.h"
#include "ui_prismabasetrian.h"

prismabasetrian::prismabasetrian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismabasetrian)
{
    ui->setupUi(this);
}

prismabasetrian::~prismabasetrian()
{
    delete ui;
}

void prismabasetrian::paintEvent(QPaintEvent *e){

}

void prismabasetrian::on_pushButton_clicked()
{
    //Dibujar

}

void prismabasetrian::on_pushButton_2_clicked()
{
    //Trasladar
}

void prismabasetrian::on_pushButton_4_clicked()
{
    //Zoom In

}

void prismabasetrian::on_pushButton_5_clicked()
{
    //Zoom Out

}

void prismabasetrian::on_pushButton_3_clicked()
{
    //Rotar
}

void prismabasetrian::on_pushButton_7_clicked()
{
    //Refl Vertical

}

void prismabasetrian::on_pushButton_6_clicked()
{
    //Refl Horizontal

}
