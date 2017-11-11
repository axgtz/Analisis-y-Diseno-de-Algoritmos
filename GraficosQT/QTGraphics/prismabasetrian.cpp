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
