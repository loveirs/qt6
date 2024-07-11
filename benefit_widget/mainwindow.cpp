#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QListWidget>
#include<QListWidgetItem>
#include<QPixmap>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QAbstractItemView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *list_widget = new QListWidget(this);
    auto *list_widget_item=new QListWidgetItem;
    list_widget_item->setText("list item");
    QPixmap pixmap(50,50);
    pixmap.fill(Qt::blue);
    list_widget_item->setIcon(pixmap);
    list_widget_item->setToolTip("this is list item");
    list_widget->insertItem(0,list_widget_item);

    auto *list_widget_item2=new QListWidgetItem;
    list_widget_item2->setText("list item2");
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::red);
    list_widget_item2->setIcon(pixmap2);
    list_widget_item2->setToolTip("this is list item2");
    list_widget->insertItem(1,list_widget_item2);

    list_widget->setSortingEnabled(true);
    list_widget->sortItems(Qt::AscendingOrder);

    list_widget->show();
    this->setCentralWidget(list_widget);

    //设置可拖动
    list_widget->setSelectionMode(QAbstractItemView::SingleSelection);
    list_widget->setDragEnabled(true);
    list_widget->viewport()->setAcceptDrops(true);
    list_widget->setDropIndicatorShown(true);
    list_widget->setDragDropMode(QAbstractItemView::InternalMove);
    //

    tree_widget=new QTreeWidget();
    tree_widget->setColumnCount(2);
    QStringList headers;
    headers<<"name"<<"year";
    tree_widget->setHeaderLabels(headers);

    auto * grade1 = new QTreeWidgetItem(tree_widget);
    grade1->setText(0,"Grade1");

    QTreeWidgetItem * student = new QTreeWidgetItem(grade1);
    student->setText(0,"tom");
    student->setText(1,"1996");

    QTreeWidgetItem * student3 = new QTreeWidgetItem(grade1,student);
    student3->setText(0,"aim");
    student3->setText(1,"1995");

    auto *grade2 = new QTreeWidgetItem(tree_widget,grade1);
    grade2->setText(0,"Grade2");
    QTreeWidgetItem * student2=new QTreeWidgetItem(grade2);
    student2->setText(0,"jack");
    student2->setText(1,"1999");

    auto *grade3 = new QTreeWidgetItem(tree_widget,grade2);
    grade3->setText(0,"Grade3");
    QTreeWidgetItem * student4=new QTreeWidgetItem(grade3);
    student4->setText(0,"mark");
    student4->setText(1,"1998");

    //删除子节点
    auto * parent_student3 = student3->parent();
    auto student3_index= parent_student3->indexOfChild(student3);
    delete parent_student3->takeChild(student3_index);

    //删除父节点
    auto * parent_garde2=grade2->parent();
    assert(parent_garde2==nullptr);
    auto grade2_index = tree_widget->indexOfTopLevelItem(grade2);
    delete tree_widget->takeTopLevelItem(grade2_index);

    tree_widget->show();

    table_widget=new QTableWidget(3,2);
    QTableWidgetItem * table_widget_item=new QTableWidgetItem("qt");
    table_widget->setItem(0,0,table_widget_item);
    QTableWidgetItem *headerv=new QTableWidgetItem("first");
    QTableWidgetItem *headerh=new QTableWidgetItem("ID");
    table_widget->setVerticalHeaderItem(0,headerv);
    table_widget->setHorizontalHeaderItem(0,headerh);
    table_widget->show();



}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree_widget;
    delete table_widget;
}
