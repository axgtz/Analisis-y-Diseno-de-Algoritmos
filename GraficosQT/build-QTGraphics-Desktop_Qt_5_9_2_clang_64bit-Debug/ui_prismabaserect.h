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

QT_BEGIN_NAMESPACE

class Ui_prismabaserect
{
public:
    QLabel *label;

    void setupUi(QDialog *prismabaserect)
    {
        if (prismabaserect->objectName().isEmpty())
            prismabaserect->setObjectName(QStringLiteral("prismabaserect"));
        prismabaserect->resize(721, 480);
        label = new QLabel(prismabaserect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 221, 16));

        retranslateUi(prismabaserect);

        QMetaObject::connectSlotsByName(prismabaserect);
    } // setupUi

    void retranslateUi(QDialog *prismabaserect)
    {
        prismabaserect->setWindowTitle(QApplication::translate("prismabaserect", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("prismabaserect", "Prisma Base Rectangular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismabaserect: public Ui_prismabaserect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASERECT_H
