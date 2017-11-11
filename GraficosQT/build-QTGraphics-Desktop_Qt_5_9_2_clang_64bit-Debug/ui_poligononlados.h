/********************************************************************************
** Form generated from reading UI file 'poligononlados.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLIGONONLADOS_H
#define UI_POLIGONONLADOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_poligononlados
{
public:
    QLabel *label;

    void setupUi(QDialog *poligononlados)
    {
        if (poligononlados->objectName().isEmpty())
            poligononlados->setObjectName(QStringLiteral("poligononlados"));
        poligononlados->resize(725, 484);
        label = new QLabel(poligononlados);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 161, 16));

        retranslateUi(poligononlados);

        QMetaObject::connectSlotsByName(poligononlados);
    } // setupUi

    void retranslateUi(QDialog *poligononlados)
    {
        poligononlados->setWindowTitle(QApplication::translate("poligononlados", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("poligononlados", "Poligono N Lados", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class poligononlados: public Ui_poligononlados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLIGONONLADOS_H
