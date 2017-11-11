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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prismaBaseRect
{
public:
    QLabel *label;

    void setupUi(QWidget *prismaBaseRect)
    {
        if (prismaBaseRect->objectName().isEmpty())
            prismaBaseRect->setObjectName(QStringLiteral("prismaBaseRect"));
        prismaBaseRect->resize(647, 441);
        label = new QLabel(prismaBaseRect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 161, 16));

        retranslateUi(prismaBaseRect);

        QMetaObject::connectSlotsByName(prismaBaseRect);
    } // setupUi

    void retranslateUi(QWidget *prismaBaseRect)
    {
        prismaBaseRect->setWindowTitle(QApplication::translate("prismaBaseRect", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("prismaBaseRect", "Prisma Base Rectangular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismaBaseRect: public Ui_prismaBaseRect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASERECT_H
