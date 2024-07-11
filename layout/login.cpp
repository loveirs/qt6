#include "login.h"
#include "ui_login.h"
#include "regi.h"
login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    this->close();
    _regi->show();
}

void login::init_signal(){
    _regi=std::make_shared<regi>();
    _regi->set_login(shared_from_this());//共享引用计数
}
