/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_register
{
public:

    void setupUi(QDialog *register)
    {
        if (register->objectName().isEmpty())
            register->setObjectName(QString::fromUtf8("register"));
        register->resize(400, 300);

        retranslateUi(register);

        QMetaObject::connectSlotsByName(register);
    } // setupUi

    void retranslateUi(QDialog *register)
    {
        register->setWindowTitle(QCoreApplication::translate("register", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register: public Ui_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
