#include "regi.h"
#include "ui_regi.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"login.h"
regi::regi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regi)
{
    ui->setupUi(this);
    this->setMinimumSize(QSize(400,500));
    this->setMaximumSize(QSize(400,500));
    auto box_layout=new QVBoxLayout();
    auto vertical_spacer1=new QSpacerItem(100,50,QSizePolicy::Expanding,QSizePolicy::Expanding);
    auto vertical_spacer2=new QSpacerItem(20,30,QSizePolicy::Expanding,QSizePolicy::Expanding);
    auto vertical_spacer3=new QSpacerItem(100,200,QSizePolicy::Expanding,QSizePolicy::Expanding);

    box_layout->addItem(vertical_spacer3);
    QLabel* name_label=new QLabel();
    name_label->setText(tr("邮箱"));
    QLineEdit *name_edit=new QLineEdit();
    auto name_layout=new QHBoxLayout();
    name_layout->addItem(vertical_spacer1);
    // name_layout->addItem(vertical_spacer2);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    name_layout->addItem(vertical_spacer1);
    box_layout->addLayout(name_layout);
    // this->setLayout(box_layout);

    box_layout->addSpacerItem(vertical_spacer2);
    QLabel *name_label2=new QLabel();
    name_label2->setText(tr("密码"));
    QLineEdit *name_edit2=new QLineEdit();
    auto name_layout2=new QHBoxLayout();
    name_layout2->addItem(vertical_spacer1);
    name_layout2->addWidget(name_label2);
    name_layout2->addWidget(name_edit2);
    name_layout2->addItem(vertical_spacer1);
    box_layout->addLayout(name_layout2);
    this->setLayout(box_layout);
    box_layout->addSpacerItem(vertical_spacer1);

    auto name_layout3=new QHBoxLayout();
    auto reg_button1=new QPushButton();
    reg_button1->setText(tr("登录"));

    auto reg_button2=new QPushButton();
    reg_button2->setText(tr("注册"));
    name_layout3->addItem(vertical_spacer1);
    name_layout3->addWidget(reg_button1);
    name_layout3->addItem(vertical_spacer2);
    name_layout3->addWidget(reg_button2);
    name_layout3->addItem(vertical_spacer1);
    box_layout->addLayout(name_layout3);
    box_layout->addSpacerItem(vertical_spacer3);

    connect(reg_button2,&QPushButton::clicked,this,&regi::slot_regi);

}

regi::~regi()
{
    delete ui;
}

void regi::set_login(const std::weak_ptr<login> &login)
{
    _login=login;
}

void regi::slot_regi()
{
    this->close();
    auto share_login=_login.lock(); //weak_ptr转换成share
    share_login->show();
}
