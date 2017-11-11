#include "cono.h"
#include "ui_cono.h"

cono::cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cono)
{
    ui->setupUi(this);
}

cono::~cono()
{
    delete ui;
}


void cono::on_pushButton_clicked()
{
    //Dibujar

}

void cono::on_pushButton_2_clicked()
{
    //Trasladar
}

void cono::on_pushButton_4_clicked()
{
    //Zoom In

}

void cono::on_pushButton_5_clicked()
{
    //Zoom Out

}

void cono::on_pushButton_3_clicked()
{
    //Rotar
}

void cono::on_pushButton_7_clicked()
{
    //Refl Vertical

}

void cono::on_pushButton_6_clicked()
{
    //Refl Horizontal

}
