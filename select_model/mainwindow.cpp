#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include<QModelIndex>
#include<QItemSelection>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel * model=new QStandardItemModel(7,4,this);
    for(int row=0;row<7;row++){
        for(int col=0;col<4;col++){
            QStandardItem * item=new QStandardItem(QString("%1").arg(row*4+col));
            model->setItem(row,col,item);
        }
    }
    table_view=new QTableView;
    table_view->setModel(model);
    setCentralWidget(table_view);
    this->resize(800,800);

    QItemSelectionModel* selection_model = table_view->selectionModel();
    //定义左上角和右下角的索引
    QModelIndex left_top;
    QModelIndex right_down;
    left_top=model->index(1,1,QModelIndex());
    right_down=model->index(5,2,QModelIndex());

    QItemSelection selection(left_top,right_down);
    selection_model->select(selection,QItemSelectionModel::Select);

    QTableView* table_view2=new QTableView();
    table_view2->setWindowTitle("table_view2");
    table_view2->resize(400,300);
    table_view2->setModel(model);
    table_view2->setSelectionModel(selection_model);
    table_view2->show();

    ui->maintoolBar->addAction(tr("当前项目"),this,&MainWindow::get_current_item);
    ui->maintoolBar->addAction(tr("切换选中"),this,&MainWindow::toggle_selection);

    //选择模型的选择条目更改后触发updataselection函数
    connect(selection_model,&QItemSelectionModel::selectionChanged,this,&MainWindow::up_data_selection);

    //选择模型改变后，当前项目也会改变，会触发changecurrent函数
    connect(selection_model,&QItemSelectionModel::currentChanged,this,&MainWindow::change_current);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete table_view;//无父窗口则需释放，或设置父窗口为this；
}

void MainWindow::get_current_item()
{

    auto current_index= table_view->currentIndex().data().toString();
    qDebug()<<"now index:"<<current_index;
}

void MainWindow::toggle_selection()
{
    //根节点下第1行第1列索引
    QModelIndex top_left=table_view->model()->index(0,0,QModelIndex());
    auto max_row=table_view->model()->rowCount(QModelIndex());
    auto max_col=table_view->model()->columnCount(QModelIndex());

    //根据行号和列号获取右下角item索引
    QModelIndex down_right=table_view->model()->index(max_row-1,max_col-1,QModelIndex());

    //设置选择区域
    QItemSelection cur_selection(top_left,down_right);

    table_view->selectionModel()->select(cur_selection,QItemSelectionModel::Toggle);
}

void MainWindow::up_data_selection(QItemSelection selected, QItemSelection deselected)
{
    QModelIndex index;
    QModelIndexList list=selected.indexes();
    for(int i=0;i<list.size();i++){
        QString text=QString("(%1,%2)").arg(list[i].row()).arg(list[i].column());
        table_view->model()->setData(list[i],text);
    }
    list=deselected.indexes();
    foreach (index, list) {
        table_view->model()->setData(index,"");
    }
}

void MainWindow::change_current(QModelIndex current, QModelIndex previous)
{
    qDebug()<<tr("move(%1,%2)to(%3,%4)").arg(previous.row()).arg(previous.column())
                .arg(current.row()).arg(current.column());
}
