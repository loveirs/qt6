#ifndef MY_SYNTAX_HIGH_LIGHT_H
#define MY_SYNTAX_HIGH_LIGHT_H
#include<QSyntaxHighlighter>
#include<QTextDocument>
#include<QObject>
class my_syntax_high_light:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    my_syntax_high_light(QObject * parent=0);
    ~my_syntax_high_light();
    //重新实现高亮
protected:
    virtual void highlightBlock(const QString &text);
};

#endif // MY_SYNTAX_HIGH_LIGHT_H
