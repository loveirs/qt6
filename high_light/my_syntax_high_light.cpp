#include "my_syntax_high_light.h"
#include<QTextCharFormat>
#include<QFont>
#include<QString>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
my_syntax_high_light::my_syntax_high_light(QObject *parent):QSyntaxHighlighter(parent)
{

}

my_syntax_high_light::~my_syntax_high_light()
{

}

void my_syntax_high_light::highlightBlock(const QString &text)
{
    QTextCharFormat my_format;
    my_format.setFont(QFont("微软雅黑"));
    my_format.setFontWeight(QFont::Bold);
    my_format.setForeground(Qt::green);

    //匹配char
    QString pattern = "\\bchar\\b"; // \b匹配一个开头或结尾是char的单词，合在一起为匹配char
    //创建正则表达式
    QRegularExpression express(pattern);
    QRegularExpressionMatch match;
    int index=0;
    match=express.match(text,index);   //qt6 高亮匹配写法 qt5为QRegExp
    while(index<text.size()){
        if(match.hasMatch()){
            int star=match.capturedStart();
            index=match.capturedEnd();
            setFormat(star,index-star,my_format);
            match=express.match(text,index);
        }
        else break;
    }
}

