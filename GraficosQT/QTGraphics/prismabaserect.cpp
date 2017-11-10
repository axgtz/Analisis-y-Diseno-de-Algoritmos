#include "prismabaserect.h"
#include "ui_prismabaserect.h"

prismaBaseRect::prismaBaseRect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prismaBaseRect)
{
    ui->setupUi(this);
}

prismaBaseRect::~prismaBaseRect()
{
    delete ui;
}
