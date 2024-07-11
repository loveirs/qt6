#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextDocument>
#include<QTextBlockFormat>
#include<QTextFrame>
#include<QTextCursor>
#include<QAction>
#include<QDebug>
#include<QTextCharFormat>
#include<QTextTableFormat>
#include<QTextListFormat>
#include<QTextImageFormat>
#include<QPushButton>
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextDocument * doc =ui->textEdit->document();
    QTextFrame * root_frame = doc->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::blue);
    format.setBorder(3);
    root_frame->setFrameFormat(format);

    //设置文本框样式
    QTextFrameFormat frame_format;
    frame_format.setBackground(Qt::lightGray);
    frame_format.setMargin(10);
    frame_format.setPadding(5);
    frame_format.setBorder(2);
    frame_format.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    QTextCursor cursor=ui->textEdit->textCursor();
    cursor.insertFrame(frame_format);
    ui->textEdit->insertPlainText("inner text!\n");
    ui->textEdit->insertPlainText("hello world\n");

    QAction * action_frame=new QAction("frame",this);
    connect(action_frame,&QAction::triggered,this,&MainWindow::show_text_frame);
    ui->toolBar->addAction(action_frame);

    QAction * action_text_block = new QAction(tr("文本块"),this);
    connect(action_text_block,&QAction::triggered,this,&MainWindow::show_text_block);
    ui->toolBar->addAction(action_text_block);

    QAction * action_font = new QAction(tr("字体"),this);
    action_font->setCheckable(true);
    connect(action_font,&QAction::toggled,this,&MainWindow::set_text_font);
    ui->toolBar->addAction(action_font);

    QAction *action_text_table=new QAction(tr("表格"),this);
    QAction *action_text_list=new QAction(tr("列表"),this);
    QAction *action_text_image=new QAction(tr("图片"),this);
    connect(action_text_table,&QAction::triggered,this,&MainWindow::insert_table);
    ui->toolBar->addAction(action_text_table);

    connect(action_text_list,&QAction::triggered,this,&MainWindow::insert_list);
    ui->toolBar->addAction(action_text_list);

    connect(action_text_image,&QAction::triggered,this,&MainWindow::insert_image);
    ui->toolBar->addAction(action_text_image);

    QAction *action_text_find=new QAction(tr("查找"),this);
    connect(action_text_find,&QAction::triggered,this,&MainWindow::text_find);
    ui->toolBar->addAction(action_text_find);

    find_dialog=new QDialog(this);
    line_dialog=new QLineEdit(find_dialog);
    QPushButton *btn=new QPushButton(find_dialog);
    btn->setText(tr("查找下一个"));
    connect(btn,&QPushButton::clicked,this,&MainWindow::find_next);
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(line_dialog);
    layout->addWidget(btn);
    find_dialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_text_frame()
{
    auto doc=ui->textEdit->document();
    auto root_frame = doc->rootFrame();
    for(auto iter=root_frame->begin();iter!=root_frame->end();iter++){
        auto cur_frame=iter.currentFrame();
        auto cur_block=iter.currentBlock();
        if(cur_frame){
            qDebug()<<"cur frame"<<Qt::endl;
        }
        else if(cur_block.isValid()){

            qDebug()<<"cur block"<< cur_block.text() <<Qt::endl;
        }


    }
}

void MainWindow::show_text_block()
{
    QTextDocument * document=ui->textEdit->document();
    QTextBlock block =document->firstBlock();
    for(int i=0;i<document->blockCount();i++){
        qDebug()<<tr("文本块%1,文本块首行行号%2，长度%3，内容%4").arg(i).arg(block.firstLineNumber()) \
                    .arg(block.length()).arg(block.text());
        block= block.next();
    }

}

void MainWindow::set_text_font(bool checked)
{
    if(checked){
        QTextCursor cursor =ui->textEdit->textCursor();//获取光标
        QTextBlockFormat block_format;
        block_format.setAlignment(Qt::AlignCenter);//对其样式
        cursor.insertBlock(block_format);//插入文本框
        QTextCharFormat char_format;
        char_format.setBackground(Qt::lightGray);
        char_format.setForeground(Qt::blue);
        char_format.setFont(QFont(tr("宋体"),12,QFont::Bold,true));
        char_format.setFontUnderline(true);
        cursor.setCharFormat(char_format);
        cursor.insertText(tr("插入字体"));

    }else{
        QTextCursor cursor =ui->textEdit->textCursor();//获取光标
        QTextBlockFormat block_format;
        block_format.setAlignment(Qt::AlignCenter);//对其样式
        cursor.insertBlock(block_format);//插入文本框
        QTextCharFormat char_format;
        cursor.setCharFormat(char_format);
        cursor.insertText(tr("微软雅黑"));
    }
}

void MainWindow::insert_table()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellPadding(10);
    format.setCellSpacing(2);
    cursor.insertTable(2,2,format);
}

void MainWindow::insert_list()
{

    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListCircle);
    cursor.insertList(format);

}

void MainWindow::insert_image()
{
    QTextImageFormat format;
    format.setName("    :/../main_window/res/d94b228dc7b3e9b053cccfe399d49501.png");
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::text_find()
{
    find_dialog->show();

}

void MainWindow::find_next()
{
    QString string = line_dialog->text();
    bool is_find=ui->textEdit->find(string,QTextDocument::FindBackward);
    if(is_find){
        qDebug()<<"行号、列号"<<ui->textEdit->textCursor().blockNumber()<<"\n"<<ui->textEdit->textCursor().columnNumber();
    }
}
