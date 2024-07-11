#include "mainwindow.h"

#include <QApplication>
#include<QStringList>
#include<QTableView>
#include<QListView>
#include<QApplication>
#include"string_list_model.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QStringList list;
    list<<"a"<<"b"<<"c";
    string_list_model model(list);

    model.insert_rows(3,2);
    model.remove_rows(1,1);

    QTableView table_view;
    table_view.setModel(&model);
    table_view.show();

    QListView list_view;
    list_view.setModel(&model);//用同一个model，同步修改
    list_view.show();
    return a.exec();
}
