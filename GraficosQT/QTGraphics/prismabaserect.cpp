#include "prismabaserect.h"
#include "ui_prismabaserect.h"
#include <QPainter>
#include <QMessageBox>

prismabaserect::prismabaserect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismabaserect)
{
    ui->setupUi(this);
}

prismabaserect::~prismabaserect()
{
    delete ui;
}


void prismabaserect::paintEvent(QPaintEvent *e){

}

void prismabaserect::on_pushButton_clicked()
{
    //Dibujar

}

void prismabaserect::on_pushButton_2_clicked()
{
    //Trasladar
}

void prismabaserect::on_pushButton_4_clicked()
{
    //Zoom In

}

void prismabaserect::on_pushButton_5_clicked()
{
    //Zoom Out

}

void prismabaserect::on_pushButton_3_clicked()
{
    //Rotar
}

void prismabaserect::on_pushButton_7_clicked()
{
    //Refl Vertical

}

void prismabaserect::on_pushButton_6_clicked()
{
    //Refl Horizontal

}

