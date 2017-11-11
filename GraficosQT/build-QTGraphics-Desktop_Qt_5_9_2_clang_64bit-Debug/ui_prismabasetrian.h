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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prismaBaseTrian
{
public:
    QLabel *label;

    void setupUi(QWidget *prismaBaseTrian)
    {
        if (prismaBaseTrian->objectName().isEmpty())
            prismaBaseTrian->setObjectName(QStringLiteral("prismaBaseTrian"));
        prismaBaseTrian->resize(658, 482);
        label = new QLabel(prismaBaseTrian);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 161, 16));

        retranslateUi(prismaBaseTrian);

        QMetaObject::connectSlotsByName(prismaBaseTrian);
    } // setupUi

    void retranslateUi(QWidget *prismaBaseTrian)
    {
        prismaBaseTrian->setWindowTitle(QApplication::translate("prismaBaseTrian", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("prismaBaseTrian", "Prisma Base Triangular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismaBaseTrian: public Ui_prismaBaseTrian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASETRIAN_H
