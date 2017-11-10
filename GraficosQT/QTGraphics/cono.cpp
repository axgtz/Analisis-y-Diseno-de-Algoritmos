#include "cono.h"
#include "ui_cono.h"

cono::cono(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cono)
{
    ui->setupUi(this);
}

cono::~cono()
{
    delete ui;
}
