/********************************************************************************
** Form generated from reading UI file 'poligononlados.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLIGONONLADOS_H
#define UI_POLIGONONLADOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_poligononlados
{
public:
    QLabel *label;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QTextEdit *boxXinicio;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QTextEdit *boxGrados;
    QTextEdit *boxLados;
    QTextEdit *boxYinicio;
    QLabel *label_11;
    QLabel *label_7;
    QTextEdit *boxRadio;

    void setupUi(QDialog *poligononlados)
    {
        if (poligononlados->objectName().isEmpty())
            poligononlados->setObjectName(QStringLiteral("poligononlados"));
        poligononlados->resize(844, 536);
        label = new QLabel(poligononlados);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 161, 16));
        pushButton_5 = new QPushButton(poligononlados);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 70, 151, 32));
        pushButton = new QPushButton(poligononlados);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 30, 113, 101));
        pushButton_4 = new QPushButton(poligononlados);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 30, 151, 32));
        pushButton_7 = new QPushButton(poligononlados);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(550, 30, 151, 32));
        boxXinicio = new QTextEdit(poligononlados);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(460, 60, 41, 21));
        label_5 = new QLabel(poligononlados);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 40, 51, 16));
        pushButton_3 = new QPushButton(poligononlados);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 70, 101, 51));
        label_4 = new QLabel(poligononlados);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 60, 91, 20));
        label_9 = new QLabel(poligononlados);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(569, 10, 81, 20));
        label_10 = new QLabel(poligononlados);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 10, 81, 20));
        label_3 = new QLabel(poligononlados);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 41, 16));
        label_6 = new QLabel(poligononlados);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 30, 91, 20));
        pushButton_2 = new QPushButton(poligononlados);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 90, 113, 32));
        pushButton_6 = new QPushButton(poligononlados);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 70, 151, 32));
        label_8 = new QLabel(poligononlados);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 10, 60, 16));
        boxGrados = new QTextEdit(poligononlados);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(760, 40, 41, 21));
        boxLados = new QTextEdit(poligononlados);
        boxLados->setObjectName(QStringLiteral("boxLados"));
        boxLados->setGeometry(QRect(60, 30, 41, 21));
        boxYinicio = new QTextEdit(poligononlados);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(460, 30, 41, 21));
        label_11 = new QLabel(poligononlados);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 10, 60, 16));
        label_7 = new QLabel(poligononlados);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 41, 16));
        boxRadio = new QTextEdit(poligononlados);
        boxRadio->setObjectName(QStringLiteral("boxRadio"));
        boxRadio->setGeometry(QRect(60, 70, 41, 21));

        retranslateUi(poligononlados);

        QMetaObject::connectSlotsByName(poligononlados);
    } // setupUi

    void retranslateUi(QDialog *poligononlados)
    {
        poligononlados->setWindowTitle(QApplication::translate("poligononlados", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("poligononlados", "Poligono N Lados", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("poligononlados", "Zoom Out", Q_NULLPTR));
        pushButton->setText(QApplication::translate("poligononlados", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("poligononlados", "Zoom In", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("poligononlados", "Reflexion Vertical", Q_NULLPTR));
        label_5->setText(QApplication::translate("poligononlados", "Grados:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("poligononlados", "Rotar", Q_NULLPTR));
        label_4->setText(QApplication::translate("poligononlados", "Horizontal:", Q_NULLPTR));
        label_9->setText(QApplication::translate("poligononlados", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("poligononlados", "Rotacion", Q_NULLPTR));
        label_3->setText(QApplication::translate("poligononlados", "Lados:", Q_NULLPTR));
        label_6->setText(QApplication::translate("poligononlados", "Vertical:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("poligononlados", "Trasladar", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("poligononlados", "Reflexion Horizontal", Q_NULLPTR));
        label_8->setText(QApplication::translate("poligononlados", "Trasladar", Q_NULLPTR));
        label_11->setText(QApplication::translate("poligononlados", "Zooms", Q_NULLPTR));
        label_7->setText(QApplication::translate("poligononlados", "Radio:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class poligononlados: public Ui_poligononlados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLIGONONLADOS_H
