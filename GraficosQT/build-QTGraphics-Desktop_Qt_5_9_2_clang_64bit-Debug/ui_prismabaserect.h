/********************************************************************************
** Form generated from reading UI file 'prismabaserect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRISMABASERECT_H
#define UI_PRISMABASERECT_H

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

class Ui_prismabaserect
{
public:
    QLabel *label;
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
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QTextEdit *boxGrados;
    QTextEdit *boxRadio;
    QTextEdit *boxYinicio;
    QLabel *label_11;

    void setupUi(QDialog *prismabaserect)
    {
        if (prismabaserect->objectName().isEmpty())
            prismabaserect->setObjectName(QStringLiteral("prismabaserect"));
        prismabaserect->resize(885, 480);
        label = new QLabel(prismabaserect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 221, 16));
        pushButton_5 = new QPushButton(prismabaserect);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 70, 151, 32));
        label_2 = new QLabel(prismabaserect);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 51, 16));
        pushButton = new QPushButton(prismabaserect);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(110, 30, 113, 101));
        pushButton_4 = new QPushButton(prismabaserect);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(250, 30, 151, 32));
        pushButton_7 = new QPushButton(prismabaserect);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(560, 30, 151, 32));
        boxXinicio = new QTextEdit(prismabaserect);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(470, 60, 41, 21));
        label_5 = new QLabel(prismabaserect);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(720, 40, 51, 16));
        pushButton_3 = new QPushButton(prismabaserect);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(710, 70, 101, 51));
        label_4 = new QLabel(prismabaserect);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 60, 91, 20));
        label_9 = new QLabel(prismabaserect);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(579, 10, 81, 20));
        label_10 = new QLabel(prismabaserect);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(720, 10, 81, 20));
        label_3 = new QLabel(prismabaserect);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 40, 41, 16));
        boxAngulo = new QTextEdit(prismabaserect);
        boxAngulo->setObjectName(QStringLiteral("boxAngulo"));
        boxAngulo->setGeometry(QRect(70, 80, 41, 21));
        label_6 = new QLabel(prismabaserect);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(410, 30, 91, 20));
        pushButton_2 = new QPushButton(prismabaserect);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 90, 113, 32));
        pushButton_6 = new QPushButton(prismabaserect);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(560, 70, 151, 32));
        label_8 = new QLabel(prismabaserect);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 10, 60, 16));
        boxGrados = new QTextEdit(prismabaserect);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(770, 40, 41, 21));
        boxRadio = new QTextEdit(prismabaserect);
        boxRadio->setObjectName(QStringLiteral("boxRadio"));
        boxRadio->setGeometry(QRect(60, 40, 41, 21));
        boxYinicio = new QTextEdit(prismabaserect);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(470, 30, 41, 21));
        label_11 = new QLabel(prismabaserect);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(290, 10, 60, 16));

        retranslateUi(prismabaserect);

        QMetaObject::connectSlotsByName(prismabaserect);
    } // setupUi

    void retranslateUi(QDialog *prismabaserect)
    {
        prismabaserect->setWindowTitle(QApplication::translate("prismabaserect", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("prismabaserect", "Prisma Base Rectangular", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("prismabaserect", "Zoom Out", Q_NULLPTR));
        label_2->setText(QApplication::translate("prismabaserect", "Angulo:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("prismabaserect", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("prismabaserect", "Zoom In", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("prismabaserect", "Reflexion Vertical", Q_NULLPTR));
        label_5->setText(QApplication::translate("prismabaserect", "Grados:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("prismabaserect", "Rotar", Q_NULLPTR));
        label_4->setText(QApplication::translate("prismabaserect", "Horizontal:", Q_NULLPTR));
        label_9->setText(QApplication::translate("prismabaserect", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("prismabaserect", "Rotacion", Q_NULLPTR));
        label_3->setText(QApplication::translate("prismabaserect", "Radio:", Q_NULLPTR));
        label_6->setText(QApplication::translate("prismabaserect", "Vertical:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("prismabaserect", "Trasladar", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("prismabaserect", "Reflexion Horizontal", Q_NULLPTR));
        label_8->setText(QApplication::translate("prismabaserect", "Trasladar", Q_NULLPTR));
        label_11->setText(QApplication::translate("prismabaserect", "Zooms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismabaserect: public Ui_prismabaserect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASERECT_H
