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

QT_BEGIN_NAMESPACE

class Ui_cono
{
public:
    QLabel *label;

    void setupUi(QDialog *cono)
    {
        if (cono->objectName().isEmpty())
            cono->setObjectName(QStringLiteral("cono"));
        cono->resize(400, 300);
        label = new QLabel(cono);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 60, 16));

        retranslateUi(cono);

        QMetaObject::connectSlotsByName(cono);
    } // setupUi

    void retranslateUi(QDialog *cono)
    {
        cono->setWindowTitle(QApplication::translate("cono", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("cono", "Cono", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cono: public Ui_cono {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONO_H
