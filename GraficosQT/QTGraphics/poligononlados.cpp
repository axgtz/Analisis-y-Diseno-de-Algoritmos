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
