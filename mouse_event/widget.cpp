#include "widget.h"
#include "ui_widget.h"
#include<QCursor>
#include<QMouseEvent>
#include<QApplication>
#include<QPixmap>
widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);

}

widget::~widget()
{
    delete ui;
}

void widget::mousePressEvent(QMouseEvent *event)
{
    //鼠标左键按下
    if(event->button()==Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }else if(event->button()==Qt::RightButton){
        QCursor cursor(QPixmap(":/../main_window/res/d94b228dc7b3e9b053cccfe399d49501.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void widget::mouseReleaseEvent(QMouseEvent *event)
{
    //
    QApplication::restoreOverrideCursor();
}

void widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(windowState()==Qt::WindowFullScreen){
            setWindowState(Qt::WindowNoState);
        }else{
            setWindowState(Qt::WindowFullScreen);
        }
    }
}

void widget::mouseMoveEvent(QMouseEvent *event)
{
    //窗口随鼠标移动
    if(event->buttons()&Qt::LeftButton){
        QPoint windows=event->globalPos()-offset;
        this->move(windows);
    }
}

void widget::wheelEvent(QWheelEvent *event)
{
    auto angle=event->angleDelta()/8;
    int num_degrees=angle.y();
    if(num_degrees>0){
        ui->textEdit->zoomIn();
    }else{
        ui->textEdit->zoomOut();
    }
}
