/********************************************************************************
** Form generated from reading UI file 'cono.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONO_H
#define UI_CONO_H

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

class Ui_cono
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
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QTextEdit *boxGrados;
    QTextEdit *boxRadio;
    QTextEdit *boxYinicio;
    QLabel *label_7;

    void setupUi(QDialog *cono)
    {
        if (cono->objectName().isEmpty())
            cono->setObjectName(QStringLiteral("cono"));
        cono->resize(820, 514);
        pushButton_5 = new QPushButton(cono);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 70, 151, 32));
        label_2 = new QLabel(cono);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 51, 16));
        pushButton = new QPushButton(cono);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 30, 113, 101));
        pushButton_4 = new QPushButton(cono);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 30, 151, 32));
        pushButton_7 = new QPushButton(cono);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(550, 30, 151, 32));
        boxXinicio = new QTextEdit(cono);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(460, 60, 41, 21));
        label_5 = new QLabel(cono);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 40, 51, 16));
        pushButton_3 = new QPushButton(cono);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(710, 60, 101, 51));
        label_4 = new QLabel(cono);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 60, 91, 20));
        label_9 = new QLabel(cono);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(569, 10, 81, 20));
        label_10 = new QLabel(cono);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 10, 81, 20));
        label_3 = new QLabel(cono);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 41, 16));
        boxAngulo = new QTextEdit(cono);
        boxAngulo->setObjectName(QStringLiteral("boxAngulo"));
        boxAngulo->setGeometry(QRect(60, 80, 41, 21));
        label_6 = new QLabel(cono);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 30, 91, 20));
        label = new QLabel(cono);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 60, 16));
        pushButton_2 = new QPushButton(cono);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 90, 113, 32));
        pushButton_6 = new QPushButton(cono);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 70, 151, 32));
        label_8 = new QLabel(cono);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 10, 60, 16));
        boxGrados = new QTextEdit(cono);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(760, 40, 41, 21));
        boxRadio = new QTextEdit(cono);
        boxRadio->setObjectName(QStringLiteral("boxRadio"));
        boxRadio->setGeometry(QRect(50, 40, 41, 21));
        boxYinicio = new QTextEdit(cono);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(460, 30, 41, 21));
        label_7 = new QLabel(cono);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 10, 60, 16));

        retranslateUi(cono);

        QMetaObject::connectSlotsByName(cono);
    } // setupUi

    void retranslateUi(QDialog *cono)
    {
        cono->setWindowTitle(QApplication::translate("cono", "Dialog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("cono", "Zoom Out", Q_NULLPTR));
        label_2->setText(QApplication::translate("cono", "Angulo:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cono", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("cono", "Zoom In", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("cono", "Reflexion Vertical", Q_NULLPTR));
        label_5->setText(QApplication::translate("cono", "Grados:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cono", "Rotar", Q_NULLPTR));
        label_4->setText(QApplication::translate("cono", "Horizontal:", Q_NULLPTR));
        label_9->setText(QApplication::translate("cono", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("cono", "Rotacion", Q_NULLPTR));
        label_3->setText(QApplication::translate("cono", "Radio:", Q_NULLPTR));
        label_6->setText(QApplication::translate("cono", "Vertical:", Q_NULLPTR));
        label->setText(QApplication::translate("cono", "Cono", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cono", "Trasladar", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("cono", "Reflexion Horizontal", Q_NULLPTR));
        label_8->setText(QApplication::translate("cono", "Trasladar", Q_NULLPTR));
        label_7->setText(QApplication::translate("cono", "Zooms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cono: public Ui_cono {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONO_H
