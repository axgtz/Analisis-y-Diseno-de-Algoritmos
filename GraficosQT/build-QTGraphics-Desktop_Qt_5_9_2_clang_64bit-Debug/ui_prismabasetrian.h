/********************************************************************************
** Form generated from reading UI file 'prismabasetrian.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRISMABASETRIAN_H
#define UI_PRISMABASETRIAN_H

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

class Ui_prismabasetrian
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
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QTextEdit *boxGrados;
    QTextEdit *boxYinicio;
    QLabel *label_11;

    void setupUi(QDialog *prismabasetrian)
    {
        if (prismabasetrian->objectName().isEmpty())
            prismabasetrian->setObjectName(QStringLiteral("prismabasetrian"));
        prismabasetrian->resize(834, 566);
        label = new QLabel(prismabasetrian);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 191, 16));
        pushButton_5 = new QPushButton(prismabasetrian);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 70, 151, 32));
        pushButton = new QPushButton(prismabasetrian);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(120, 30, 113, 101));
        pushButton_4 = new QPushButton(prismabasetrian);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 30, 151, 32));
        pushButton_7 = new QPushButton(prismabasetrian);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(570, 30, 151, 32));
        boxXinicio = new QTextEdit(prismabasetrian);
        boxXinicio->setObjectName(QStringLiteral("boxXinicio"));
        boxXinicio->setGeometry(QRect(480, 60, 41, 21));
        label_5 = new QLabel(prismabasetrian);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 40, 51, 16));
        pushButton_3 = new QPushButton(prismabasetrian);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(720, 70, 101, 51));
        label_4 = new QLabel(prismabasetrian);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 60, 91, 20));
        label_9 = new QLabel(prismabasetrian);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(589, 10, 81, 20));
        label_10 = new QLabel(prismabasetrian);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(730, 10, 81, 20));
        label_6 = new QLabel(prismabasetrian);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 30, 91, 20));
        pushButton_2 = new QPushButton(prismabasetrian);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 90, 113, 32));
        pushButton_6 = new QPushButton(prismabasetrian);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(570, 70, 151, 32));
        label_8 = new QLabel(prismabasetrian);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(460, 10, 60, 16));
        boxGrados = new QTextEdit(prismabasetrian);
        boxGrados->setObjectName(QStringLiteral("boxGrados"));
        boxGrados->setGeometry(QRect(780, 40, 41, 21));
        boxYinicio = new QTextEdit(prismabasetrian);
        boxYinicio->setObjectName(QStringLiteral("boxYinicio"));
        boxYinicio->setGeometry(QRect(480, 30, 41, 21));
        label_11 = new QLabel(prismabasetrian);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 10, 60, 16));

        retranslateUi(prismabasetrian);

        QMetaObject::connectSlotsByName(prismabasetrian);
    } // setupUi

    void retranslateUi(QDialog *prismabasetrian)
    {
        prismabasetrian->setWindowTitle(QApplication::translate("prismabasetrian", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("prismabasetrian", "Prisma Base Triangular", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("prismabasetrian", "Zoom Out", Q_NULLPTR));
        pushButton->setText(QApplication::translate("prismabasetrian", "Dibujar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("prismabasetrian", "Zoom In", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("prismabasetrian", "Reflexion Vertical", Q_NULLPTR));
        label_5->setText(QApplication::translate("prismabasetrian", "Grados:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("prismabasetrian", "Rotar", Q_NULLPTR));
        label_4->setText(QApplication::translate("prismabasetrian", "Horizontal:", Q_NULLPTR));
        label_9->setText(QApplication::translate("prismabasetrian", "Reflexiones", Q_NULLPTR));
        label_10->setText(QApplication::translate("prismabasetrian", "Rotacion", Q_NULLPTR));
        label_6->setText(QApplication::translate("prismabasetrian", "Vertical:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("prismabasetrian", "Trasladar", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("prismabasetrian", "Reflexion Horizontal", Q_NULLPTR));
        label_8->setText(QApplication::translate("prismabasetrian", "Trasladar", Q_NULLPTR));
        label_11->setText(QApplication::translate("prismabasetrian", "Zooms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismabasetrian: public Ui_prismabasetrian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASETRIAN_H
