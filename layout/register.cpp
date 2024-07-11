#include "register.h"
#include "ui_register.h"
#include<QVBoxLayout>
register ::register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::register)
{
    ui->setupUi(this);
    this.QLayout::SetMaximumSize(QSize(400,500));
    this.QLayout::SetMinimumSize(QSize(400,500));
    auto vbox_layout=new QVBoxLayout();
    auto Vertical_spacer1=new QSpacerItem(40,20,QSizePolicy::Minimum,QSizePolicy::Expanding);
    QVBoxLayout.addItem(Vertical_spacer1);
}

register ::~register()
{
    delete ui;
}
