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

QT_BEGIN_NAMESPACE

class Ui_prismabasetrian
{
public:
    QLabel *label;

    void setupUi(QDialog *prismabasetrian)
    {
        if (prismabasetrian->objectName().isEmpty())
            prismabasetrian->setObjectName(QStringLiteral("prismabasetrian"));
        prismabasetrian->resize(400, 300);
        label = new QLabel(prismabasetrian);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 191, 16));

        retranslateUi(prismabasetrian);

        QMetaObject::connectSlotsByName(prismabasetrian);
    } // setupUi

    void retranslateUi(QDialog *prismabasetrian)
    {
        prismabasetrian->setWindowTitle(QApplication::translate("prismabasetrian", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("prismabasetrian", "Prisma Base Triangular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class prismabasetrian: public Ui_prismabasetrian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMABASETRIAN_H
