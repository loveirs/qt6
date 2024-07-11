#include "main_dialog.h"
#include "ui_main_dialog.h"
#include"child_dialog.h"
main_dialog::main_dialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_dialog)
{
    ui->setupUi(this);
}

main_dialog::~main_dialog()
{
    delete ui;
}

void main_dialog::on_enter_child_clicked()
{
    close();
    child_dialog child;
    if(child.exec()==QDialog::Accepted){
        this->show();

    }else{
        return ;
    }

}

