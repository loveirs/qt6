#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<QDebug>
#include<QDir>
#include<QFileDialog>
#include<QInputDialog>
#include<QMessageBox>

// #include<QProgressDialog>
// #include<QTimer>
#include<QWizard>
#include<QVBoxLayout>
#include<QLabel>
#include<QButtonGroup>
#include<QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    count=0;
}

//常用对话框
void MainWindow::on_color_clicked()
{
    QColorDialog color_dialog(Qt::blue,this);
    color_dialog.setOption(QColorDialog::ShowAlphaChannel);
    color_dialog.exec();
    QColor color=color_dialog.currentColor();
    qDebug()<<" "<<color<<Qt::endl;
}


void MainWindow::on_pushButton_clicked()
{
    QString path=QDir::currentPath();
    QString title=tr("文件对话框");
    QString filter=tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)");
    QString afilename=QFileDialog::getOpenFileName(this,title,path,filter);
    qDebug()<<afilename<<Qt::endl;

}


void MainWindow::on_pushButton_2_clicked()
{
    bool ok=false;
    auto intdata = QInputDialog::getInt(this,tr("数字输入对话框"),tr("请输入提示"),200,-200,400,10,&ok);
    if(ok){
        qDebug()<<intdata<<Qt::endl;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok=false;
    auto floatdata = QInputDialog::getDouble(this,tr("数字输入对话框"),tr("请输入浮点数"),0.1,-2,4,1,&ok,Qt::WindowFlags(),0.2);
    if(ok){
        qDebug()<<floatdata<<Qt::endl;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QStringList items;
    items<<tr("条目1")<<tr("条目2");
    bool ok=false;
    auto item=QInputDialog::getItem(this,tr("条目对话框"),tr("输入或选择条目"),items,0,true,&ok);
    if(ok){
        qDebug()<<item<<Qt::endl;
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    auto ret = QMessageBox::question(this,tr("提示对话框"),tr("你是单身吗?"));
    if(ret==QMessageBox::Yes){
        qDebug()<<ret<<Qt::endl;
        qDebug()<<"你好，单身汪。"<<Qt::endl;

    }else return ;
    auto ret2 = QMessageBox::information(this,tr("通知对话框"),tr("你好，单身汪"),tr("是的，我是单身汪"));
    if(ret==QMessageBox::Yes){
        qDebug()<<ret2<<Qt::endl;
    }else return ;
    auto ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("找个地 方发泄一下吧0.0"),QMessageBox::Ok);
    if(ret3==QMessageBox::Ok){
        qDebug()<<ret3<<Qt::endl;
    }else return ;
    auto ret4 = QMessageBox::critical(this,tr("关键提示对话框"),tr("别动手！"),QMessageBox::Yes,QMessageBox::No);
    if(ret4==QMessageBox::Yes){
        qDebug()<<ret4<<Qt::endl;
    }else return ;
}

//进度对话框
void MainWindow::on_pushButton_6_clicked()
{
    _progress_dialog = new QProgressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    _progress_dialog->setWindowTitle(tr("文件复制进度对话框"));
    _progress_dialog->setWindowModality(Qt::ApplicationModal);
    _timer = new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&MainWindow::on_updata_dialog);
    connect(_progress_dialog,&QProgressDialog::canceled,this,&MainWindow::on_cancel_dialog);
    _timer->start(10);
}

void MainWindow::on_updata_dialog(){
    count++;

    if(count>5000){
        _timer->stop();
        delete _timer;
        _timer=nullptr;
        delete _progress_dialog;
        count=0;
        return ;
    }
    _progress_dialog->setValue(count);
}

void MainWindow::on_cancel_dialog(){
    _timer->stop();
    delete _timer;
    _timer=nullptr;
    delete _progress_dialog;
    _progress_dialog=nullptr;
    count=0;
    return ;
}

//向导对话框
void MainWindow::on_pushButton_7_clicked()
{
    //页面1
    QWizard wizard(this);
    wizard.setWindowTitle(tr("全城热恋"));

    auto page1=new QWizardPage();
    page1->setTitle(tr("婚恋介绍"));
    auto label1=new QLabel();
    label1->setText(tr("帮您找对象"));
    auto layout=new QVBoxLayout();
    layout->addWidget(label1);
    page1->setLayout(layout);
    wizard.addPage(page1);

    //页面2
    auto page2=new QWizardPage();
    page2->setTitle(tr("选择心动类型"));
    auto group=new QButtonGroup(page2);
    auto but1=new QRadioButton();
    but1->setText(tr("白富美"));
    group->addButton(but1);

    auto but2=new QRadioButton();
    but2->setText(tr("萝莉"));
    group->addButton(but2);

    auto but3=new QRadioButton();
    but3->setText(tr("御姐"));
    group->addButton(but3);

    auto but4=new QRadioButton();
    but4->setText(tr("甜妹"));
    group->addButton(but4);

    auto but5=new QRadioButton();
    but5->setText(tr("暴龙"));
    group->addButton(but5);

    auto but6=new QRadioButton();
    but6->setText(tr("全都要！"));
    group->addButton(but6);

    auto layout2=new QVBoxLayout();
    for(auto type:group->buttons()){
        layout2->addWidget(type);
    }

    page2->setLayout(layout2);
    wizard.addPage(page2);

    //页面3
    QWizardPage* page3=new QWizardPage();
    page3->setTitle(tr("你的缘分即将到来！"));

    auto label3=new QLabel();
    label3->setText(tr("感谢您的参与，接下来一个月您会遇到对的人！"));
    QVBoxLayout * layout3=new QVBoxLayout();
    layout3->addWidget(label3);
    page3->setLayout(layout3);
    wizard.addPage(page3);

    //展示
    wizard.show();
    wizard.exec();
}

