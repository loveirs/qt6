/********************************************************************************
** Form generated from reading UI file 'main_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_DIALOG_H
#define UI_MAIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_dialog
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *enter_child;
    QPushButton *exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *main_dialog)
    {
        if (main_dialog->objectName().isEmpty())
            main_dialog->setObjectName(QString::fromUtf8("main_dialog"));
        main_dialog->resize(800, 600);
        centralwidget = new QWidget(main_dialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 120, 81, 31));
        enter_child = new QPushButton(centralwidget);
        enter_child->setObjectName(QString::fromUtf8("enter_child"));
        enter_child->setGeometry(QRect(180, 290, 80, 23));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(440, 290, 80, 23));
        main_dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(main_dialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        main_dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(main_dialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        main_dialog->setStatusBar(statusbar);

        retranslateUi(main_dialog);
        QObject::connect(exit, &QPushButton::clicked, main_dialog, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(main_dialog);
    } // setupUi

    void retranslateUi(QMainWindow *main_dialog)
    {
        main_dialog->setWindowTitle(QCoreApplication::translate("main_dialog", "main_dialog", nullptr));
        label->setText(QCoreApplication::translate("main_dialog", "\344\270\273\347\225\214\351\235\242", nullptr));
        enter_child->setText(QCoreApplication::translate("main_dialog", "\350\277\233\345\205\245\345\255\220\347\225\214\351\235\242", nullptr));
        exit->setText(QCoreApplication::translate("main_dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_dialog: public Ui_main_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_DIALOG_H
