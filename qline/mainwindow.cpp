#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ip="000.000.000.000;";
    ui->ip_edit->setInputMask(ip);
    QString mac="HH:HH:HH:HH:HH:HH;_";
    ui->mac_edit->setInputMask(mac);
    ui->pwd_edit->setEchoMode(QLineEdit::Password);
    QRegularExpression regx("[a-zA-Z0-9_-]+@[A-Za-z0-9]+\.[a-zA-Z0-9]+");
    QValidator * validdator=new QRegularExpressionValidator(regx,ui->email_edit);
    ui->email_edit->setValidator(validdator);

}

MainWindow::~MainWindow()
{
    delete ui;
}
