/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *pwd_label;
    QLabel *email_label;
    QLabel *ip_label;
    QLineEdit *email_edit;
    QLineEdit *ip_edit;
    QLineEdit *pwd_edit;
    QLabel *mac_label;
    QLineEdit *mac_edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 40, 571, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 0);
        pwd_label = new QLabel(gridLayoutWidget);
        pwd_label->setObjectName(QString::fromUtf8("pwd_label"));

        gridLayout->addWidget(pwd_label, 1, 0, 1, 1);

        email_label = new QLabel(gridLayoutWidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout->addWidget(email_label, 0, 0, 1, 1);

        ip_label = new QLabel(gridLayoutWidget);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));

        gridLayout->addWidget(ip_label, 2, 0, 1, 1);

        email_edit = new QLineEdit(gridLayoutWidget);
        email_edit->setObjectName(QString::fromUtf8("email_edit"));

        gridLayout->addWidget(email_edit, 0, 1, 1, 1);

        ip_edit = new QLineEdit(gridLayoutWidget);
        ip_edit->setObjectName(QString::fromUtf8("ip_edit"));

        gridLayout->addWidget(ip_edit, 2, 1, 1, 1);

        pwd_edit = new QLineEdit(gridLayoutWidget);
        pwd_edit->setObjectName(QString::fromUtf8("pwd_edit"));

        gridLayout->addWidget(pwd_edit, 1, 1, 1, 1);

        mac_label = new QLabel(gridLayoutWidget);
        mac_label->setObjectName(QString::fromUtf8("mac_label"));

        gridLayout->addWidget(mac_label, 3, 0, 1, 1);

        mac_edit = new QLineEdit(gridLayoutWidget);
        mac_edit->setObjectName(QString::fromUtf8("mac_edit"));

        gridLayout->addWidget(mac_edit, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pwd_label->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        email_label->setText(QCoreApplication::translate("MainWindow", "\351\202\256\347\256\261", nullptr));
        ip_label->setText(QCoreApplication::translate("MainWindow", "ip\345\234\260\345\235\200", nullptr));
        email_edit->setText(QString());
        mac_label->setText(QCoreApplication::translate("MainWindow", "MAC\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
