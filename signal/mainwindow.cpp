#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->showchildButton,SIGNAL(clicked(bool)),this,SLOT(show_child_diaglog()));
    connect(ui->showchildButton,&QPushButton::clicked,this,&MainWindow::show_child_diaglog);


    child_dialog = new childdialog(this);
    // connect(child_dialog,&childdialog::show_main_sig,this,&MainWindow::show_main_window);
    connect(child_dialog,&childdialog::show_main_sig,this,[this](){
        this->child_dialog->hide();
        this->show();
    });
}


MainWindow::~MainWindow()
{
    delete ui;
    if(child_dialog){
        delete child_dialog;
        child_dialog=nullptr;
    }
}

void MainWindow::show_child_diaglog()
{
    // auto child_diaglog=new QDialog(this);

    // child_diaglog->show();
    child_dialog->show();
    this->hide();
}

void MainWindow::show_main_window()
{
    this->show();
    child_dialog->hide();
}
