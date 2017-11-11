#include "cubo.h"
#include "ui_cubo.h"

cubo::cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cubo)
{
    ui->setupUi(this);
}

cubo::~cubo()
{
    delete ui;
}
