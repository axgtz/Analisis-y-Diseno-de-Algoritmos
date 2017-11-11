#include "prismabaserect.h"
#include "ui_prismabaserect.h"

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
