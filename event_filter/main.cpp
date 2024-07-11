#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])//事件系统
{
    QApplication a(argc, argv);
    widget w;
    w.show();
    return a.exec();
}
