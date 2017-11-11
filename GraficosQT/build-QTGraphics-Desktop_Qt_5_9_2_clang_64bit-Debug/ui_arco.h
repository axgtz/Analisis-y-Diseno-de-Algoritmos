/********************************************************************************
** Form generated from reading UI file 'arco.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCO_H
#define UI_ARCO_H

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

class Ui_arco
{
public:
    QLabel *label;
    QLabel *label_5;
    QPushButton *pushButton_6;
    QTextEdit *boxGrados;
    QTextEdit *boxYinicio;
    QPushButton *pushButton;
    QTextEdit *boxAngulo;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QTextEdit *boxRadio;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QTextEdit *boxXinicio;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *arco)
    {
        if (arco->objectName().isEmpty())
            arco->setObjectName(QStringLiteral("arco"));
        arco->resize(810, 545);
        label = new QLabel(arco);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 60, 16));
        label_5 = new QLabel(arco);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 40, 51, 16));
        pushButton_6 = new QPushButton(arco);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 70, 151, 32));
        boxGrados = new QTextEdit(arco);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(760, 40, 41, 21));
        boxYinicio = new QTextEdit(arco);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(460, 30, 41, 21));
        pushButton = new QPushButton(arco);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 30, 113, 101));
        boxAngulo = new QTextEdit(arco);
        boxAngulo->setObjectName(QStringLiteral("boxAngulo"));
        boxAngulo->setGeometry(QRect(60, 80, 41, 21));
        pushButton_4 = new QPushButton(arco);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 30, 151, 32));
        label_2 = new QLabel(arco);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 51, 16));
        pushButton_3 = new QPushButton(arco);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 70, 101, 51));
        label_3 = new QLabel(arco);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 41, 16));
        pushButton_2 = new QPushButton(arco);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 90, 113, 32));
        pushButton_7 = new QPushButton(arco);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(550, 30, 151, 32));
        boxRadio = new QTextEdit(arco);
        boxRadio->setObjectName(QStringLiteral("boxRadio"));
        boxRadio->setGeometry(QRect(50, 40, 41, 21));
        pushButton_5 = new QPushButton(arco);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 70, 151, 32));
        label_4 = new QLabel(arco);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 60, 91, 20));
        boxXinicio = new QTextEdit(arco);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(460, 60, 41, 21));
        label_6 = new QLabel(arco);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 30, 91, 20));
        label_7 = new QLabel(arco);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 10, 60, 16));
        label_8 = new QLabel(arco);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 10, 60, 16));
        label_9 = new QLabel(arco);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(569, 10, 81, 20));
        label_10 = new QLabel(arco);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 10, 81, 20));

        retranslateUi(arco);

        QMetaObject::connectSlotsByName(arco);
    } // setupUi

    void retranslateUi(QDialog *arco)
    {
        arco->setWindowTitle(QApplication::translate("arco", "Arco", Q_NULLPTR));
        label->setText(QApplication::translate("arco", "Arco", Q_NULLPTR));
        label_5->setText(QApplication::translate("arco", "Grados:", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("arco", "Reflexion Horizontal", Q_NULLPTR));
        pushButton->setText(QApplication::translate("arco", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("arco", "Zoom In", Q_NULLPTR));
        label_2->setText(QApplication::translate("arco", "Angulo:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("arco", "Rotar", Q_NULLPTR));
        label_3->setText(QApplication::translate("arco", "Radio:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("arco", "Trasladar", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("arco", "Reflexion Vertical", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("arco", "Zoom Out", Q_NULLPTR));
        label_4->setText(QApplication::translate("arco", "Horizontal:", Q_NULLPTR));
        label_6->setText(QApplication::translate("arco", "Vertical:", Q_NULLPTR));
        label_7->setText(QApplication::translate("arco", "Zooms", Q_NULLPTR));
        label_8->setText(QApplication::translate("arco", "Trasladar", Q_NULLPTR));
        label_9->setText(QApplication::translate("arco", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("arco", "Rotacion", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arco: public Ui_arco {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCO_H
