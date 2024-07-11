#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qstandarditemmodel>
#include<QTableView>
#include"spinboxdele.h"

MainWindow::MainWindow(QWidget *parent)
     : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *model =new QStandardItemModel(7,4,this);
    for(int row=0;row<7;row++){
        for(int col=0;col<4;col++){
            QStandardItem* item = new QStandardItem(QString("%1").arg(row*4+col));
            model->setItem(row,col,item);
        }
    }
    QTableView* _table_view = new QTableView;
    _table_view->setModel(model);
    setCentralWidget(_table_view);
    this->resize(800,800);

    auto *model2 =new QStandardItemModel(7,4,this);
    for(int row=0;row<7;row++){
        for(int col=0;col<4;col++){
            QStandardItem* item = new QStandardItem(QString("%1").arg(row*4+col));
            model2->setItem(row,col,item);
        }
    }

    auto * delegate=new spinboxdele(this);

    QTableView* _table_view2 = new QTableView();
    _table_view2->setModel(model2);
    _table_view2->setItemDelegate(delegate);
    _table_view2->show();
    _table_view2->resize(800,800);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete _table_view2;
}
