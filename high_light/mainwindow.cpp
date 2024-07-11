#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"my_syntax_high_light.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto my_high_light=new my_syntax_high_light(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
