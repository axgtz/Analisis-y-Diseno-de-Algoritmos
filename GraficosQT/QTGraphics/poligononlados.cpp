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
void drawPoligono(QPainter &painter, int lados, int radio){
    double angulo = (double)360.0/(double)lados;

      int xi,yi,xf,yf;
      double val = 3.141592 / 180;
      angulo *= val;
      int a = 0;

      for(a=1; a<=lados; a++) {
        xi = centroX + (radio * cos(angulo*a));
        yi = centroY + (radio * sin(angulo*a));

        xf = centroX + (radio * cos(angulo*(a+1)));
        yf = centroY + (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
      }
}

void poligononlados::paintEvent(QPaintEvent *e){

}

void poligononlados::on_pushButton_clicked()
{
    qVecTrans.clear();
    QString n = ui->boxLados->toPlainText();
     if(!n.isEmpty()) {
       int nS = n.toInt();

       QTransform centro;
       centro.translate(centroX,centroY);
       qVecTrans.push_back(centro);
       draw = !draw;
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir numero de lados");
       msgBox.exec();
     }
     update();
}

void poligononlados::on_pushButton_2_clicked()
{
    //Trasladar
    QString x = ui->boxXinicio->toPlainText();
    QString y = ui->boxYinicio->toPlainText();
     if(!x.isEmpty() && !y.isEmpty()) {
       int xS = x.toInt();
       int yS = y.toInt();
       QTransform t;
       t.translate(xS, yS);
       qVecTrans.push_back(t);
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir traslacion");
       msgBox.exec();
     }
     update();
}

void poligononlados::on_pushButton_4_clicked()
{
    //Zoom In
    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();

}

void poligononlados::on_pushButton_5_clicked()
{
    //Zoom Out
    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();

}

void poligononlados::on_pushButton_3_clicked()
{
    //Rotar
    QString r = ui->boxGrados->toPlainText();
      if(!r.isEmpty()) {
        int rS = r.toInt();
        QTransform r;
        r.rotate(rS);
        qVecTrans.push_back(r);
      } else {
        QMessageBox msgBox;
        msgBox.setText("Favor de elegir angulo");
        msgBox.exec();
      }
    update();
}

void poligononlados::on_pushButton_7_clicked()
{
    //Refl Vertical
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();

}

void poligononlados::on_pushButton_6_clicked()
{
    //Refl Horizontal
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();

}
