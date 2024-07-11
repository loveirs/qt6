/********************************************************************************
** Form generated from reading UI file 'regi.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGI_H
#define UI_REGI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_regi
{
public:

    void setupUi(QDialog *regi)
    {
        if (regi->objectName().isEmpty())
            regi->setObjectName(QString::fromUtf8("regi"));
        regi->resize(400, 300);

        retranslateUi(regi);

        QMetaObject::connectSlotsByName(regi);
    } // setupUi

    void retranslateUi(QDialog *regi)
    {
        regi->setWindowTitle(QCoreApplication::translate("regi", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regi: public Ui_regi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGI_H
