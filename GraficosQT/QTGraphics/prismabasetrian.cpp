#include "prismabasetrian.h"
#include "ui_prismabasetrian.h"

prismaBaseTrian::prismaBaseTrian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prismaBaseTrian)
{
    ui->setupUi(this);
}

prismaBaseTrian::~prismaBaseTrian()
{
    delete ui;
}
