#include "childdialog.h"
#include "ui_childdialog.h"

childdialog::childdialog(QWidget *parent)
    : QDialog(parent),_parent(parent)
    , ui(new Ui::childdialog)
{
    ui->setupUi(this);
    connect(ui->show_main_window,&QPushButton::clicked,this,&childdialog::show_main_window);
}

childdialog::~childdialog()
{
    delete ui;
}

void childdialog::show_main_window()
{
    this->hide();
    // _parent->show();
    emit show_main_sig();
}
