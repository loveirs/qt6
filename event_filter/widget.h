#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"my_edit.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class widget;
}
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();
    void keyPressEvent(QKeyEvent *) ;//按键事件
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::widget *ui;
    my_edit * line_edit;
};
#endif // WIDGET_H
