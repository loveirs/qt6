#ifndef MYACTION_H
#define MYACTION_H
#include<QWidgetAction>
#include<QLineEdit>
#include<QObject>

class myaction:public QWidgetAction
{
    Q_OBJECT
signals:
    void getText(const QString&string);

public:
    myaction(QObject *parent=nullptr);
protected:
    virtual QWidget * createWidget(QWidget *parent);

private:
    QLineEdit *line_edit;
private slots:
    void sendtext();

};

#endif // MYACTION_H
