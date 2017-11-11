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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_poligonoNLados
{
public:
    QLabel *label;

    void setupUi(QWidget *poligonoNLados)
    {
        if (poligonoNLados->objectName().isEmpty())
            poligonoNLados->setObjectName(QStringLiteral("poligonoNLados"));
        poligonoNLados->resize(658, 432);
        label = new QLabel(poligonoNLados);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 121, 16));

        retranslateUi(poligonoNLados);

        QMetaObject::connectSlotsByName(poligonoNLados);
    } // setupUi

    void retranslateUi(QWidget *poligonoNLados)
    {
        poligonoNLados->setWindowTitle(QApplication::translate("poligonoNLados", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("poligonoNLados", "Poligono N Lados", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class poligonoNLados: public Ui_poligonoNLados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLIGONONLADOS_H
