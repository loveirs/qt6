#include "login.h"
#include "regi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<login> w=std::make_shared<login>(); //初始化智能指针
    // login w;
    w->init_signal();
    w->show();


    return a.exec();
}
