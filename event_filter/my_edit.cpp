#include "my_edit.h"
#include<QDebug>
#include<QKeyEvent>

my_edit::my_edit(QWidget *parent):QLineEdit(parent)
{

}

void my_edit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"my edit event"<<Qt::endl;
    QLineEdit::keyPressEvent(event);
    event->ignore();

}

bool my_edit::event(QEvent *pevent)
{
    if(pevent->type()==QEvent::KeyPress){
        qDebug()<<tr("my edit event111")<<Qt::endl;
        // return false;
        // return true; // 返回true不会触发widget事件 // 此处返回会拦截事件；
    }

    return QLineEdit::event(pevent);
}
