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

QT_BEGIN_NAMESPACE

class Ui_cubo
{
public:
    QLabel *label;

    void setupUi(QDialog *cubo)
    {
        if (cubo->objectName().isEmpty())
            cubo->setObjectName(QStringLiteral("cubo"));
        cubo->resize(400, 300);
        label = new QLabel(cubo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 16));

        retranslateUi(cubo);

        QMetaObject::connectSlotsByName(cubo);
    } // setupUi

    void retranslateUi(QDialog *cubo)
    {
        cubo->setWindowTitle(QApplication::translate("cubo", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("cubo", "Cubo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cubo: public Ui_cubo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBO_H
