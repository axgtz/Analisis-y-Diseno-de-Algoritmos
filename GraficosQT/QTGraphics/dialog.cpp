#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //Arco
    arco a;
    a.setModal(true);
    a.exec();
}

void Dialog::on_pushButton_2_clicked()
{
    //Poligono
    poligonoNLados pN;
    pN.setModal(true);
    pN.exec();
}

void Dialog::on_pushButton_3_clicked()
{
    //Cono
    cono c;
    c.setModal(true);
    c.exec();
}

void Dialog::on_pushButton_4_clicked()
{
    //Cubo
    cubo c;
    cu.setModal(true);
    cu.exec();
}

void Dialog::on_pushButton_5_clicked()
{
    //Prisma Base Rect
    prismaBaseRect pbr;
    pbr.setModal(true);
    pbr.exec();
}

void Dialog::on_pushButton_6_clicked()
{
    //Prisma Base Triangular
    prismaBaseTrian pbt;
    pbt.setModal(true);
    pbt.exec();
}





