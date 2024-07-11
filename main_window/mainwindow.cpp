#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QTextEdit>
#include<QMdiSubWindow>
#include<QMenu>
#include<QIcon>
#include<QKeySequence>
#include<QActionGroup>
#include"myaction.h"
#include<QToolButton>
#include<QSpinBox>
#include<QLabel>
#include<QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *edit_menu=ui->menubar->addMenu(tr("编辑"));
    edit_menu->addSeparator();
    QAction *action_open=edit_menu->addAction(QIcon(":/res/*.png"),tr("打开文件(&O)"));
    // action_open->setShortcut(QKeySequence("Ctrl+O"));
    connect(action_open,&QAction::triggered,this,&MainWindow::on_actionedit_trigger);

    QActionGroup * group=new QActionGroup(this);
    QAction *action_l=group->addAction(tr("左对齐(&L)"));
    action_l->setCheckable(true);
    edit_menu->addSeparator();
    edit_menu->addAction(action_l);
    myaction* action=new myaction(this);

    edit_menu->addAction(action);
    connect(action,&myaction::getText,this,&MainWindow::slot_set_text);



    QToolButton * toolbut=new QToolButton(this);
    toolbut->setText(tr("颜色"));
    ui->toolBar->addWidget(toolbut);
    QMenu *colormenu=new QMenu(this);
    colormenu->addAction(tr("红色"));
    toolbut->setMenu(colormenu);
    toolbut->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addSeparator();
    QSpinBox *spinbox=new QSpinBox(this);
    ui->toolBar->addWidget(spinbox);

    ui->statusbar->showMessage(tr("欢迎使用多功能编辑器"),2000);

    //永久显示状态标签
    QLabel *parmnant=new QLabel(this);
    parmnant->setFrameStyle(QFrame::Box|QFrame::Sunken);
    parmnant->setText("llfc.club");
    ui->statusbar->addPermanentWidget(parmnant);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionshowdock_D_triggered()
{
    qDebug()<<"显示"<<Qt::endl ;
    ui->dockWidget->show();
}


void MainWindow::on_actionnew_file_triggered()
{
    QTextEdit *text_edit=new QTextEdit(this);
    auto child_window=ui->mdiArea->addSubWindow(text_edit);
    child_window->setWindowTitle(tr("文本编辑子窗口"));
    child_window->show();
}

void MainWindow::on_actionedit_trigger()
{
    qDebug()<<"显示编辑"<<Qt::endl;
}

void MainWindow::slot_set_text(const QString &string)
{
    ui->textEdit->setText(string);
}

