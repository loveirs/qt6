#include "mainwindow.h"

#include <QApplication>
#include<QStandardItemModel>
#include<QPixmap>
#include<QTreeView>

#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QStandardItemModel model;
    auto * parent_item =model.invisibleRootItem();
    QStandardItem * item0=new QStandardItem();
    item0->setText("item0");
    QPixmap pixmap0(50,50);
    pixmap0.fill(Qt::red);
    item0->setIcon(pixmap0);
    item0->setToolTip("indexA");
    parent_item->appendRow(item0);

    parent_item=item0;//赋值，item0作为根节点

    QStandardItem * item1=new QStandardItem();
    item1->setText("item1");
    QPixmap pixmap1(50,50);
    pixmap1.fill(Qt::blue);
    item1->setIcon(pixmap1);
    item1->setToolTip("indexB");
    parent_item->appendRow(item1);

    // QStandardItem * item2=new QStandardItem();
    // item2->setText("item2");
    // QPixmap pixmap2(50,50);
    // pixmap2.fill(Qt::yellow);
    // item2->setIcon(pixmap2);
    // item2->setToolTip("indexC");
    // parent_item->appendRow(item2);

    QStandardItem * item2=new QStandardItem();
    item2->setData("item2",Qt::EditRole);
    item2->setData("indexC",Qt::ToolTipRole);
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::green);
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);
    parent_item->appendRow(item2);

    //取出根节点下第0行0列的item模型索引
    QModelIndex indexA = model.index(0,0,QModelIndex());
    qDebug()<<model.rowCount(indexA);

    //获取indexA下的0行0列
    QModelIndex indexB=model.index(0,0,indexA);
    qDebug() << model.data(indexB,Qt::EditRole).toString();//text
    qDebug() << model.data(indexB,Qt::DecorationRole);//取icon
    qDebug() << model.data(indexB,Qt::ToolTipRole).toString();//tool tip


    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}
