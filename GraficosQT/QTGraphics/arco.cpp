#include "arco.h"
#include "ui_arco.h"

arco::arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arco)
{
    ui->setupUi(this);
}

arco::~arco()
{
    delete ui;
}
