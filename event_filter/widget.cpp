#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QWheelEvent>
// #include<QPoint>
widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);

    line_edit=new my_edit(this);

    line_edit->move(100,100);
    line_edit->installEventFilter(this);
    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);

}

widget::~widget()
{
    delete ui;
}

void widget::keyPressEvent(QKeyEvent *)
{
    qDebug()<<"widget key press event"<<Qt::endl;
}

bool widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==line_edit){
        if(event->type()==QEvent::KeyPress){
            qDebug()<<"eventfilter line edit";
            return false;//抛给父节点处理
        }
    }

    if(watched==ui->textEdit){
        if(event->type()==QEvent::Wheel){
            QWheelEvent *wheel_event=static_cast<QWheelEvent*>(event);

            //qt6滚轮事件判断（已废弃delta）
            auto angle=wheel_event->angleDelta()/8;//获取滚轮角度
            int num_degrees=angle.y();
            if(num_degrees>0){
                qDebug()<<"wheel up";
                ui->textEdit->zoomIn();
            }else{
                qDebug()<<"wheel down";
                ui->textEdit->zoomOut();
            }
            return true;

        }
        return false;
    }

    if(watched==ui->spinBox){
        if(event->type()==QEvent::KeyPress){
            QKeyEvent *key_event=static_cast<QKeyEvent*>(event);

            if(key_event->key()==Qt::Key_Space){
                ui->spinBox->setValue(0);
                return true;
            }
            return false;
        }
        return false;
    }
    return QWidget::eventFilter(watched,event);
}
