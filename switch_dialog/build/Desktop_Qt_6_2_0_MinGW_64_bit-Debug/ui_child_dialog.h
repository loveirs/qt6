/********************************************************************************
** Form generated from reading UI file 'child_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD_DIALOG_H
#define UI_CHILD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_child_dialog
{
public:
    QLabel *label;
    QPushButton *enter_nain_window;
    QPushButton *exit;

    void setupUi(QDialog *child_dialog)
    {
        if (child_dialog->objectName().isEmpty())
            child_dialog->setObjectName(QString::fromUtf8("child_dialog"));
        child_dialog->resize(400, 300);
        label = new QLabel(child_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 60, 81, 41));
        enter_nain_window = new QPushButton(child_dialog);
        enter_nain_window->setObjectName(QString::fromUtf8("enter_nain_window"));
        enter_nain_window->setGeometry(QRect(60, 160, 80, 23));
        exit = new QPushButton(child_dialog);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(200, 160, 80, 23));

        retranslateUi(child_dialog);
        QObject::connect(exit, &QPushButton::clicked, child_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(child_dialog);
    } // setupUi

    void retranslateUi(QDialog *child_dialog)
    {
        child_dialog->setWindowTitle(QCoreApplication::translate("child_dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("child_dialog", "\345\255\220\347\252\227\345\217\243", nullptr));
        enter_nain_window->setText(QCoreApplication::translate("child_dialog", "\350\277\233\345\205\245\344\270\273\347\225\214\351\235\242", nullptr));
        exit->setText(QCoreApplication::translate("child_dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class child_dialog: public Ui_child_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD_DIALOG_H
