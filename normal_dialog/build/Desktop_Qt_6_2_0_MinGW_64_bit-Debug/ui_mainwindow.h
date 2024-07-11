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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *color;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        color = new QPushButton(centralwidget);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(40, 30, 80, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 30, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 30, 121, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 90, 121, 23));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 90, 80, 23));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 90, 80, 23));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 200, 80, 23));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 300, 81, 23));
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
        color->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\225\264\345\275\242\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\265\256\347\202\271\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\235\241\347\233\256\350\276\223\345\205\245\346\241\206", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
