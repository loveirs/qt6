#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QDebug>
#include<QString>
widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);
    // id1=startTimer(10000);
    // id2=startTimer(15000);
    // id3=startTimer(20000);

    QTimer *timer =new QTimer(this);
    connect(timer,&QTimer::timeout,this,&widget::slot_updata_led);
    timer->start(1000);

}

widget::~widget()
{
    delete ui;
    // killTimer(id1);
    // killTimer(id2);
    // killTimer(id3);
}

void widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier){
        if(event->key()==Qt::Key_M&&windowState()!=Qt::WindowFullScreen){
            setWindowState(Qt::WindowFullScreen);
            return;
        }
        return ;
    }
    if(event->key()==Qt::Key_Escape&&windowState()==Qt::WindowFullScreen){
        setWindowState(Qt::WindowNoState);
        return;
    }

    bool up_flag=false;
    bool down_flag=false;
    bool left_flag=false;
    bool right_flag=false;

    if(event->key()==Qt::Key_Up){
        if(event->isAutoRepeat()){
            auto curpos=ui->pushButton->pos();
            curpos.setY(curpos.y()-5);
            ui->pushButton->move(curpos);
            return ;
        }else{
            up_flag=true;
        }
    }

    if(event->key()==Qt::Key_Down){
        if(event->isAutoRepeat()){
            auto curpos=ui->pushButton->pos();
            curpos.setY(curpos.y()+5);
            ui->pushButton->move(curpos);
            return ;
        }else{
            down_flag=true;
        }
    }

    if(event->key()==Qt::Key_Left){
        if(event->isAutoRepeat()){
            auto curpos=ui->pushButton->pos();
            curpos.setX(curpos.x()-5);
            ui->pushButton->move(curpos);
            return ;
        }else{
            left_flag=true;
        }
    }

    if(event->key()==Qt::Key_Right){
        if(event->isAutoRepeat()){
            auto curpos=ui->pushButton->pos();
            curpos.setX(curpos.x()+5);
            ui->pushButton->move(curpos);
            return ;
        }else{
            right_flag=true;
        }
    }

    auto curpos=ui->pushButton->pos();
    if(up_flag){
        curpos.setY(curpos.y()-5);
    }

    if(down_flag){
        curpos.setY(curpos.y()+5);
    }

    if(left_flag){
        curpos.setX(curpos.x()-5);
    }

    if(right_flag){
        curpos.setX(curpos.x()+5);
    }
    ui->pushButton->move(curpos);

}

void widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1){
        qDebug()<<"id1";
    }
    if(event->timerId()==id2){
        qDebug()<<"id2";
    }
    if(event->timerId()==id3){
        qDebug()<<"id3";
    }
}

void widget::slot_updata_led()
{
    QTime time = QTime::currentTime();
    QString text= time.toString("hh:mm:ss");
    // qDebug()<<text;
    if(time.second()%2==0){
        text[5]=' ';//冒号呈现闪烁效果。
    }
    ui->lcdNumber->setDigitCount(text.length());//设置长度，显示小时
    ui->lcdNumber->display(text);
}
