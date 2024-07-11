#include "myaction.h"
#include<QSplitter>
#include<QLabel>
#include<QLineEdit>

myaction::myaction(QObject *parent):QWidgetAction(parent)
{
    //创建行编辑器
    line_edit=new QLineEdit();
    //链接信号和槽，出发回车信号和发送文本的槽函数关联

    connect(line_edit,&QLineEdit::returnPressed,this,&myaction::sendtext);

}

QWidget *myaction::createWidget(QWidget *parent)
{
    //parent不继承QMenu 且不继承QToolBar
    if(!(parent->inherits("QMenu"))&&!(parent->inherits("QToolBar"))){

        return nullptr;
    }

    QSplitter* spliter=new QSplitter(parent);
    QLabel *label=new QLabel;


    label->setText(tr("插入文本"));
    spliter->addWidget(label);
    spliter->addWidget(line_edit);
    return spliter;
}

void myaction::sendtext()
{
    emit getText(line_edit->text());
    line_edit->clear();
}
