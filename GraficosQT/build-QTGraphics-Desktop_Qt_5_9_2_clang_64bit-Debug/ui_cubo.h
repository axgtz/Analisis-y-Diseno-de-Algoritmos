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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cubo
{
public:
    QLabel *label;

    void setupUi(QWidget *cubo)
    {
        if (cubo->objectName().isEmpty())
            cubo->setObjectName(QStringLiteral("cubo"));
        cubo->resize(635, 426);
        label = new QLabel(cubo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 60, 16));

        retranslateUi(cubo);

        QMetaObject::connectSlotsByName(cubo);
    } // setupUi

    void retranslateUi(QWidget *cubo)
    {
        cubo->setWindowTitle(QApplication::translate("cubo", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("cubo", "Cubo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cubo: public Ui_cubo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBO_H
