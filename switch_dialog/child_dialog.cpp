#include "child_dialog.h"
#include "ui_child_dialog.h"
#include<QDebug>
child_dialog::child_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::child_dialog)
{
    ui->setupUi(this);
}

child_dialog::~child_dialog()
{
    delete ui;
}

void child_dialog::on_enter_nain_window_clicked()
{
    qDebug() << tr("进入主界面")<<Qt::endl;
    accept();
}

