/********************************************************************************
** Form generated from reading UI file 'cubo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBO_H
#define UI_CUBO_H

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

class Ui_cubo
{
public:
    QPushButton *pushButton_5;
    QLabel *label_2;
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
    QTextEdit *boxAngulo;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QTextEdit *boxGrados;
    QTextEdit *boxRadio;
    QTextEdit *boxYinicio;
    QLabel *label_11;

    void setupUi(QDialog *cubo)
    {
        if (cubo->objectName().isEmpty())
            cubo->setObjectName(QStringLiteral("cubo"));
        cubo->resize(837, 551);
        pushButton_5 = new QPushButton(cubo);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 70, 151, 32));
        label_2 = new QLabel(cubo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 51, 16));
        pushButton = new QPushButton(cubo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 30, 113, 101));
        pushButton_4 = new QPushButton(cubo);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 30, 151, 32));
        pushButton_7 = new QPushButton(cubo);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(550, 30, 151, 32));
        boxXinicio = new QTextEdit(cubo);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(460, 60, 41, 21));
        label_5 = new QLabel(cubo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 40, 51, 16));
        pushButton_3 = new QPushButton(cubo);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 70, 101, 51));
        label_4 = new QLabel(cubo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 60, 91, 20));
        label_9 = new QLabel(cubo);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(569, 10, 81, 20));
        label_10 = new QLabel(cubo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 10, 81, 20));
        label_3 = new QLabel(cubo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 41, 16));
        boxAngulo = new QTextEdit(cubo);
        boxAngulo->setObjectName(QStringLiteral("boxAngulo"));
        boxAngulo->setGeometry(QRect(60, 80, 41, 21));
        label_6 = new QLabel(cubo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 30, 91, 20));
        label_7 = new QLabel(cubo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 10, 60, 16));
        pushButton_2 = new QPushButton(cubo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 90, 113, 32));
        pushButton_6 = new QPushButton(cubo);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 70, 151, 32));
        label_8 = new QLabel(cubo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 10, 60, 16));
        boxGrados = new QTextEdit(cubo);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(760, 40, 41, 21));
        boxRadio = new QTextEdit(cubo);
        boxRadio->setObjectName(QStringLiteral("boxRadio"));
        boxRadio->setGeometry(QRect(50, 40, 41, 21));
        boxYinicio = new QTextEdit(cubo);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(460, 30, 41, 21));
        label_11 = new QLabel(cubo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 10, 60, 16));

        retranslateUi(cubo);

        QMetaObject::connectSlotsByName(cubo);
    } // setupUi

    void retranslateUi(QDialog *cubo)
    {
        cubo->setWindowTitle(QApplication::translate("cubo", "Dialog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("cubo", "Zoom Out", Q_NULLPTR));
        label_2->setText(QApplication::translate("cubo", "Angulo:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cubo", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("cubo", "Zoom In", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("cubo", "Reflexion Vertical", Q_NULLPTR));
        label_5->setText(QApplication::translate("cubo", "Grados:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cubo", "Rotar", Q_NULLPTR));
        label_4->setText(QApplication::translate("cubo", "Horizontal:", Q_NULLPTR));
        label_9->setText(QApplication::translate("cubo", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("cubo", "Rotacion", Q_NULLPTR));
        label_3->setText(QApplication::translate("cubo", "Radio:", Q_NULLPTR));
        label_6->setText(QApplication::translate("cubo", "Vertical:", Q_NULLPTR));
        label_7->setText(QApplication::translate("cubo", "Cubo", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cubo", "Trasladar", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("cubo", "Reflexion Horizontal", Q_NULLPTR));
        label_8->setText(QApplication::translate("cubo", "Trasladar", Q_NULLPTR));
        label_11->setText(QApplication::translate("cubo", "Zooms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cubo: public Ui_cubo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBO_H
