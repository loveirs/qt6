#ifndef MY_EDIT_H
#define MY_EDIT_H
#include<QLineEdit>
#include<QWidget>


class my_edit:public QLineEdit
{
    Q_OBJECT
public:
    explicit my_edit(QWidget* parent =nullptr); //显式调用

protected:
    void keyPressEvent(QKeyEvent *) ;//按键事件
    bool event(QEvent* pevent);
};

#endif // MY_EDIT_H
