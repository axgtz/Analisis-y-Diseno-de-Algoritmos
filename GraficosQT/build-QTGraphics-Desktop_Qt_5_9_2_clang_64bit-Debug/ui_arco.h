/********************************************************************************
** Form generated from reading UI file 'arco.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCO_H
#define UI_ARCO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_arco
{
public:
    QLabel *label;

    void setupUi(QDialog *arco)
    {
        if (arco->objectName().isEmpty())
            arco->setObjectName(QStringLiteral("arco"));
        arco->resize(635, 436);
        label = new QLabel(arco);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 60, 16));

        retranslateUi(arco);

        QMetaObject::connectSlotsByName(arco);
    } // setupUi

    void retranslateUi(QDialog *arco)
    {
        arco->setWindowTitle(QApplication::translate("arco", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("arco", "Arco", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arco: public Ui_arco {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCO_H
