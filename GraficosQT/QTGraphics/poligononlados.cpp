#include "poligononlados.h"
#include "ui_poligononlados.h"

poligononlados::poligononlados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::poligononlados)
{
    ui->setupUi(this);
}

poligononlados::~poligononlados()
{
    delete ui;
}


void poligononlados::paintEvent(QPaintEvent *e){}
void poligononlados::on_pushButton_clicked()
{
    //Dibujar

}

void poligononlados::on_pushButton_2_clicked()
{
    //Trasladar
}

void poligononlados::on_pushButton_4_clicked()
{
    //Zoom In

}

void poligononlados::on_pushButton_5_clicked()
{
    //Zoom Out

}

void poligononlados::on_pushButton_3_clicked()
{
    //Rotar
}

void poligononlados::on_pushButton_7_clicked()
{
    //Refl Vertical

}

void poligononlados::on_pushButton_6_clicked()
{
    //Refl Horizontal

}
