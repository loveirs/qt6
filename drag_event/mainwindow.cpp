#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMimeData>
#include<QDebug>
#include<QUrl>
#include<QList>
#include<QString>
#include<QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        qDebug()<<event->mimeData()->urls()[0]<<Qt::endl;//取url
        event->acceptProposedAction();//让事件可以被接收
    }else{
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData* mimedata=event->mimeData();
    //判断是否包含url
    if(mimedata->hasUrls()){
        QList<QUrl> url_list=mimedata->urls();
        //将第一个匹配的文件路径获取

        QString file_name=url_list[0].toLocalFile();
        if(!file_name.isEmpty()){

            QFile file(file_name);
            if(!file.open(QIODevice::ReadOnly)){
                return ;
            }

            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }else{
        event->ignore();
    }
}
