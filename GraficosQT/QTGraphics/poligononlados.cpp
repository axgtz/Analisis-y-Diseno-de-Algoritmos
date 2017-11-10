#include "poligononlados.h"
#include "ui_poligononlados.h"

poligonoNLados::poligonoNLados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::poligonoNLados)
{
    ui->setupUi(this);
}

poligonoNLados::~poligonoNLados()
{
    delete ui;
}
