#include "main_dialog.h"

#include <QApplication>

#include"child_dialog.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_dialog w;
    child_dialog child_dlg;
    // child_dlg.exec();
    if(child_dlg.exec()==QDialog::Accepted){
        w.show();
        a.exec();
    }
    else return 0;
    // w.show();
    // return a.exec();
}
