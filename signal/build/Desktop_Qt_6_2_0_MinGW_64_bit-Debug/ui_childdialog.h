/********************************************************************************
** Form generated from reading UI file 'childdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDDIALOG_H
#define UI_CHILDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_childdialog
{
public:
    QLabel *label;
    QPushButton *show_main_window;

    void setupUi(QDialog *childdialog)
    {
        if (childdialog->objectName().isEmpty())
            childdialog->setObjectName(QString::fromUtf8("childdialog"));
        childdialog->resize(400, 300);
        label = new QLabel(childdialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 100, 53, 15));
        show_main_window = new QPushButton(childdialog);
        show_main_window->setObjectName(QString::fromUtf8("show_main_window"));
        show_main_window->setGeometry(QRect(130, 160, 80, 23));

        retranslateUi(childdialog);

        QMetaObject::connectSlotsByName(childdialog);
    } // setupUi

    void retranslateUi(QDialog *childdialog)
    {
        childdialog->setWindowTitle(QCoreApplication::translate("childdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("childdialog", "\345\255\220\347\225\214\351\235\242", nullptr));
        show_main_window->setText(QCoreApplication::translate("childdialog", "\346\230\276\347\244\272\344\270\273\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class childdialog: public Ui_childdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDDIALOG_H
